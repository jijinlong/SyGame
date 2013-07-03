#include "StartDialog.h"
#include "UIButton.h"
#include "UIWindow.h"
#include "PinTuAboutNet.h"
#include "UIXmlBag.h"
#include "UIManager.h"
#include "BollActor.h"
NS_CC_BEGIN
void StartDialog::doInitEvent()
{
	CCSize s = CCDirector::sharedDirector()->getWinSize();
	do{
		GET_UI_BYNAME(this,UIButton,reqLoginBtn,"login");
		if (reqLoginBtn)
		{
			struct stReqLogin:public UICallback{
				void callback(UIBase *base)
				{
					// 尝试读取系统中的 登录名 登录密码 并发送到网络
					// 在Request.cpp 中创建场景
					// 创建等待动画
					
					GET_UI_BYNAME(dialog,UIEditField,uiName,"name");
					std::string userName,userPwd;
					if (uiName)
					{
						userName = uiName->getContent();
					}
					GET_UI_BYNAME(dialog,UIEditField,pwdName,"pwd");
					if (pwdName)
					{
						userPwd = pwdName->getContent();
					}
					theRequest.reqLogin(theNet.getSocket(),userName,userPwd);// 尝试登录进系统
				}
				stReqLogin(UIWindow *window,StartDialog *dialog):window(window),dialog(dialog)
				{
				
				}
				UIWindow *window;
				StartDialog *dialog;
			};
			reqLoginBtn->bind(UIBase::EVENT_CLICK_DOWN,new stReqLogin(window,this));
		}
		
	} while (false);
}

void MainDialog::doInitEvent()
{	
	do{
		GET_UI_BYNAME(this,UIButton,gameBtn,"tiyuchang");
		if (gameBtn)
		{
			struct stShowGames:public UICallback{
				void callback(UIBase *base)
				{
					theUI.hideAll();
					UIPanel *loginPanel = theUI.getPanel("games");
					if (loginPanel)
					{
						loginPanel->setVisible(true);
						theBollManager.start("start");
					}
				}
			};
			gameBtn->bind(UIBase::EVENT_CLICK_DOWN,new stShowGames());
		}
		
	} while (false);
}
GameItem *GameItem::create(script::tixmlCodeNode *snode)
{
	GameItem *node = new GameItem();
	if (node)
	{
		node->initWithNode(snode);
		node->autorelease();
		return node;
	}
	CC_SAFE_DELETE(node);
}
void GameItem::initWithNode(script::tixmlCodeNode *node)
{
	if (node->equal("item"))
	{
		back = CCSprite::create(node->getAttr("pngname"));
		if (back)
		{
			back->setAnchorPoint(ccp(0,0));
			this->addChild(back);
		}
	}
}
void GameItem::setSize(float w,float h)
{
	if (back)
	{
		back->setScaleX(w / back->getContentSize().width);
		back->setScaleY(h / back->getContentSize().height);
	}
}
void GameDialog::doInitEvent()
{
	
}
void GameDialog::vTakeNode(script::tixmlCodeNode *node)
{
	if (node->equal("Config"))
	{
		int count = 0;
		script::tixmlCodeNode itemNode = node->getFirstChildNode("item");
		GET_UI_BYNAME(this,UIViewBag,bag,"bag");
		if (!bag) return;
		while (itemNode.isValid())
		{
			GameItem *item = GameItem::create(&itemNode);
			bag->setItem(item,count++);
			itemNode = itemNode.getNextNode("item");
		}
		bag->show();
	}
}
NS_CC_END
