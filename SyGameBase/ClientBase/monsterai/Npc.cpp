#include "Npc.h"
#include "GameUser.h"
#include "MsgDefine/NpcSyncMsg.h"
#include "MsgDefine/MoveMsg.h"
#include "Map.h"
#include "NpcManager.h"
#include "MsgDefine/AbilityMsg.h"
#include "NpcAI.h"
#include "NpcExt.h"
bool Npc::initWithNode(script::tixmlCodeNode *node)
{
	if (!node) return false;
	node->getAttr("x",x);
	node->getAttr("y",y);	
	node->getAttr("id",npcid);
	node->getAttr("dir",dir);
	node->getAttr("hp",hp);
	return true;
}
bool Npc::moveable(const zPos &tempPos,const zPos &destPos,const int radius1)
{
	return true;
	Map * map = getMap();
	if (map)
	{
		if (map->checkBlock(destPos.x,destPos.y,BP_GROUND)) return false;
	}	
	return true;
}
/**
 *  回调 
 * */
bool Npc::moveTo(zPos &dest)
{
	ClientMsg::RetNpcMove move;
	move.tempId = this->quickID;
	move.x = dest.x;
	move.y = dest.y;
	move.dir = dir;
	if (map->updateEntry(this,dest.x,dest.y))	
        {
		sendCmdToNine(&move,sizeof(move));
		printf("%u 移动 到%u ,%u\n",getObjectId(),dest.x,dest.y);
	}
	return false;
}
bool Npc::gotoFindPath(const zPos &srcPos, const zPos &destPos)
{
	return zAStar<>::gotoFindPath(srcPos,destPos);
}
void Npc::tellAdd(localmap::Entry *entry)
{
	// TODO 将自身的信息 告知给entry
	if (!entry) return;
	if (entry->entryType == TYPE_GAME_USER)
	{
		GameUser * user = (GameUser*) entry;
		if (user)
		{
			ClientMsg::RetAddNpcInfo otherInfo;
			otherInfo.data.npcID = npcid;
			otherInfo.data.tempID = quickID;
			otherInfo.data.x = x;
			otherInfo.data.y = y; 	
			otherInfo.data.dir = dir;
			// TODO 扩展
			user->sendClientMsg(&otherInfo,sizeof(otherInfo));
			printf("tell user %u npc add <%u,%u>\n",user->id,x,y);
		}
	}
}

void Npc::tellDel(localmap::Entry *entry)
{
	// 将自身的信息 通知Entry删除

	if (!entry) return;
	if (entry->entryType == TYPE_GAME_USER)
	{
		GameUser * user = (GameUser*) entry;
		if (user)
		{
			ClientMsg::RetOtherLeave userLeave;
			userLeave.tempID = quickID;
			userLeave.objectType = ClientMsg::OBJECT_TYPE_NPC; // 通知玩家的删除
			user->sendClientMsg(&userLeave,sizeof(userLeave));
		}
	}
}

bool Npc::intoMap(Map *map)
{
	if (!map) return false;
	if (map->addObject(this))
	{
		if (theNpcManager.addNpc(this))
		return true;
	}
	return false;
}
Map * Npc::getMap()
{
	return (Map*) map;
}
bool Npc::doAttack(const NIO& nio)
{
	if (!map) return false;
	printf("%u doAttack; %u %u\n",getObjectId(),nio.objectId,nio.lastTime);
	MapObject *object = (MapObject*)getMap()->findObjectById(nio.objectId);
	if (!object)
	{
		printf("cant find attack target Npc::doAttack\n");	
	}
	if (object && object->entryType == TYPE_GAME_USER)
	{ 
		GameUser *user = (GameUser*) object;
		if (user->calcDistance(this) <= 3)
		{
			// 这里释放一个技能
			stAbilityAttackData atkData;
			atkData.attackType = ClientMsg::RetAbilityToOther::ATTACK_TYPE_NPC_TO_ROLE;
			atkData.skillID = 1;
			atkData.x = user->x;
			atkData.y = user->y;
			atkData.targetType = ClientMsg::RetAbilityToOther::TARGET_TYPE_USER;
			atkData.beAttackId = user->id;
			npcAbility.studyAbility(1); // 学习技能
			npcAbility.useAbility(1,&atkData);
			hp --; // 血量减少1
			updateHpToClients(-1); // 通知客户端血量减少
		}
		else
		{
			zPos srcPos(x,y);
			zPos destPos(user->x,user->y);
			gotoFindPath(srcPos,destPos); // 走到玩家附近
		}
		return true;
	}
	return false;
}

void Npc::sendCmdToNine(const void *msg, const UINT32 msgLen)
{
	struct SendCallBack:public localmap::ExecEveryEntry{
		const void *cmd;
		const UINT32 msgLen;
		SendCallBack(const void *cmd,const UINT32 msgLen)
			:cmd(cmd),msgLen(msgLen){}
		int exec(Entry *entry)
		{
			if (entry && entry->entryType == TYPE_GAME_USER)
			{
				GameUser *user = (GameUser*) entry;
				user->sendClientMsg(cmd,msgLen);
				printf("tell user <%u> moving\n",user->id);
			}
			return 1;
		}
	}send(msg,msgLen);
	if (map)
		map->exec(x,y,20,20,&send); // 通知视野内我的移动
}

void Npc::updateHpToClients(int changeHp)
{
	ClientMsg::RetNpcChangeHp notify;
	notify.hp = changeHp;
	notify.nowHp = hp;
	sendCmdToNine(&notify,sizeof(notify));
}


void Npc::execAIEvent(int event)
{
	NpcAIStub stub(this,NULL);
	theNpcAILib.execEvent(npcAIID,&stub,event);	
}
void Npc::execAIEvent(MapObject *object,int event)
{
	NpcAIStub  stub;
	stub.npc = this;
	stub.object = object;
	theNpcAILib.execEvent(npcAIID,&stub,event);
}
void Npc::addTarget(DWORD objectID,DWORD objectType,DWORD eventType,DWORD weight,DWORD lastTime,int id)
{
	if (targetList.size() >= 100) return;
	stNpcTarget target;
	target.objectID = objectID;
	target.objectType = objectType;
	target.eventType = eventType;
	target.weight = weight;
	target.lastTime = lastTime;
	target.createTime = sys::sTime::getNowTime();
	if (id != -1)
	{
		targetList.push_back(target);
	}
	else
	{
		if (id >=0 && id >= targetList.size()) targetList.resize(id);
		if (id >=0 && id < targetList.size())
		{
			targetList.resize(id + 1);
			targetList[id] = target;
		}
	}
}

bool Npc::checkTimeOut(DWORD timerid,DWORD lasttime)
{
	sys::stTimeValue nowTime = sys::sTime::getNowTime();
	if (timerid < ticks.size())
	{
		stNpcTimeTick& tick = ticks[timerid];
		if (tick.timerid == timerid)
		{
			if (tick.startTime + lasttime < nowTime )
			{
				tick.startTime = nowTime;
				return true;
			}
			return false;
		}
	}
	return false;
}

void Npc::addTimer(DWORD timerid,DWORD lasttime)
{
	stNpcTimeTick tick;
	tick.timerid = timerid;	
	tick.startTime = sys::sTime::getNowTime();
	tick.createTime = sys::sTime::getNowTime();
	if (timerid >= ticks.size())
	{
		ticks.resize(timerid + 1);
	}
	ticks[timerid] = tick;
}

void Npc::delTimer(DWORD timerid,DWORD lasttime)
{
	if (timerid < ticks.size())
	{
		ticks[timerid].timerid = 0;
	}
}

bool Npc::checkTimePassed(DWORD timerid,DWORD lasttime)
{
	sys::stTimeValue nowTime = sys::sTime::getNowTime();
	if (timerid < ticks.size())
	{
		stNpcTimeTick& tick = ticks[timerid];
		if (tick.timerid == timerid)
		{
			if (tick.createTime + lasttime < nowTime )
			{
				return true;
			}
			return false;
		}
	}
	return false;
}

void Npc::doTick()
{
	if (!now_nio.isOn())
	{
		anaysicsNIO(now_nio);
		doNIO(now_nio);	
		now_nio.freshTime();
	}
}

void Npc::doNIO(NIO &nio)
{
	int opType = nio.getFirstOp();
	switch(opType)
	{
		case NIO::ATTACK:
		{
			this->doAttack(nio);
		}break;
		case NIO::FLEE:
		{
			this->doFlee(nio);
		}break;
		case NIO::SLEEP:
		{
			this->doSleep(nio);
		}break;
		case NIO::TLAK:
		{
			this->doTalk(nio);
		}break;
		case NIO::WALK:
		{
			this->doWalk(nio);
		}break;
	}
}
/**
 * 执行一个行为
 * */
void Npc::anaysicsNIO(NIO &nio)
{
	theNpcExt.action(extLibId,this,nio);
	return;
}

bool Npc::doWalk(const NIO &nio)
{
	if (!map) return false;
	printf("%u doAttack; %u %u\n",getObjectId(),nio.objectId,nio.lastTime);
	MapObject *object = (MapObject*)getMap()->findObjectById(nio.objectId);
	if (!object)
	{
		printf("cant find attack target Npc::doAttack\n");	
	}
	if (object && object->entryType == TYPE_GAME_USER)
	{ 
		GameUser *user = (GameUser*) object;
		zPos destPos(user->x,user->y);
		if (user->calcDistance(this) <= 3)
		{
			DWORD range = sys::sRandom::randBetween(0,5);
			if (destPos.x > 3)
				destPos.x = destPos.x - 3 + range/2;
			range = sys::sRandom::randBetween(0,5);
			if (destPos.y > 3)
				destPos.y = destPos.y - 3 + range/2;
		}
		zPos srcPos(x,y);
		gotoFindPath(srcPos,destPos); // 走到玩家附近
		return true;
	}
	return false;

}
