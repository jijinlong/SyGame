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
 * 编辑消息Down
 */
struct stEditDown:public UICallback{
public:
	virtual  void callback(UIBase *base)
	{
		PropDialog *propPanel = (PropDialog*)window->getPanel("prop");
		if (propPanel)
		{
			propPanel->show(base);
		}
	}
	stEditDown(MainDialog *dialog,UIWindow *window): dialog(dialog),window(window)
	{}
protected:
	MainDialog *dialog;
	UIWindow *window;
};
/**
 * 创建动画 输入动画名字 指定各个帧的图片 和帧处理类型 可以测试动画
 */

/**
 * 创建图片 输入文件名 设定大小 位置 层次
 */

/**
 * 创建背景层 可以在上面放置物体 相对于场景 有移动
 */

/**
 * 新建一个地图 设定名字
 * <map width="" height="" name="">
 *	<cartoon name="" x="" y=""/>
 *	<img src="" x="" y="" w="" h=""/>
 *	<backgroud x="" y="" w="" h="" speed="" />
 * </map>
 */

void MainDialog::doInitEvent()
{	
	do{
		
	}while(false);
}

/**
 * 展示基本数值
 */
void PropBaseShow::show(PropDialog *propDialog,UIBase *base)
{
	
}


/**
 * 展示Button的属性 设定应该展示的属性
 */
void PropButtonShow::show(PropDialog *propDialog,UIButton *button)
{
	
}


void PropPanelShow::show(PropDialog* propDialog,UIPanel *panel)
{

}

/**
 * 隐藏属性
 */
void PropDialog::hideProps()
{
	
}
/**
 * 展示基本控件
 */
void PropDialog::show(UIBase *base)
{
	
}
/**
 * 展示button 的属性
 */
void PropDialog::show(UIButton *button)
{
	
}
/**
 * 展示panel 的属性
 */
void PropDialog::show(UIPanel *panel)
{
	
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
