#pragma once
#include "cocos2d.h"
#include "Cartoon.h"
#include "FileSet.h"
#include "LocalSprite.h"
NS_CC_BEGIN
/**
 * 技能行为 离身行为 或者本身行为
 **/
class SkillActionInfo{
public:
	SkillActionInfo *nextInfo; // 下一个动画信息
	std::string actionName; // 动作名字
	int delayTime; // 延时
	int nextType; // 下一个类型
	bool self; // 是否自身播放
	std::string endCodeName; // 结束时回调代码
	std::vector<CCSpriteFrame*> frames; // 帧集合
	CCPoint offset; // 相对移动的方向
	float rotation; // 将精灵反转的角度
	float jumpHeight;// 跳动高度
	int frameType; // 帧类型 
	enum{
		ACTION_FOLLOW, // 跟随
		ACTION_MOVE, // 移动
		ACTION_STOP, // 静止
		ACTION_JUMP, // 跳跃
	};
	int actionType; // 动作类型
	
	float needTime;// 消耗的时间
	enum{
		FRAME_TYPE_TIME_ANIMATION, // 时间帧
		FRAME_TYPE_LOCATION_ACTION, // 位置帧
	};
	enum{
		NEXT_TYPE_SEQUENCE, // 下一个与当前串行
		NEXT_TYPE_TOGATHER, // 下一个与当前并行
	};
	SkillActionInfo()
	{
		jumpHeight = 10;
		frameType = FRAME_TYPE_TIME_ANIMATION;
		needTime = 1;
		self = false;
		delayTime = 0;
		rotation  = 0;
		nextInfo = NULL;
	}
	void release(){}
	CCAnimation *createAnimation(float costtime = 0);
	CCFiniteTimeAction * createAction(CCNode *self,CCNode *parent,CCNode *target,const CCPoint &point = ccp(-1,-1),float needTime = 0,stCollideTargetCallback *callback = NULL);
};
 /**
 * 动画移动动作 将会作用在自己身上 
 * 动画帧与移动相关联
 */
class SkillMoveAction:public CCMoveBy{
public:
	
	virtual void update(float time);
	bool isTempTarget;
	SkillMoveAction()
	{
		isTempTarget = false;
	}

	/**
	 * 创建动画
	 */
	static SkillMoveAction* create(const SkillActionInfo &cartoonInfo, const CCPoint& position);
	/**
	 * 初始化cartoon 移动行为
	 */
	bool init(const SkillActionInfo &SkillActionInfo, const CCPoint& position);
	/**
	 * 释放自己所占有的帧
	 */
	void stop(void);
	
protected:
	SkillActionInfo cartoonInfo;
};
/**
 * 移动时间帧
 **/
class TimeFramesMoveBy:public CCMoveBy{

};
/**
 * 使时间帧跳跃
 */
class TimeFramesJump:public CCJumpBy{
public:
	TimeFramesJump()
	{
		isTempTarget = false;
		callback = NULL;
	}
    static TimeFramesJump* create(float duration, const CCPoint& position, float height, unsigned int jumps);
   
	void stop(void);
 
    bool isTempTarget;
	stCollideTargetCallback *callback;
};
 /**
  * <Config>
		<frames fileset="">
			<frame name=""/>
			<frame name=""/>
		</frames>
  * </Config>
  **/
class CartoonFromPack:public CCObject,public script::tixmlCode{
public:
	static CartoonFromPack* create(SkillActionInfo *info,const std::string &name)
	{
		CartoonFromPack *pack = new CartoonFromPack();
		pack->info = info;
		pack->init(name);
		pack->autorelease();
		return pack;
	}
	static CartoonFromPack* create(SkillActionInfo *info,script::tixmlCodeNode *node)
	{
		CartoonFromPack *pack = new CartoonFromPack();
		pack->info = info;
		pack->initNode(node);
		pack->autorelease();
		return pack;
	}
	bool init(const std::string &name)
	{
		return script::tixmlCode::initWithXmlFile(name.c_str());
	}
	void takeNode(script::tixmlCodeNode *node)
	{
		if (node->equal("Config"))
		{
			script::tixmlCodeNode framesNode = node->getFirstChildNode("frames");
			initNode(&framesNode);
		}
	}
	SkillActionInfo *info;
	void initNode(script::tixmlCodeNode *node)
	{
		if (node->equal("frames"))
		{
			std::string fileSetName = node->getAttr("fileset");
			FileSet fileSet;
			fileSet.createFromFile(fileSetName.c_str()); // 从配置文件中获取信息
			script::tixmlCodeNode frameNode = node->getFirstChildNode("frame");
			while (frameNode.isValid())
			{
				LocalSpriteFrame *frame = LocalSpriteFrame::create(frameNode.getAttr("name"),&fileSet);
				info->frames.push_back(frame);
				frame->retain();
				frameNode = frameNode.getNextNode("frame");
			}
			fileSet.destroy();
		}
	}
};
/**
 * 每个子技能对象结束后回调
 */
class ChildSkillEndAction:public CCCallFunc{
public:
	static ChildSkillEndAction* create(CCNode *self,SkillActionInfo *info)
	{
		ChildSkillEndAction *pRet = new ChildSkillEndAction();
        pRet->autorelease();
        return pRet;
    }
	virtual void execute()
	{
		// 尝试去调用脚本
	}
	CCNode *self;
	SkillActionInfo*info;
	ChildSkillEndAction()
	{
		self = NULL;
		info = NULL;
	}
};

/**
 * 指导文件
 * <skill name="" >
 *			<action cartoonbin="" delaytime=""  self="false" endcode="结束时的触发动画" startcode="开始时的触发动画" collide="true"/>
 *			<action cartoonbin="" delaytime="" nexttype="sequence" self="false" endcode="结束时的触发动画" startcode="开始时的触发动画" collide="true"/>
 * </skill>
 */
/**
 * 技能行为
 **/
class SkillAction:public CCObject,public script::tixmlCode{
public:
	SkillActionInfo*info; // 创建好动画信息
	std::string skillName;
	SkillAction()
	{
		info = NULL;
	}
	static SkillAction* create(const std::string &skillName)
	{
		SkillAction *skillAction = new SkillAction();
		skillAction->init(skillName);
		skillAction->autorelease();
		return skillAction;
	}
	bool init(const std::string &skillName)
	{
		return initWithXmlFile(skillName.c_str());
	}
	void takeNode(script::tixmlCodeNode *node)
	{
		if (node->equal("Config"))
		{
			script::tixmlCodeNode skillNode = node->getFirstChildNode("skill");
			initNode(&skillNode);
		}
	}
	void initNode(script::tixmlCodeNode *node)
	{
		if (node->equal("skill"))
		{
			skillName = node->getAttr("name");
			script::tixmlCodeNode actionNode = node->getFirstChildNode("action");
			SkillActionInfo *preInfo = NULL;
			while (actionNode.isValid())
			{
				SkillActionInfo*info = new SkillActionInfo();
				std::string binName  = actionNode.getAttr("cartoonbin");
				script::tixmlCodeNode framesNode = actionNode.getFirstChildNode("frames");
				CartoonFromPack::create(info,&framesNode);
				info->delayTime = actionNode.getInt("delaytime");
				info->self = actionNode.getBool("self");
				std::string actiontypeName = actionNode.getAttr("actiontype");
				if (actiontypeName == "stop")
				{
					info->actionType = SkillActionInfo::ACTION_STOP;
				}
				if (actiontypeName == "move")
				{
					info->actionType = SkillActionInfo::ACTION_MOVE;
				}
				if (actiontypeName == "follow")
				{
					info->actionType = SkillActionInfo::ACTION_FOLLOW;
				}
				if (actiontypeName == "jump")
				{
					info->actionType = SkillActionInfo::ACTION_JUMP;
				}
				info->needTime = actionNode.getFloat("needtime");
				std::string nextTypeStr = actionNode.getAttr("nexttype");
				info->offset.x = actionNode.getInt("offsetx");
				info->offset.y = actionNode.getInt("offsety");
				info->rotation = actionNode.getFloat("rotation");
				info->jumpHeight = actionNode.getInt("jumpheight");
				if (nextTypeStr == "sequence")
				{
					info->nextType = SkillActionInfo::NEXT_TYPE_SEQUENCE;
				}
				else
				{
					info->nextType = SkillActionInfo::NEXT_TYPE_TOGATHER;
				}
				if (!preInfo) // 将信息串联起来
				{
					preInfo = info;
					this->info = info;
				}
				else
				{
					preInfo->nextInfo = info;
					preInfo = info;
				}
					
				actionNode = actionNode.getNextNode("action");
			}
		}
	}
	void runAction(CCNode *self,const cocos2d::CCPoint &point = ccp(-1,-1),CCNode *target = NULL,int needTime=0,stCollideTargetCallback * callback = NULL)
	{
		if (!info) return;
		SkillActionInfo * root =(SkillActionInfo*) info;
		int nextConbine = root->nextType;
		CCFiniteTimeAction *preAction = NULL;
		CCFiniteTimeAction *nowAction = NULL;
		while(root)
		{
			nowAction = root->createAction(self,self->getParent(),target,point,needTime,callback); // 碰撞pack
			if (!preAction)
			{
				preAction = CCSequence::create(nowAction,NULL);
			}
			else
			{
				switch(nextConbine)
				{
					case SkillActionInfo::NEXT_TYPE_SEQUENCE:
					{
						preAction = CCSequence::create(preAction,nowAction,NULL); 
					}break;
					case SkillActionInfo::NEXT_TYPE_TOGATHER:
					{
						preAction = CCSpawn::create(preAction,nowAction,NULL);
					}break;
				}
				if (root->delayTime)
				{
					preAction = CCSequence::create(CCDelayTime::create(root->delayTime),preAction,NULL);// 创建delay
				}
				preAction = CCSequence::create(preAction,
					ChildSkillEndAction::create(self,root),
					NULL); // 创建回调
			}
			nextConbine = root->nextType;
			root = root->nextInfo;
		}
		if (preAction)
		{
			CCFiniteTimeAction *seqaction = CCSequence::create(preAction,
					/*CCDelayTime::create(0.5),*/
						/*CCCallFunc::create(this, callfunc_selector(Cartoon::doCartoonEnd)),*/
						NULL);
		
			if (seqaction)
			{
				self->runAction(seqaction);
			}
		}
	}
};

class SkillManager{
public:
	static SkillManager& getMe()
	{
		static SkillManager sm;
		return sm;
	}
	SkillAction * find(const std::string &name)
	{
		SKILLS_ITER iter = skills.find(name);
		if (iter != skills.end())
		{
			return iter->second;
		}
		SkillAction *skill = SkillAction::create(name);
		skills[name] = skill;
		skill->retain();
		return skill;
	}
	
	std::map<std::string,SkillAction*> skills;
	typedef std::map<std::string,SkillAction*>::iterator SKILLS_ITER;
};
#define theSkill(name) SkillManager::getMe().find(name)
NS_CC_END