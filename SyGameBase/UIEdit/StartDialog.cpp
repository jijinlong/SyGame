#include "StartDialog.h"
#include "UIButton.h"
#include "UIWindow.h"
#include "UIXmlBag.h"
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
				}
				stReqLogin(UIWindow *window,StartDialog *dialog):window(window),dialog(dialog)
				{
				
				}
				UIWindow *window;
				StartDialog *dialog;
			};
		}
		
	} while (false);
}
/**
 * 关闭当前panel
 **/
struct stClosePanel:public UICallback{
	void callback(UIBase *base)
	{
		if (base && base->getParent())
		{
			base->getParent()->setVisible(false);
		}
	}
	stClosePanel()
	{
	
	}
};
/**
 * 展示属性
 */
struct stShowProp:public UICallback{
public:
	void callback(UIBase *base)
	{
	
	}

};

/**
 * 创建按钮
 */
struct stCreateButton:public UICallback{
public:
	virtual void callback(UIBase *base)
	{
		if (dialog && window)
		{
			UIPanel *panel = window->getNowTouchPanel();
			if (panel)
			{
				UIButton *btn = (UIButton*)panel->createButton(ccp(0,300),CCSizeMake(64,64),
					"btn_common_down.png","btn_common_up.png",panel);
				if (btn)
				{
					btn->setEditable(true);
					btn->bind(UIBase::EVENT_EDIT_DOWN,new stShowProp());
				}
			}
		}
	}
	stCreateButton(MainDialog *dialog,UIWindow *window):dialog(dialog),window(window)
	{
	
	}
protected:
	MainDialog *dialog;
	UIWindow *window;
};
/**
 * 创建Panel
 */
struct stCreatePanel:public stCreateButton{
public:
	virtual void callback(UIBase *base)
	{
		if (dialog && window)
		{
			DefaultDialog * dialog = DefaultDialog::create(window,"defaultdialog.xml");
		}
	}
	stCreatePanel(MainDialog *dialog,UIWindow *window):stCreateButton(dialog,window)
	{}
};
/**
 * 创建Panel
 */
struct stSavePanel:public stCreateButton{
public:
	virtual void callback(UIBase *base)
	{
		if (dialog && window)
		{
			SavePanelDialog *savePanel = (SavePanelDialog*)window->getPanel("save");
			if (savePanel)
			{
			savePanel->nowPanel = window->getNowTouchPanel();
			savePanel->setVisible(true);
			}
		}
	}
	stSavePanel(MainDialog *dialog,UIWindow *window):stCreateButton(dialog,window)
	{}
};
/**
 * 创建图片
 */
struct stCreateImage:public stCreateButton{
public:
	virtual void callback(UIBase *base)
	{
		if (dialog && window)
		{
			// 创建图片
			UIPanel *panel = window->getNowTouchPanel();
			if (panel)
			{
				UIImage *image = (UIImage*) panel->createImage(ccp(0,300),CCSizeMake(0,0),"defaultimg.png",panel);
				if (image)
				{
					image->setEditable(true);
					image->bind(UIBase::EVENT_EDIT_DOWN,new stShowProp());
				}
			}
		}
	}
	stCreateImage(MainDialog *dialog,UIWindow *window):stCreateButton(dialog,window)
	{}
};
/**
 * 创建文本
 */
struct stCreateText:public stCreateButton{
public:
	virtual void callback(UIBase *base)
	{
		if (dialog && window)
		{
			// 创建图片
			UIPanel *panel = window->getNowTouchPanel();
			if (panel)
			{
				UILabel * label = (UILabel*)panel->createLabel(ccp(0,0),CCSizeMake(0,0),"default",32,panel);
				if (label)
				{
					label->setEditable(true);
					label->bind(UIBase::EVENT_EDIT_DOWN,new stShowProp());
				}
			}
		}
	}
	stCreateText(MainDialog *dialog,UIWindow *window):stCreateButton(dialog,window)
	{}
};

/**
 * 创建输入框
 */
struct stCreateEditField :public stCreateButton{
public:
	virtual void callback(UIBase *base)
	{
		if (dialog && window)
		{
			// 创建图片
			UIPanel *panel = window->getNowTouchPanel();
			if (panel)
			{
				UIEditField *editField = (UIEditField*) panel->createTextField(ccp(0,0),CCSizeMake(100,32),"hello,world",panel);
				if (editField)
				{
					editField->setEditable(true);
					editField->bind(UIBase::EVENT_EDIT_DOWN,new stShowProp());
				}
			}
		}
	}
	stCreateEditField(MainDialog *dialog,UIWindow *window):stCreateButton(dialog,window)
	{}
};
/**
 * 创建数字
 */



/**
 * 创建包裹
 */

/**
 * 创建收纳BAG
 */

/**
 * 创建界面动画
 */

void MainDialog::doInitEvent()
{	
	do{
		GET_UI_BYNAME(this,UIButton,closeBtn,"close");
		if (closeBtn)
		{
			closeBtn->bind(UIBase::EVENT_CLICK_DOWN,new stClosePanel());
		}
		GET_UI_BYNAME(this,UIButton,crtBtnBtn,"button");
		if (crtBtnBtn)
		{
			crtBtnBtn->bind(UIBase::EVENT_CLICK_DOWN,new stCreateButton(this,this->window));
		}
		GET_UI_BYNAME(this,UIButton,crtImageBtn,"image");
		if (crtImageBtn)
		{
			crtImageBtn->bind(UIBase::EVENT_CLICK_DOWN,new stCreateImage(this,this->window));
		}
		GET_UI_BYNAME(this,UIButton,crtTextBtn,"text");
		if (crtTextBtn)
		{
			crtTextBtn->bind(UIBase::EVENT_CLICK_DOWN,new stCreateText(this,this->window));
		}
		GET_UI_BYNAME(this,UIButton,crtEditBtn,"editfield");
		if (crtEditBtn)
		{
			crtEditBtn->bind(UIBase::EVENT_CLICK_DOWN,new stCreateEditField(this,this->window));
		}
		GET_UI_BYNAME(this,UIButton,crtPanelBtn,"panel");
		if (crtPanelBtn)
		{
			crtPanelBtn->bind(UIBase::EVENT_CLICK_DOWN,new stCreatePanel(this,this->window));
		}
		GET_UI_BYNAME(this,UIButton,saveBtn,"save");
		if (saveBtn)
		{
			saveBtn->bind(UIBase::EVENT_CLICK_DOWN,new stSavePanel(this,this->window));
		}
	}while(false);
}

/**
 * 创建的属性界面
 */
void PropDialog::doInitEvent()
{
	
}
struct stSurePanel:public UICallback{
public:
	void callback(UIBase *base)
	{
		if (base && base->getParent())
		{
			base->getParent()->setVisible(false);
			GET_UI_BYNAME(saveDialog,UIEditField,txtField,"filename");
			if (txtField)
			{
				saveDialog->savePanel(txtField->getContent());
			}
		}
	}
	stSurePanel(SavePanelDialog *saveDialog):saveDialog(saveDialog)
	{
	
	}
	SavePanelDialog* saveDialog;
};
void SavePanelDialog::doInitEvent()
{
	do{
		GET_UI_BYNAME(this,UIButton,cancelBtn,"canel");
		if (cancelBtn)
		{
			cancelBtn->bind(UIBase::EVENT_CLICK_DOWN,new stClosePanel());
		}
		GET_UI_BYNAME(this,UIButton,sureBtn,"sure");
		if (sureBtn)
		{
			sureBtn->bind(UIBase::EVENT_CLICK_DOWN,new stSurePanel(this)); // 确定保存
		}
	}while(false);
}

void SavePanelDialog::savePanel(const std::string &name)
{
	if (nowPanel)
		nowPanel->makeXmlFile(name);
}
NS_CC_END
