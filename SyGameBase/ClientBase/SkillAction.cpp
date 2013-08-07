#pragma once
#include "cocos2d.h"
#include "SkillAction.h"

NS_CC_BEGIN
CCAnimation *SkillActionInfo::createAnimation(float costtime)
{
	CCAnimation* animation = CCAnimation::create();
	for (int i = 0; i < frames.size(); i++)
	{
		animation->addSpriteFrame(frames[i]);
	}
	if (frames.empty()) return NULL;
	if (!costtime)
		animation->setDelayPerUnit(needTime / frames.size());
	else
		animation->setDelayPerUnit(costtime / frames.size());
	animation->setRestoreOriginalFrame(true);
	return animation;
}
CCFiniteTimeAction * SkillActionInfo::createAction(CCNode *self,CCNode *parent,CCNode *target,const CCPoint &point,float needTime,stCollideTargetCallback *callback )
{
	CCFiniteTimeAction *action = NULL;
	CCAnimation * animation = NULL;
	this->self = false;
	CCPoint location;
	if (!needTime) needTime = this->needTime;
	if (frameType == FRAME_TYPE_TIME_ANIMATION)
	{
		switch(actionType)
		{
			case ACTION_FOLLOW:
			{
				FollowAnimationAction * followAction = FollowAnimationAction::create(target,needTime);;
				followAction->isTempTarget = true;
				followAction->callback = callback;
				animation = createAnimation(needTime);

				action = followAction;
			}break;
			case ACTION_STOP:
			{
				// 静止动画
				CartoonAction * cartoonAction = CartoonAction::create(createAnimation(needTime));
				action = cartoonAction;
				cartoonAction->isTempTarget = true;
				location = ccpAdd(offset,self->getPosition());
			}break;
			case ACTION_MOVE:
			{
				SkillMoveAction *moveAction = SkillMoveAction::create(*this,offset);
				action = moveAction;
				moveAction->isTempTarget = true;
				location = self->getPosition();
			}break;
			case ACTION_JUMP:
			{
				TimeFramesJump *jumpBy = TimeFramesJump::create(needTime,offset,jumpHeight,1);
				animation = createAnimation(needTime);
				action = jumpBy;
				jumpBy->isTempTarget = true;
				location = self->getPosition();
			}break;
		}
	}
	if (!action) return NULL;

	if (!this->self)
	{
			CCSprite * temp = CCSprite::create();
			if (temp)
			{
				parent->addChild(temp);
				if (animation)
				{
					temp->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
				}
				temp->setPosition(location);
				action->setTarget(temp);
				temp->setRotation(rotation);
			}
	}
	return action;
}
void SkillMoveAction::update(float time)
{
	if (m_pTarget)
	{
		m_pTarget->setPosition(ccp(m_startPosition.x + m_delta.x * time,
			m_startPosition.y + m_delta.y * time));
		CCPoint nowPoint = m_pTarget->getPosition();
		float dw = ccpDistance(nowPoint,m_startPosition);
		float da = ccpDistance(m_endPosition,m_startPosition);
		int frameSize = this->cartoonInfo.frames.size();
		int nowFrameId = frameSize - 1;
		if (da) nowFrameId = frameSize * (dw / da);
		if (nowFrameId >= 0 && nowFrameId < frameSize)
		{
			CCSpriteFrame *frame = this->cartoonInfo.frames[nowFrameId];
			if (frame)
			{
				CCSprite *sprite = static_cast<CCSprite*>(m_pTarget);
				if (sprite)
					sprite->setDisplayFrame(frame);
			}
		}
	}
}
	
SkillMoveAction* SkillMoveAction::create(const SkillActionInfo &cartoonInfo, const CCPoint& position)
{
	SkillMoveAction *pMove = new SkillMoveAction();
	pMove->init(cartoonInfo,position);
    pMove->autorelease();
    return pMove;
}
/**
* 初始化cartoon 移动行为
*/
bool SkillMoveAction::init(const SkillActionInfo &cartoonInfo, const CCPoint& position)
{
	this->cartoonInfo = cartoonInfo;
	initWithDuration(cartoonInfo.needTime, position);
	return true;
}

void SkillMoveAction::stop(void)
{
	CCNode *tempTarget = m_pTarget; 
	CCMoveBy::stop();
	cartoonInfo.release();
	if (isTempTarget)
	{
		tempTarget->removeFromParentAndCleanup(true);
	}
}
/**
 * 时间帧跳跃
 **/
TimeFramesJump* TimeFramesJump::create(float duration, const CCPoint& position, float height, unsigned int jumps)
{
	TimeFramesJump *jump = new TimeFramesJump();
	jump->autorelease();
	jump->initWithDuration(duration, position, height, jumps);
	return jump;
}   
void TimeFramesJump::stop(void){
	CCNode *tempTarget = m_pTarget; 
	CCJumpBy::stop();
	if (isTempTarget)
	{
		tempTarget->removeFromParentAndCleanup(true);
	}
}
   
NS_CC_END
