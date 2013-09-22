/*
** Lua binding: MyUI
** Generated automatically by tolua++-1.0.92 on 09/22/13 14:46:35.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_MyUI_open (lua_State* tolua_S);

#include "MyUI.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
#ifndef Mtolua_typeid
#define Mtolua_typeid(L,TI,T)
#endif
}

/* Open function */
TOLUA_API int tolua_MyUI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_MyUI (lua_State* tolua_S) {
 return tolua_MyUI_open(tolua_S);
};
#endif

/*
** Lua binding: MyUI
** Generated automatically by tolua++-1.0.92 on 09/22/13 14:48:05.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_MyUI_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CCPoint (lua_State* tolua_S)
{
 CCPoint* self = (CCPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__ScrollView (lua_State* tolua_S)
{
 myui::ScrollView* self = (myui::ScrollView*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__Tree (lua_State* tolua_S)
{
 myui::Tree* self = (myui::Tree*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__Base (lua_State* tolua_S)
{
 myui::Base* self = (myui::Base*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CCSize (lua_State* tolua_S)
{
 CCSize* self = (CCSize*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__Slider (lua_State* tolua_S)
{
 myui::Slider* self = (myui::Slider*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__Image (lua_State* tolua_S)
{
 myui::Image* self = (myui::Image*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__Table (lua_State* tolua_S)
{
 myui::Table* self = (myui::Table*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__HPLabel (lua_State* tolua_S)
{
 myui::HPLabel* self = (myui::HPLabel*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__List (lua_State* tolua_S)
{
 myui::List* self = (myui::List*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
#ifndef Mtolua_typeid
#define Mtolua_typeid(L,TI,T)
#endif
 tolua_usertype(tolua_S,"CCPoint");
 Mtolua_typeid(tolua_S,typeid(CCPoint), "CCPoint");
 tolua_usertype(tolua_S,"myui::Tree");
 Mtolua_typeid(tolua_S,typeid(myui::Tree), "myui::Tree");
 tolua_usertype(tolua_S,"CCTouch");
 Mtolua_typeid(tolua_S,typeid(CCTouch), "CCTouch");
 tolua_usertype(tolua_S,"myui::List");
 Mtolua_typeid(tolua_S,typeid(myui::List), "myui::List");
 tolua_usertype(tolua_S,"myui::TouchHandle");
 Mtolua_typeid(tolua_S,typeid(myui::TouchHandle), "myui::TouchHandle");
 tolua_usertype(tolua_S,"cocos2d::CCEvent");
 Mtolua_typeid(tolua_S,typeid(cocos2d::CCEvent), "cocos2d::CCEvent");
 tolua_usertype(tolua_S,"myui::Panel");
 Mtolua_typeid(tolua_S,typeid(myui::Panel), "myui::Panel");
 tolua_usertype(tolua_S,"CCNode");
 Mtolua_typeid(tolua_S,typeid(CCNode), "CCNode");
 tolua_usertype(tolua_S,"std::list<myui::Base*>");
 Mtolua_typeid(tolua_S,typeid(std::list<myui::Base*>), "std::list<myui::Base*>");
 tolua_usertype(tolua_S,"CCNodeRGBA");
 Mtolua_typeid(tolua_S,typeid(CCNodeRGBA), "CCNodeRGBA");
 tolua_usertype(tolua_S,"myui::Button");
 Mtolua_typeid(tolua_S,typeid(myui::Button), "myui::Button");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 Mtolua_typeid(tolua_S,typeid(std::vector<std::string>), "std::vector<std::string>");
 tolua_usertype(tolua_S,"std::list<myui::Image*>");
 Mtolua_typeid(tolua_S,typeid(std::list<myui::Image*>), "std::list<myui::Image*>");
 tolua_usertype(tolua_S,"myui::Slider");
 Mtolua_typeid(tolua_S,typeid(myui::Slider), "myui::Slider");
 tolua_usertype(tolua_S,"CCRect");
 Mtolua_typeid(tolua_S,typeid(CCRect), "CCRect");
 tolua_usertype(tolua_S,"myui::Bubble");
 Mtolua_typeid(tolua_S,typeid(myui::Bubble), "myui::Bubble");
 tolua_usertype(tolua_S,"std::vector<CCLabelAtlas*>");
 Mtolua_typeid(tolua_S,typeid(std::vector<CCLabelAtlas*>), "std::vector<CCLabelAtlas*>");
 tolua_usertype(tolua_S,"myui::Label");
 Mtolua_typeid(tolua_S,typeid(myui::Label), "myui::Label");
 tolua_usertype(tolua_S,"CCSize");
 Mtolua_typeid(tolua_S,typeid(CCSize), "CCSize");
 tolua_usertype(tolua_S,"CCAction");
 Mtolua_typeid(tolua_S,typeid(CCAction), "CCAction");
 tolua_usertype(tolua_S,"myui::ScrollView");
 Mtolua_typeid(tolua_S,typeid(myui::ScrollView), "myui::ScrollView");
 tolua_usertype(tolua_S,"myui::Choice");
 Mtolua_typeid(tolua_S,typeid(myui::Choice), "myui::Choice");
 tolua_usertype(tolua_S,"myui::Base");
 Mtolua_typeid(tolua_S,typeid(myui::Base), "myui::Base");
 tolua_usertype(tolua_S,"cocos2d::CCSet");
 Mtolua_typeid(tolua_S,typeid(cocos2d::CCSet), "cocos2d::CCSet");
 tolua_usertype(tolua_S,"CCImage");
 Mtolua_typeid(tolua_S,typeid(CCImage), "CCImage");
 tolua_usertype(tolua_S,"myui::Image");
 Mtolua_typeid(tolua_S,typeid(myui::Image), "myui::Image");
 tolua_usertype(tolua_S,"CCLayer");
 Mtolua_typeid(tolua_S,typeid(CCLayer), "CCLayer");
 tolua_usertype(tolua_S,"myui::Window");
 Mtolua_typeid(tolua_S,typeid(myui::Window), "myui::Window");
 tolua_usertype(tolua_S,"USING_NS_CC");
 Mtolua_typeid(tolua_S,typeid(USING_NS_CC), "USING_NS_CC");
 tolua_usertype(tolua_S,"CCSprite");
 Mtolua_typeid(tolua_S,typeid(CCSprite), "CCSprite");
 tolua_usertype(tolua_S,"std::vector<myui::Image*>");
 Mtolua_typeid(tolua_S,typeid(std::vector<myui::Image*>), "std::vector<myui::Image*>");
 tolua_usertype(tolua_S,"myui::Table");
 Mtolua_typeid(tolua_S,typeid(myui::Table), "myui::Table");
 tolua_usertype(tolua_S,"myui::HPLabel");
 Mtolua_typeid(tolua_S,typeid(myui::HPLabel), "myui::HPLabel");
 tolua_usertype(tolua_S,"CCObject");
 Mtolua_typeid(tolua_S,typeid(CCObject), "CCObject");
}

/* get function: tolua_var_1 */
#ifndef TOLUA_DISABLE_tolua_get_USING_NS_CC
static int tolua_get_USING_NS_CC(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&tolua_var_1,"USING_NS_CC");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tolua_var_1 */
#ifndef TOLUA_DISABLE_tolua_set_USING_NS_CC
static int tolua_set_USING_NS_CC(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"USING_NS_CC",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  tolua_var_1 = *((USING_NS_CC*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_create00
static int tolua_MyUI_myui_Panel_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Panel* tolua_ret = (myui::Panel*)  myui::Panel::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Panel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: uis of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_get_myui__Panel_uis
static int tolua_get_myui__Panel_uis(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uis'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->uis,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uis of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_set_myui__Panel_uis
static int tolua_set_myui__Panel_uis(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uis'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->uis = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: actives of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_get_myui__Panel_actives
static int tolua_get_myui__Panel_actives(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actives'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->actives,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: actives of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_set_myui__Panel_actives
static int tolua_set_myui__Panel_actives(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actives'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->actives = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: firsts of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_get_myui__Panel_firsts
static int tolua_get_myui__Panel_firsts(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firsts'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->firsts,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: firsts of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_set_myui__Panel_firsts
static int tolua_set_myui__Panel_firsts(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firsts'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->firsts = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachTouch of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_attachTouch00
static int tolua_MyUI_myui_Panel_attachTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->attachTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addUI of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_addUI00
static int tolua_MyUI_myui_Panel_addUI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addUI'",NULL);
#endif
  {
   self->addUI(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_visit00
static int tolua_MyUI_myui_Panel_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLocation of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_setLocation00
static int tolua_MyUI_myui_Panel_setLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
  myui::AlignType alignType = ((myui::AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLocation'",NULL);
#endif
  {
   self->setLocation(alignType,*splitSize,*gridLocation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_setSize00
static int tolua_MyUI_myui_Panel_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'",NULL);
#endif
  {
   self->setSize(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rect of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_get_myui__Panel_rect
static int tolua_get_myui__Panel_rect(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->rect,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rect of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_set_myui__Panel_rect
static int tolua_set_myui__Panel_rect(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rect = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSize of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_getSize00
static int tolua_MyUI_myui_Panel_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'",NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoint of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_getPoint00
static int tolua_MyUI_myui_Panel_getPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
  myui::AlignType alignType = ((myui::AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPoint'",NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->getPoint(alignType,*splitSize,*gridLocation);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_new00
static int tolua_MyUI_myui_Base_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Base* tolua_ret = (myui::Base*)  Mtolua_new((myui::Base)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Base");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_new00_local
static int tolua_MyUI_myui_Base_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Base* tolua_ret = (myui::Base*)  Mtolua_new((myui::Base)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Base");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_checkIn00
static int tolua_MyUI_myui_Base_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bindTouchHandle of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_bindTouchHandle00
static int tolua_MyUI_myui_Base_bindTouchHandle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::TouchHandle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchHandle* touchHandle = ((myui::TouchHandle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bindTouchHandle'",NULL);
#endif
  {
   self->bindTouchHandle(touchHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bindTouchHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMoveable of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_setMoveable00
static int tolua_MyUI_myui_Base_setMoveable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  bool moveableTag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMoveable'",NULL);
#endif
  {
   self->setMoveable(moveableTag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMoveable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachTouch of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_attachTouch00
static int tolua_MyUI_myui_Base_attachTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->attachTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_doTouch00
static int tolua_MyUI_myui_Base_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: touch of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_touch_ptr
static int tolua_get_myui__Base_touch_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'touch'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->touch,"CCTouch");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: touch of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_touch_ptr
static int tolua_set_myui__Base_touch_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'touch'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowTouchPoint of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_nowTouchPoint
static int tolua_get_myui__Base_nowTouchPoint(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchPoint'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->nowTouchPoint,"CCPoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowTouchPoint of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_nowTouchPoint
static int tolua_set_myui__Base_nowTouchPoint(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchPoint'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowTouchPoint = *((CCPoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isActive of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_isActive
static int tolua_get_myui__Base_isActive(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isActive'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isActive);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isActive of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_isActive
static int tolua_set_myui__Base_isActive(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isActive'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isActive = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: moveAble of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_moveAble
static int tolua_get_myui__Base_moveAble(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moveAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->moveAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: moveAble of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_moveAble
static int tolua_set_myui__Base_moveAble(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moveAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->moveAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: panel of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_panel_ptr
static int tolua_get_myui__Base_panel_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'panel'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->panel,"myui::Panel");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: panel of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_panel_ptr
static int tolua_set_myui__Base_panel_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'panel'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Panel",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->panel = ((myui::Panel*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parent of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_parent_ptr
static int tolua_get_myui__Base_parent_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->parent,"CCNode");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parent of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_parent_ptr
static int tolua_set_myui__Base_parent_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->parent = ((CCNode*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLocation of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_setLocation00
static int tolua_MyUI_myui_Base_setLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  myui::AlignType alignType = ((myui::AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLocation'",NULL);
#endif
  {
   self->setLocation(alignType,*splitSize,*gridLocation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInView of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_setInView00
static int tolua_MyUI_myui_Base_setInView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInView'",NULL);
#endif
  {
   self->setInView(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleDown of class  myui::TouchHandle */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_TouchHandle_handleDown00
static int tolua_MyUI_myui_TouchHandle_handleDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::TouchHandle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::TouchHandle* self = (myui::TouchHandle*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleDown'",NULL);
#endif
  {
   self->handleDown(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handleDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleMove of class  myui::TouchHandle */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_TouchHandle_handleMove00
static int tolua_MyUI_myui_TouchHandle_handleMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::TouchHandle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::TouchHandle* self = (myui::TouchHandle*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleMove'",NULL);
#endif
  {
   self->handleMove(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handleMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleEnd of class  myui::TouchHandle */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_TouchHandle_handleEnd00
static int tolua_MyUI_myui_TouchHandle_handleEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::TouchHandle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::TouchHandle* self = (myui::TouchHandle*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleEnd'",NULL);
#endif
  {
   self->handleEnd(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handleEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleClick of class  myui::TouchHandle */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_TouchHandle_handleClick00
static int tolua_MyUI_myui_TouchHandle_handleClick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::TouchHandle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::TouchHandle* self = (myui::TouchHandle*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleClick'",NULL);
#endif
  {
   self->handleClick(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handleClick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_create00
static int tolua_MyUI_myui_Image_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* pngName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   myui::Image* tolua_ret = (myui::Image*)  myui::Image::create(pngName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Image");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_checkIn00
static int tolua_MyUI_myui_Image_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_checkIn01
static int tolua_MyUI_myui_Image_checkIn01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(*point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI_myui_Image_checkIn00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pngName of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_get_myui__Image_pngName
static int tolua_get_myui__Image_pngName(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pngName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->pngName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pngName of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_set_myui__Image_pngName
static int tolua_set_myui__Image_pngName(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pngName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pngName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: outlinePngName of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_get_myui__Image_outlinePngName
static int tolua_get_myui__Image_outlinePngName(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outlinePngName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->outlinePngName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: outlinePngName of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_set_myui__Image_outlinePngName
static int tolua_set_myui__Image_outlinePngName(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outlinePngName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->outlinePngName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOutLine of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_setOutLine00
static int tolua_MyUI_myui_Image_setOutLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const char* pngName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOutLine'",NULL);
#endif
  {
   self->setOutLine(pngName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOutLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_doTouch00
static int tolua_MyUI_myui_Image_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sprite of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_get_myui__Image_sprite_ptr
static int tolua_get_myui__Image_sprite_ptr(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->sprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sprite of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_set_myui__Image_sprite_ptr
static int tolua_set_myui__Image_sprite_ptr(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_show00
static int tolua_MyUI_myui_Image_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: replacePng of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_replacePng00
static int tolua_MyUI_myui_Image_replacePng00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'replacePng'",NULL);
#endif
  {
   self->replacePng(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'replacePng'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_checkIn02
static int tolua_MyUI_myui_Image_checkIn02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint point = *((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* sprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  const char* fileName = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(point,sprite,fileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI_myui_Image_checkIn01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkInRect of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_checkInRect00
static int tolua_MyUI_myui_Image_checkInRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint point = *((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* sprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkInRect'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkInRect(point,sprite);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkInRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createImage of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_createImage00
static int tolua_MyUI_myui_Image_createImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const char* fileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCImage* image = ((CCImage*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createImage'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->createImage(fileName,image);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
    tolua_pushusertype(tolua_S,(void*)image,"CCImage");
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_delete00
static int tolua_MyUI_myui_Image_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_new00
static int tolua_MyUI_myui_Image_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Image* tolua_ret = (myui::Image*)  Mtolua_new((myui::Image)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Image");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_new00_local
static int tolua_MyUI_myui_Image_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Image* tolua_ret = (myui::Image*)  Mtolua_new((myui::Image)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Image");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: image of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_get_myui__Image_image_ptr
static int tolua_get_myui__Image_image_ptr(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->image,"CCImage");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: image of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_set_myui__Image_image_ptr
static int tolua_set_myui__Image_image_ptr(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCImage",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->image = ((CCImage*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: runAction of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_runAction00
static int tolua_MyUI_myui_Image_runAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  CCAction* action = ((CCAction*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'runAction'",NULL);
#endif
  {
   self->runAction(action);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'runAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewSize of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_getViewSize00
static int tolua_MyUI_myui_Image_getViewSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewSize'",NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getViewSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: imageSize of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_get_myui__Image_imageSize
static int tolua_get_myui__Image_imageSize(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->imageSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: imageSize of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_set_myui__Image_imageSize
static int tolua_set_myui__Image_imageSize(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->imageSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setsize of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_setsize00
static int tolua_MyUI_myui_Image_setsize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setsize'",NULL);
#endif
  {
   self->setsize(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setsize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInView of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_setInView00
static int tolua_MyUI_myui_Image_setInView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInView'",NULL);
#endif
  {
   self->setInView(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Button_create00
static int tolua_MyUI_myui_Button_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Button",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   myui::Button* tolua_ret = (myui::Button*)  myui::Button::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Button");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Button_doTouch00
static int tolua_MyUI_myui_Button_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Button",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Button* self = (myui::Button*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: upName of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_get_myui__Button_upName
static int tolua_get_myui__Button_upName(lua_State* tolua_S)
{
  myui::Button* self = (myui::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->upName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: upName of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_set_myui__Button_upName
static int tolua_set_myui__Button_upName(lua_State* tolua_S)
{
  myui::Button* self = (myui::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->upName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: downName of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_get_myui__Button_downName
static int tolua_get_myui__Button_downName(lua_State* tolua_S)
{
  myui::Button* self = (myui::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->downName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: downName of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_set_myui__Button_downName
static int tolua_set_myui__Button_downName(lua_State* tolua_S)
{
  myui::Button* self = (myui::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->downName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Choice_create00
static int tolua_MyUI_myui_Choice_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Choice",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   myui::Choice* tolua_ret = (myui::Choice*)  myui::Choice::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Choice");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Choice_doTouch00
static int tolua_MyUI_myui_Choice_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Choice",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: upName of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_get_myui__Choice_upName
static int tolua_get_myui__Choice_upName(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->upName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: upName of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_set_myui__Choice_upName
static int tolua_set_myui__Choice_upName(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->upName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: downName of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_get_myui__Choice_downName
static int tolua_get_myui__Choice_downName(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->downName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: downName of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_set_myui__Choice_downName
static int tolua_set_myui__Choice_downName(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->downName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: choiceAble of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_get_myui__Choice_choiceAble
static int tolua_get_myui__Choice_choiceAble(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'choiceAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->choiceAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: choiceAble of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_set_myui__Choice_choiceAble
static int tolua_set_myui__Choice_choiceAble(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'choiceAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->choiceAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Bubble_create00
static int tolua_MyUI_myui_Bubble_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Bubble",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   myui::Bubble* tolua_ret = (myui::Bubble*)  myui::Bubble::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Bubble");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Bubble_doTouch00
static int tolua_MyUI_myui_Bubble_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Bubble",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: upName of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_get_myui__Bubble_upName
static int tolua_get_myui__Bubble_upName(lua_State* tolua_S)
{
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->upName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: upName of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_set_myui__Bubble_upName
static int tolua_set_myui__Bubble_upName(lua_State* tolua_S)
{
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->upName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: downName of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_get_myui__Bubble_downName
static int tolua_get_myui__Bubble_downName(lua_State* tolua_S)
{
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->downName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: downName of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_set_myui__Bubble_downName
static int tolua_set_myui__Bubble_downName(lua_State* tolua_S)
{
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->downName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: popUp of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Bubble_popUp00
static int tolua_MyUI_myui_Bubble_popUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Bubble",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popUp'",NULL);
#endif
  {
   self->popUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_create00
static int tolua_MyUI_myui_Slider_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   myui::Slider* tolua_ret = (myui::Slider*)  myui::Slider::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Slider");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_init00
static int tolua_MyUI_myui_Slider_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(upName,downName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_checkIn00
static int tolua_MyUI_myui_Slider_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_doTouch00
static int tolua_MyUI_myui_Slider_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: backSprite of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_get_myui__Slider_backSprite_ptr
static int tolua_get_myui__Slider_backSprite_ptr(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->backSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: backSprite of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_set_myui__Slider_backSprite_ptr
static int tolua_set_myui__Slider_backSprite_ptr(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->backSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sliderSprite of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_get_myui__Slider_sliderSprite_ptr
static int tolua_get_myui__Slider_sliderSprite_ptr(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sliderSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->sliderSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sliderSprite of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_set_myui__Slider_sliderSprite_ptr
static int tolua_set_myui__Slider_sliderSprite_ptr(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sliderSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sliderSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValue of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_getValue00
static int tolua_MyUI_myui_Slider_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValue'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setValue of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_setValue00
static int tolua_MyUI_myui_Slider_setValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setValue'",NULL);
#endif
  {
   self->setValue(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_get_myui__Slider_value
static int tolua_get_myui__Slider_value(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_set_myui__Slider_value
static int tolua_set_myui__Slider_value(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_new00
static int tolua_MyUI_myui_Slider_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Slider* tolua_ret = (myui::Slider*)  Mtolua_new((myui::Slider)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Slider");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_new00_local
static int tolua_MyUI_myui_Slider_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Slider* tolua_ret = (myui::Slider*)  Mtolua_new((myui::Slider)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Slider");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaxValue of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_getMaxValue00
static int tolua_MyUI_myui_Slider_getMaxValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxValue'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getMaxValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_create00
static int tolua_MyUI_myui_Label_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  {
   myui::Label* tolua_ret = (myui::Label*)  myui::Label::create(content,*size);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Label");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_init00
static int tolua_MyUI_myui_Label_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(content,*size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArgs of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_getArgs00
static int tolua_MyUI_myui_Label_getArgs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"std::vector<std::string>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
  int argc = ((int)  tolua_tonumber(tolua_S,3,0));
  std::vector<std::string>* args = ((std::vector<std::string>*)  tolua_tousertype(tolua_S,4,0));
  {
   const char* tolua_ret = (const char*)  myui::Label::getArgs(content,argc,*args);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArgs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_checkIn00
static int tolua_MyUI_myui_Label_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_doTouch00
static int tolua_MyUI_myui_Label_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rect of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_get_myui__Label_rect
static int tolua_get_myui__Label_rect(lua_State* tolua_S)
{
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->rect,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rect of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_set_myui__Label_rect
static int tolua_set_myui__Label_rect(lua_State* tolua_S)
{
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rect = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNumber of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_setNumber00
static int tolua_MyUI_myui_Label_setNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
  double value = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNumber'",NULL);
#endif
  {
   self->setNumber(tag,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumber of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_getNumber00
static int tolua_MyUI_myui_Label_getNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumber'",NULL);
#endif
  {
   double tolua_ret = (double)  self->getNumber(tag);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numbers of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_get_myui__Label_numbers
static int tolua_get_myui__Label_numbers(lua_State* tolua_S)
{
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numbers'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->numbers,"std::vector<CCLabelAtlas*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: numbers of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_set_myui__Label_numbers
static int tolua_set_myui__Label_numbers(lua_State* tolua_S)
{
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numbers'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<CCLabelAtlas*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->numbers = *((std::vector<CCLabelAtlas*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_HPLabel_create00
static int tolua_MyUI_myui_HPLabel_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::HPLabel",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* backName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* showName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   myui::HPLabel* tolua_ret = (myui::HPLabel*)  myui::HPLabel::create(backName,showName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::HPLabel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_HPLabel_init00
static int tolua_MyUI_myui_HPLabel_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::HPLabel",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
  const char* backName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* showName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(backName,showName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setValue of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_HPLabel_setValue00
static int tolua_MyUI_myui_HPLabel_setValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::HPLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setValue'",NULL);
#endif
  {
   self->setValue(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: viewSize of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_myui__HPLabel_viewSize
static int tolua_get_myui__HPLabel_viewSize(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'viewSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->viewSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: viewSize of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_myui__HPLabel_viewSize
static int tolua_set_myui__HPLabel_viewSize(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'viewSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->viewSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxValue of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_myui__HPLabel_maxValue
static int tolua_get_myui__HPLabel_maxValue(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->maxValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxValue of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_myui__HPLabel_maxValue
static int tolua_set_myui__HPLabel_maxValue(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->maxValue = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_myui__HPLabel_value
static int tolua_get_myui__HPLabel_value(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_myui__HPLabel_value
static int tolua_set_myui__HPLabel_value(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: backSprite of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_myui__HPLabel_backSprite_ptr
static int tolua_get_myui__HPLabel_backSprite_ptr(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->backSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: backSprite of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_myui__HPLabel_backSprite_ptr
static int tolua_set_myui__HPLabel_backSprite_ptr(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->backSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: valueSprite of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_myui__HPLabel_valueSprite_ptr
static int tolua_get_myui__HPLabel_valueSprite_ptr(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'valueSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->valueSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: valueSprite of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_myui__HPLabel_valueSprite_ptr
static int tolua_set_myui__HPLabel_valueSprite_ptr(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'valueSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->valueSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_HPLabel_new00
static int tolua_MyUI_myui_HPLabel_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::HPLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::HPLabel* tolua_ret = (myui::HPLabel*)  Mtolua_new((myui::HPLabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::HPLabel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_HPLabel_new00_local
static int tolua_MyUI_myui_HPLabel_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::HPLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::HPLabel* tolua_ret = (myui::HPLabel*)  Mtolua_new((myui::HPLabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::HPLabel");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_new00
static int tolua_MyUI_myui_Tree_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Tree* tolua_ret = (myui::Tree*)  Mtolua_new((myui::Tree)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Tree");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_new00_local
static int tolua_MyUI_myui_Tree_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Tree* tolua_ret = (myui::Tree*)  Mtolua_new((myui::Tree)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Tree");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_create00
static int tolua_MyUI_myui_Tree_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
  {
   myui::Tree* tolua_ret = (myui::Tree*)  myui::Tree::create(image);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Tree");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTree of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_addTree00
static int tolua_MyUI_myui_Tree_addTree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  myui::Tree* tree = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTree'",NULL);
#endif
  {
   self->addTree(tree);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_show00
static int tolua_MyUI_myui_Tree_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_visit00
static int tolua_MyUI_myui_Tree_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parent of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_get_myui__Tree_parent_ptr
static int tolua_get_myui__Tree_parent_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->parent,"myui::Tree");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parent of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_set_myui__Tree_parent_ptr
static int tolua_set_myui__Tree_parent_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->parent = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: next of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_get_myui__Tree_next_ptr
static int tolua_get_myui__Tree_next_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->next,"myui::Tree");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: next of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_set_myui__Tree_next_ptr
static int tolua_set_myui__Tree_next_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->next = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: child of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_get_myui__Tree_child_ptr
static int tolua_get_myui__Tree_child_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->child,"myui::Tree");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: child of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_set_myui__Tree_child_ptr
static int tolua_set_myui__Tree_child_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->child = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: image of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_get_myui__Tree_image_ptr
static int tolua_get_myui__Tree_image_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->image,"myui::Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: image of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_set_myui__Tree_image_ptr
static int tolua_set_myui__Tree_image_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isOpen of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_get_myui__Tree_isOpen
static int tolua_get_myui__Tree_isOpen(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isOpen'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isOpen);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isOpen of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_set_myui__Tree_isOpen
static int tolua_set_myui__Tree_isOpen(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isOpen'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isOpen = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_show01
static int tolua_MyUI_myui_Tree_show01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  myui::Tree* tree = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0));
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->show(tree,*point);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI_myui_Tree_show00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_checkIn00
static int tolua_MyUI_myui_Tree_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_doTouch00
static int tolua_MyUI_myui_Tree_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkInTree of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_checkInTree00
static int tolua_MyUI_myui_Tree_checkInTree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
  myui::Tree* tree = ((myui::Tree*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkInTree'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkInTree(touch,tree);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkInTree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchInTree of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_touchInTree00
static int tolua_MyUI_myui_Tree_touchInTree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
  myui::Tree* tree = ((myui::Tree*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchInTree'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchInTree(event,touch,tree);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchInTree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hideCloseNode of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_hideCloseNode00
static int tolua_MyUI_myui_Tree_hideCloseNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  myui::Tree* node = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hideCloseNode'",NULL);
#endif
  {
   self->hideCloseNode(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hideCloseNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_new00
static int tolua_MyUI_myui_List_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::List* tolua_ret = (myui::List*)  Mtolua_new((myui::List)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::List");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_new00_local
static int tolua_MyUI_myui_List_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::List* tolua_ret = (myui::List*)  Mtolua_new((myui::List)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::List");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_create00
static int tolua_MyUI_myui_List_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
  {
   myui::List* tolua_ret = (myui::List*)  myui::List::create(image);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::List");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_create01
static int tolua_MyUI_myui_List_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
  const CCSize* cellSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  {
   myui::List* tolua_ret = (myui::List*)  myui::List::create(image,*cellSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::List");
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI_myui_List_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_remove00
static int tolua_MyUI_myui_List_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  myui::List* list = ((myui::List*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
  {
   self->remove(list);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_add00
static int tolua_MyUI_myui_List_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* list = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
  {
   self->add(list);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_show00
static int tolua_MyUI_myui_List_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: content of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_get_myui__List_content
static int tolua_get_myui__List_content(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'content'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->content,"std::list<myui::Image*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: content of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_set_myui__List_content
static int tolua_set_myui__List_content(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'content'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Image*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->content = *((std::list<myui::Image*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: image of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_get_myui__List_image_ptr
static int tolua_get_myui__List_image_ptr(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->image,"myui::Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: image of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_set_myui__List_image_ptr
static int tolua_set_myui__List_image_ptr(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cellSize of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_get_myui__List_cellSize
static int tolua_get_myui__List_cellSize(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->cellSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cellSize of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_set_myui__List_cellSize
static int tolua_set_myui__List_cellSize(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cellSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_checkIn00
static int tolua_MyUI_myui_List_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_doTouch00
static int tolua_MyUI_myui_List_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImageIndex of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_pickImageIndex00
static int tolua_MyUI_myui_List_pickImageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImageIndex'",NULL);
#endif
  {
   int tolua_ret = (int)  self->pickImageIndex(touch);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImage of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_pickImage00
static int tolua_MyUI_myui_List_pickImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  const int index = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImage'",NULL);
#endif
  {
   myui::Image* tolua_ret = (myui::Image*)  self->pickImage(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Image");
   tolua_pushnumber(tolua_S,(lua_Number)index);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowTouchImage of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_get_myui__List_nowTouchImage_ptr
static int tolua_get_myui__List_nowTouchImage_ptr(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->nowTouchImage,"myui::Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowTouchImage of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_set_myui__List_nowTouchImage_ptr
static int tolua_set_myui__List_nowTouchImage_ptr(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowTouchImage = ((myui::Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: exchageAble of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_get_myui__List_exchageAble
static int tolua_get_myui__List_exchageAble(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->exchageAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: exchageAble of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_set_myui__List_exchageAble
static int tolua_set_myui__List_exchageAble(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->exchageAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_new00
static int tolua_MyUI_myui_Table_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Table* tolua_ret = (myui::Table*)  Mtolua_new((myui::Table)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Table");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_new00_local
static int tolua_MyUI_myui_Table_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Table* tolua_ret = (myui::Table*)  Mtolua_new((myui::Table)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Table");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_create00
static int tolua_MyUI_myui_Table_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Table",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCSize* tableSize = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
  const CCSize* cellSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  {
   myui::Table* tolua_ret = (myui::Table*)  myui::Table::create(*tableSize,*cellSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Table");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: exchageAble of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_get_myui__Table_exchageAble
static int tolua_get_myui__Table_exchageAble(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->exchageAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: exchageAble of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_set_myui__Table_exchageAble
static int tolua_set_myui__Table_exchageAble(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->exchageAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: images of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_get_myui__Table_images
static int tolua_get_myui__Table_images(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'images'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->images,"std::vector<myui::Image*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: images of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_set_myui__Table_images
static int tolua_set_myui__Table_images(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'images'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<myui::Image*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->images = *((std::vector<myui::Image*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_add00
static int tolua_MyUI_myui_Table_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
  {
   self->add(*point,image);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: push of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_push00
static int tolua_MyUI_myui_Table_push00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push'",NULL);
#endif
  {
   self->push(image);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_remove00
static int tolua_MyUI_myui_Table_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
  {
   self->remove(image);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_checkIn00
static int tolua_MyUI_myui_Table_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_doTouch00
static int tolua_MyUI_myui_Table_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImageIndex of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_pickImageIndex00
static int tolua_MyUI_myui_Table_pickImageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImageIndex'",NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->pickImageIndex(touch);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImage of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_pickImage00
static int tolua_MyUI_myui_Table_pickImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImage'",NULL);
#endif
  {
   myui::Image* tolua_ret = (myui::Image*)  self->pickImage(*point);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Image");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_show00
static int tolua_MyUI_myui_Table_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tableSize of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_get_myui__Table_tableSize
static int tolua_get_myui__Table_tableSize(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tableSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->tableSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tableSize of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_set_myui__Table_tableSize
static int tolua_set_myui__Table_tableSize(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tableSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tableSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cellSize of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_get_myui__Table_cellSize
static int tolua_get_myui__Table_cellSize(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->cellSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cellSize of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_set_myui__Table_cellSize
static int tolua_set_myui__Table_cellSize(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cellSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowTouchImage of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_get_myui__Table_nowTouchImage_ptr
static int tolua_get_myui__Table_nowTouchImage_ptr(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->nowTouchImage,"myui::Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowTouchImage of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_set_myui__Table_nowTouchImage_ptr
static int tolua_set_myui__Table_nowTouchImage_ptr(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowTouchImage = ((myui::Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_visit00
static int tolua_MyUI_myui_Table_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doExchange of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_doExchange00
static int tolua_MyUI_myui_Table_doExchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* src = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
  myui::Image* dest = ((myui::Image*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doExchange'",NULL);
#endif
  {
   self->doExchange(src,dest);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doExchange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeIndex of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_removeIndex00
static int tolua_MyUI_myui_Table_removeIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* src = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeIndex'",NULL);
#endif
  {
   self->removeIndex(src);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_create00
static int tolua_MyUI_myui_ScrollView_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   myui::ScrollView* tolua_ret = (myui::ScrollView*)  myui::ScrollView::create(width,height);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::ScrollView");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_init00
static int tolua_MyUI_myui_ScrollView_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(width,height);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_add00
static int tolua_MyUI_myui_ScrollView_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* base = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
  {
   self->add(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_visit00
static int tolua_MyUI_myui_ScrollView_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_myui__ScrollView_width
static int tolua_get_myui__ScrollView_width(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_myui__ScrollView_width
static int tolua_set_myui__ScrollView_width(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_myui__ScrollView_height
static int tolua_get_myui__ScrollView_height(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_myui__ScrollView_height
static int tolua_set_myui__ScrollView_height(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_new00
static int tolua_MyUI_myui_ScrollView_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::ScrollView* tolua_ret = (myui::ScrollView*)  Mtolua_new((myui::ScrollView)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::ScrollView");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_new00_local
static int tolua_MyUI_myui_ScrollView_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::ScrollView* tolua_ret = (myui::ScrollView*)  Mtolua_new((myui::ScrollView)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::ScrollView");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eachTap of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_myui__ScrollView_eachTap
static int tolua_get_myui__ScrollView_eachTap(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eachTap'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->eachTap,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: eachTap of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_myui__ScrollView_eachTap
static int tolua_set_myui__ScrollView_eachTap(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eachTap'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->eachTap = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollType of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_myui__ScrollView_scrollType
static int tolua_get_myui__ScrollView_scrollType(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->scrollType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scrollType of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_myui__ScrollView_scrollType
static int tolua_set_myui__ScrollView_scrollType(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scrollType = ((myui::ScrollView::SCROLL_TYPE) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEachTap of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_setEachTap00
static int tolua_MyUI_myui_ScrollView_setEachTap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  const CCSize eachTap = *((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEachTap'",NULL);
#endif
  {
   self->setEachTap(eachTap);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEachTap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScrollType of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_setScrollType00
static int tolua_MyUI_myui_ScrollView_setScrollType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  myui::ScrollView::SCROLL_TYPE scrollType = ((myui::ScrollView::SCROLL_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScrollType'",NULL);
#endif
  {
   self->setScrollType(scrollType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScrollType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: child of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_myui__ScrollView_child_ptr
static int tolua_get_myui__ScrollView_child_ptr(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->child,"myui::Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: child of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_myui__ScrollView_child_ptr
static int tolua_set_myui__ScrollView_child_ptr(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->child = ((myui::Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_checkIn00
static int tolua_MyUI_myui_ScrollView_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_doTouch00
static int tolua_MyUI_myui_ScrollView_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_create00
static int tolua_MyUI_myui_Window_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Window* tolua_ret = (myui::Window*)  myui::Window::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Window");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_init00
static int tolua_MyUI_myui_Window_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesBegan of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_ccTouchesBegan00
static int tolua_MyUI_myui_Window_ccTouchesBegan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cocos2d::CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"cocos2d::CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::CCSet* pTouches = ((cocos2d::CCSet*)  tolua_tousertype(tolua_S,2,0));
  cocos2d::CCEvent* pEvent = ((cocos2d::CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesBegan'",NULL);
#endif
  {
   self->ccTouchesBegan(pTouches,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesBegan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesMoved of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_ccTouchesMoved00
static int tolua_MyUI_myui_Window_ccTouchesMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cocos2d::CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"cocos2d::CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::CCSet* pTouch = ((cocos2d::CCSet*)  tolua_tousertype(tolua_S,2,0));
  cocos2d::CCEvent* pEvent = ((cocos2d::CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesMoved'",NULL);
#endif
  {
   self->ccTouchesMoved(pTouch,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesEnded of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_ccTouchesEnded00
static int tolua_MyUI_myui_Window_ccTouchesEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cocos2d::CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"cocos2d::CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::CCSet* pTouch = ((cocos2d::CCSet*)  tolua_tousertype(tolua_S,2,0));
  cocos2d::CCEvent* pEvent = ((cocos2d::CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesEnded'",NULL);
#endif
  {
   self->ccTouchesEnded(pTouch,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: uis of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_get_myui__Window_uis
static int tolua_get_myui__Window_uis(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uis'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->uis,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uis of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_set_myui__Window_uis
static int tolua_set_myui__Window_uis(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uis'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->uis = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: actives of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_get_myui__Window_actives
static int tolua_get_myui__Window_actives(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actives'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->actives,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: actives of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_set_myui__Window_actives
static int tolua_set_myui__Window_actives(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actives'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->actives = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: firsts of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_get_myui__Window_firsts
static int tolua_get_myui__Window_firsts(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firsts'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->firsts,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: firsts of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_set_myui__Window_firsts
static int tolua_set_myui__Window_firsts(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firsts'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->firsts = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: addUI of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_addUI00
static int tolua_MyUI_myui_Window_addUI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addUI'",NULL);
#endif
  {
   self->addUI(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_visit00
static int tolua_MyUI_myui_Window_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWindowSize of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_getWindowSize00
static int tolua_MyUI_myui_Window_getWindowSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCSize tolua_ret = (CCSize)  myui::Window::getWindowSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWindowSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoint of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_getPoint00
static int tolua_MyUI_myui_Window_getPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::AlignType alignType = ((myui::AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
  {
   CCPoint tolua_ret = (CCPoint)  myui::Window::getPoint(alignType,*splitSize,*gridLocation);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_MyUI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
  tolua_variable(tolua_S,"USING_NS_CC",tolua_get_USING_NS_CC,tolua_set_USING_NS_CC);
  tolua_module(tolua_S,"myui",0);
  tolua_beginmodule(tolua_S,"myui");
   tolua_constant(tolua_S,"TOUCH_DOWN",myui::TOUCH_DOWN);
   tolua_constant(tolua_S,"TOUCH_MOVE",myui::TOUCH_MOVE);
   tolua_constant(tolua_S,"TOUCH_END",myui::TOUCH_END);
   tolua_constant(tolua_S,"ALIGN_LEFT",myui::ALIGN_LEFT);
   tolua_constant(tolua_S,"ALIGN_RIGHT",myui::ALIGN_RIGHT);
   tolua_constant(tolua_S,"ALIGN_UP",myui::ALIGN_UP);
   tolua_constant(tolua_S,"ALIGN_BOTTOM",myui::ALIGN_BOTTOM);
   tolua_constant(tolua_S,"ALIGN_CENTER",myui::ALIGN_CENTER);
   tolua_constant(tolua_S,"FIT_SELF",myui::FIT_SELF);
   tolua_constant(tolua_S,"FIT_GRID",myui::FIT_GRID);
   tolua_cclass(tolua_S,"Panel","myui::Panel","myui::Image",NULL);
   tolua_beginmodule(tolua_S,"Panel");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Panel_create00);
    tolua_variable(tolua_S,"uis",tolua_get_myui__Panel_uis,tolua_set_myui__Panel_uis);
    tolua_variable(tolua_S,"actives",tolua_get_myui__Panel_actives,tolua_set_myui__Panel_actives);
    tolua_variable(tolua_S,"firsts",tolua_get_myui__Panel_firsts,tolua_set_myui__Panel_firsts);
    tolua_function(tolua_S,"attachTouch",tolua_MyUI_myui_Panel_attachTouch00);
    tolua_function(tolua_S,"addUI",tolua_MyUI_myui_Panel_addUI00);
    tolua_function(tolua_S,"visit",tolua_MyUI_myui_Panel_visit00);
    tolua_function(tolua_S,"setLocation",tolua_MyUI_myui_Panel_setLocation00);
    tolua_function(tolua_S,"setSize",tolua_MyUI_myui_Panel_setSize00);
    tolua_variable(tolua_S,"rect",tolua_get_myui__Panel_rect,tolua_set_myui__Panel_rect);
    tolua_function(tolua_S,"getSize",tolua_MyUI_myui_Panel_getSize00);
    tolua_function(tolua_S,"getPoint",tolua_MyUI_myui_Panel_getPoint00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Base","myui::Base","CCNodeRGBA",tolua_collect_myui__Base);
   #else
   tolua_cclass(tolua_S,"Base","myui::Base","CCNodeRGBA",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Base");
    tolua_function(tolua_S,"new",tolua_MyUI_myui_Base_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_Base_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_Base_new00_local);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Base_checkIn00);
    tolua_function(tolua_S,"bindTouchHandle",tolua_MyUI_myui_Base_bindTouchHandle00);
    tolua_function(tolua_S,"setMoveable",tolua_MyUI_myui_Base_setMoveable00);
    tolua_function(tolua_S,"attachTouch",tolua_MyUI_myui_Base_attachTouch00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Base_doTouch00);
    tolua_variable(tolua_S,"touch",tolua_get_myui__Base_touch_ptr,tolua_set_myui__Base_touch_ptr);
    tolua_variable(tolua_S,"nowTouchPoint",tolua_get_myui__Base_nowTouchPoint,tolua_set_myui__Base_nowTouchPoint);
    tolua_variable(tolua_S,"isActive",tolua_get_myui__Base_isActive,tolua_set_myui__Base_isActive);
    tolua_variable(tolua_S,"moveAble",tolua_get_myui__Base_moveAble,tolua_set_myui__Base_moveAble);
    tolua_variable(tolua_S,"panel",tolua_get_myui__Base_panel_ptr,tolua_set_myui__Base_panel_ptr);
    tolua_variable(tolua_S,"parent",tolua_get_myui__Base_parent_ptr,tolua_set_myui__Base_parent_ptr);
    tolua_function(tolua_S,"setLocation",tolua_MyUI_myui_Base_setLocation00);
    tolua_function(tolua_S,"setInView",tolua_MyUI_myui_Base_setInView00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"TouchHandle","myui::TouchHandle","CCObject",NULL);
   tolua_beginmodule(tolua_S,"TouchHandle");
    tolua_function(tolua_S,"handleDown",tolua_MyUI_myui_TouchHandle_handleDown00);
    tolua_function(tolua_S,"handleMove",tolua_MyUI_myui_TouchHandle_handleMove00);
    tolua_function(tolua_S,"handleEnd",tolua_MyUI_myui_TouchHandle_handleEnd00);
    tolua_function(tolua_S,"handleClick",tolua_MyUI_myui_TouchHandle_handleClick00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Image","myui::Image","myui::Base",tolua_collect_myui__Image);
   #else
   tolua_cclass(tolua_S,"Image","myui::Image","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Image");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Image_create00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Image_checkIn00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Image_checkIn01);
    tolua_variable(tolua_S,"pngName",tolua_get_myui__Image_pngName,tolua_set_myui__Image_pngName);
    tolua_variable(tolua_S,"outlinePngName",tolua_get_myui__Image_outlinePngName,tolua_set_myui__Image_outlinePngName);
    tolua_function(tolua_S,"setOutLine",tolua_MyUI_myui_Image_setOutLine00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Image_doTouch00);
    tolua_variable(tolua_S,"sprite",tolua_get_myui__Image_sprite_ptr,tolua_set_myui__Image_sprite_ptr);
    tolua_function(tolua_S,"show",tolua_MyUI_myui_Image_show00);
    tolua_function(tolua_S,"replacePng",tolua_MyUI_myui_Image_replacePng00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Image_checkIn02);
    tolua_function(tolua_S,"checkInRect",tolua_MyUI_myui_Image_checkInRect00);
    tolua_function(tolua_S,"createImage",tolua_MyUI_myui_Image_createImage00);
    tolua_function(tolua_S,"delete",tolua_MyUI_myui_Image_delete00);
    tolua_function(tolua_S,"new",tolua_MyUI_myui_Image_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_Image_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_Image_new00_local);
    tolua_variable(tolua_S,"image",tolua_get_myui__Image_image_ptr,tolua_set_myui__Image_image_ptr);
    tolua_function(tolua_S,"runAction",tolua_MyUI_myui_Image_runAction00);
    tolua_function(tolua_S,"getViewSize",tolua_MyUI_myui_Image_getViewSize00);
    tolua_variable(tolua_S,"imageSize",tolua_get_myui__Image_imageSize,tolua_set_myui__Image_imageSize);
    tolua_function(tolua_S,"setsize",tolua_MyUI_myui_Image_setsize00);
    tolua_function(tolua_S,"setInView",tolua_MyUI_myui_Image_setInView00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Button","myui::Button","myui::Image",NULL);
   tolua_beginmodule(tolua_S,"Button");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Button_create00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Button_doTouch00);
    tolua_variable(tolua_S,"upName",tolua_get_myui__Button_upName,tolua_set_myui__Button_upName);
    tolua_variable(tolua_S,"downName",tolua_get_myui__Button_downName,tolua_set_myui__Button_downName);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Choice","myui::Choice","myui::Image",NULL);
   tolua_beginmodule(tolua_S,"Choice");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Choice_create00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Choice_doTouch00);
    tolua_variable(tolua_S,"upName",tolua_get_myui__Choice_upName,tolua_set_myui__Choice_upName);
    tolua_variable(tolua_S,"downName",tolua_get_myui__Choice_downName,tolua_set_myui__Choice_downName);
    tolua_variable(tolua_S,"choiceAble",tolua_get_myui__Choice_choiceAble,tolua_set_myui__Choice_choiceAble);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Bubble","myui::Bubble","myui::Choice",NULL);
   tolua_beginmodule(tolua_S,"Bubble");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Bubble_create00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Bubble_doTouch00);
    tolua_variable(tolua_S,"upName",tolua_get_myui__Bubble_upName,tolua_set_myui__Bubble_upName);
    tolua_variable(tolua_S,"downName",tolua_get_myui__Bubble_downName,tolua_set_myui__Bubble_downName);
    tolua_function(tolua_S,"popUp",tolua_MyUI_myui_Bubble_popUp00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Slider","myui::Slider","myui::Image",tolua_collect_myui__Slider);
   #else
   tolua_cclass(tolua_S,"Slider","myui::Slider","myui::Image",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Slider");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Slider_create00);
    tolua_function(tolua_S,"init",tolua_MyUI_myui_Slider_init00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Slider_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Slider_doTouch00);
    tolua_variable(tolua_S,"backSprite",tolua_get_myui__Slider_backSprite_ptr,tolua_set_myui__Slider_backSprite_ptr);
    tolua_variable(tolua_S,"sliderSprite",tolua_get_myui__Slider_sliderSprite_ptr,tolua_set_myui__Slider_sliderSprite_ptr);
    tolua_function(tolua_S,"getValue",tolua_MyUI_myui_Slider_getValue00);
    tolua_function(tolua_S,"setValue",tolua_MyUI_myui_Slider_setValue00);
    tolua_variable(tolua_S,"value",tolua_get_myui__Slider_value,tolua_set_myui__Slider_value);
    tolua_function(tolua_S,"new",tolua_MyUI_myui_Slider_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_Slider_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_Slider_new00_local);
    tolua_function(tolua_S,"getMaxValue",tolua_MyUI_myui_Slider_getMaxValue00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Label","myui::Label","myui::Base",NULL);
   tolua_beginmodule(tolua_S,"Label");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Label_create00);
    tolua_function(tolua_S,"init",tolua_MyUI_myui_Label_init00);
    tolua_function(tolua_S,"getArgs",tolua_MyUI_myui_Label_getArgs00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Label_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Label_doTouch00);
    tolua_variable(tolua_S,"rect",tolua_get_myui__Label_rect,tolua_set_myui__Label_rect);
    tolua_function(tolua_S,"setNumber",tolua_MyUI_myui_Label_setNumber00);
    tolua_function(tolua_S,"getNumber",tolua_MyUI_myui_Label_getNumber00);
    tolua_variable(tolua_S,"numbers",tolua_get_myui__Label_numbers,tolua_set_myui__Label_numbers);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"HPLabel","myui::HPLabel","myui::Base",tolua_collect_myui__HPLabel);
   #else
   tolua_cclass(tolua_S,"HPLabel","myui::HPLabel","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"HPLabel");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_HPLabel_create00);
    tolua_function(tolua_S,"init",tolua_MyUI_myui_HPLabel_init00);
    tolua_function(tolua_S,"setValue",tolua_MyUI_myui_HPLabel_setValue00);
    tolua_variable(tolua_S,"viewSize",tolua_get_myui__HPLabel_viewSize,tolua_set_myui__HPLabel_viewSize);
    tolua_variable(tolua_S,"maxValue",tolua_get_myui__HPLabel_maxValue,tolua_set_myui__HPLabel_maxValue);
    tolua_variable(tolua_S,"value",tolua_get_myui__HPLabel_value,tolua_set_myui__HPLabel_value);
    tolua_variable(tolua_S,"backSprite",tolua_get_myui__HPLabel_backSprite_ptr,tolua_set_myui__HPLabel_backSprite_ptr);
    tolua_variable(tolua_S,"valueSprite",tolua_get_myui__HPLabel_valueSprite_ptr,tolua_set_myui__HPLabel_valueSprite_ptr);
    tolua_function(tolua_S,"new",tolua_MyUI_myui_HPLabel_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_HPLabel_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_HPLabel_new00_local);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Tree","myui::Tree","myui::Base",tolua_collect_myui__Tree);
   #else
   tolua_cclass(tolua_S,"Tree","myui::Tree","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Tree");
    tolua_function(tolua_S,"new",tolua_MyUI_myui_Tree_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_Tree_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_Tree_new00_local);
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Tree_create00);
    tolua_function(tolua_S,"addTree",tolua_MyUI_myui_Tree_addTree00);
    tolua_function(tolua_S,"show",tolua_MyUI_myui_Tree_show00);
    tolua_function(tolua_S,"visit",tolua_MyUI_myui_Tree_visit00);
    tolua_variable(tolua_S,"parent",tolua_get_myui__Tree_parent_ptr,tolua_set_myui__Tree_parent_ptr);
    tolua_variable(tolua_S,"next",tolua_get_myui__Tree_next_ptr,tolua_set_myui__Tree_next_ptr);
    tolua_variable(tolua_S,"child",tolua_get_myui__Tree_child_ptr,tolua_set_myui__Tree_child_ptr);
    tolua_variable(tolua_S,"image",tolua_get_myui__Tree_image_ptr,tolua_set_myui__Tree_image_ptr);
    tolua_variable(tolua_S,"isOpen",tolua_get_myui__Tree_isOpen,tolua_set_myui__Tree_isOpen);
    tolua_function(tolua_S,"show",tolua_MyUI_myui_Tree_show01);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Tree_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Tree_doTouch00);
    tolua_function(tolua_S,"checkInTree",tolua_MyUI_myui_Tree_checkInTree00);
    tolua_function(tolua_S,"touchInTree",tolua_MyUI_myui_Tree_touchInTree00);
    tolua_function(tolua_S,"hideCloseNode",tolua_MyUI_myui_Tree_hideCloseNode00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"List","myui::List","myui::Base",tolua_collect_myui__List);
   #else
   tolua_cclass(tolua_S,"List","myui::List","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"List");
    tolua_function(tolua_S,"new",tolua_MyUI_myui_List_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_List_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_List_new00_local);
    tolua_function(tolua_S,"create",tolua_MyUI_myui_List_create00);
    tolua_function(tolua_S,"create",tolua_MyUI_myui_List_create01);
    tolua_function(tolua_S,"remove",tolua_MyUI_myui_List_remove00);
    tolua_function(tolua_S,"add",tolua_MyUI_myui_List_add00);
    tolua_function(tolua_S,"show",tolua_MyUI_myui_List_show00);
    tolua_variable(tolua_S,"content",tolua_get_myui__List_content,tolua_set_myui__List_content);
    tolua_variable(tolua_S,"image",tolua_get_myui__List_image_ptr,tolua_set_myui__List_image_ptr);
    tolua_variable(tolua_S,"cellSize",tolua_get_myui__List_cellSize,tolua_set_myui__List_cellSize);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_List_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_List_doTouch00);
    tolua_function(tolua_S,"pickImageIndex",tolua_MyUI_myui_List_pickImageIndex00);
    tolua_function(tolua_S,"pickImage",tolua_MyUI_myui_List_pickImage00);
    tolua_variable(tolua_S,"nowTouchImage",tolua_get_myui__List_nowTouchImage_ptr,tolua_set_myui__List_nowTouchImage_ptr);
    tolua_variable(tolua_S,"exchageAble",tolua_get_myui__List_exchageAble,tolua_set_myui__List_exchageAble);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Table","myui::Table","myui::Base",tolua_collect_myui__Table);
   #else
   tolua_cclass(tolua_S,"Table","myui::Table","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Table");
    tolua_function(tolua_S,"new",tolua_MyUI_myui_Table_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_Table_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_Table_new00_local);
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Table_create00);
    tolua_variable(tolua_S,"exchageAble",tolua_get_myui__Table_exchageAble,tolua_set_myui__Table_exchageAble);
    tolua_variable(tolua_S,"images",tolua_get_myui__Table_images,tolua_set_myui__Table_images);
    tolua_function(tolua_S,"add",tolua_MyUI_myui_Table_add00);
    tolua_function(tolua_S,"push",tolua_MyUI_myui_Table_push00);
    tolua_function(tolua_S,"remove",tolua_MyUI_myui_Table_remove00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Table_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Table_doTouch00);
    tolua_function(tolua_S,"pickImageIndex",tolua_MyUI_myui_Table_pickImageIndex00);
    tolua_function(tolua_S,"pickImage",tolua_MyUI_myui_Table_pickImage00);
    tolua_function(tolua_S,"show",tolua_MyUI_myui_Table_show00);
    tolua_variable(tolua_S,"tableSize",tolua_get_myui__Table_tableSize,tolua_set_myui__Table_tableSize);
    tolua_variable(tolua_S,"cellSize",tolua_get_myui__Table_cellSize,tolua_set_myui__Table_cellSize);
    tolua_variable(tolua_S,"nowTouchImage",tolua_get_myui__Table_nowTouchImage_ptr,tolua_set_myui__Table_nowTouchImage_ptr);
    tolua_function(tolua_S,"visit",tolua_MyUI_myui_Table_visit00);
    tolua_function(tolua_S,"doExchange",tolua_MyUI_myui_Table_doExchange00);
    tolua_function(tolua_S,"removeIndex",tolua_MyUI_myui_Table_removeIndex00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"ScrollView","myui::ScrollView","myui::Base",tolua_collect_myui__ScrollView);
   #else
   tolua_cclass(tolua_S,"ScrollView","myui::ScrollView","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"ScrollView");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_ScrollView_create00);
    tolua_function(tolua_S,"init",tolua_MyUI_myui_ScrollView_init00);
    tolua_function(tolua_S,"add",tolua_MyUI_myui_ScrollView_add00);
    tolua_function(tolua_S,"visit",tolua_MyUI_myui_ScrollView_visit00);
    tolua_variable(tolua_S,"width",tolua_get_myui__ScrollView_width,tolua_set_myui__ScrollView_width);
    tolua_variable(tolua_S,"height",tolua_get_myui__ScrollView_height,tolua_set_myui__ScrollView_height);
    tolua_function(tolua_S,"new",tolua_MyUI_myui_ScrollView_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_ScrollView_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_ScrollView_new00_local);
    tolua_variable(tolua_S,"eachTap",tolua_get_myui__ScrollView_eachTap,tolua_set_myui__ScrollView_eachTap);
    tolua_constant(tolua_S,"UP_DOWN",myui::ScrollView::UP_DOWN);
    tolua_constant(tolua_S,"LEFT_RIGHT",myui::ScrollView::LEFT_RIGHT);
    tolua_constant(tolua_S,"ALL",myui::ScrollView::ALL);
    tolua_variable(tolua_S,"scrollType",tolua_get_myui__ScrollView_scrollType,tolua_set_myui__ScrollView_scrollType);
    tolua_function(tolua_S,"setEachTap",tolua_MyUI_myui_ScrollView_setEachTap00);
    tolua_function(tolua_S,"setScrollType",tolua_MyUI_myui_ScrollView_setScrollType00);
    tolua_variable(tolua_S,"child",tolua_get_myui__ScrollView_child_ptr,tolua_set_myui__ScrollView_child_ptr);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_ScrollView_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_ScrollView_doTouch00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Window","myui::Window","CCLayer",NULL);
   tolua_beginmodule(tolua_S,"Window");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Window_create00);
    tolua_function(tolua_S,"init",tolua_MyUI_myui_Window_init00);
    tolua_function(tolua_S,"ccTouchesBegan",tolua_MyUI_myui_Window_ccTouchesBegan00);
    tolua_function(tolua_S,"ccTouchesMoved",tolua_MyUI_myui_Window_ccTouchesMoved00);
    tolua_function(tolua_S,"ccTouchesEnded",tolua_MyUI_myui_Window_ccTouchesEnded00);
    tolua_variable(tolua_S,"uis",tolua_get_myui__Window_uis,tolua_set_myui__Window_uis);
    tolua_variable(tolua_S,"actives",tolua_get_myui__Window_actives,tolua_set_myui__Window_actives);
    tolua_variable(tolua_S,"firsts",tolua_get_myui__Window_firsts,tolua_set_myui__Window_firsts);
    tolua_function(tolua_S,"addUI",tolua_MyUI_myui_Window_addUI00);
    tolua_function(tolua_S,"visit",tolua_MyUI_myui_Window_visit00);
    tolua_function(tolua_S,"getWindowSize",tolua_MyUI_myui_Window_getWindowSize00);
    tolua_function(tolua_S,"getPoint",tolua_MyUI_myui_Window_getPoint00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_MyUI (lua_State* tolua_S) {
 return tolua_MyUI_open(tolua_S);
};
#endif

/*
** Lua binding: MyUI
** Generated automatically by tolua++-1.0.92 on 09/22/13 14:50:42.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_MyUI_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_CCPoint (lua_State* tolua_S)
{
 CCPoint* self = (CCPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__ScrollView (lua_State* tolua_S)
{
 myui::ScrollView* self = (myui::ScrollView*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__Tree (lua_State* tolua_S)
{
 myui::Tree* self = (myui::Tree*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__Base (lua_State* tolua_S)
{
 myui::Base* self = (myui::Base*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CCSize (lua_State* tolua_S)
{
 CCSize* self = (CCSize*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__Slider (lua_State* tolua_S)
{
 myui::Slider* self = (myui::Slider*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__Image (lua_State* tolua_S)
{
 myui::Image* self = (myui::Image*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__Table (lua_State* tolua_S)
{
 myui::Table* self = (myui::Table*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__HPLabel (lua_State* tolua_S)
{
 myui::HPLabel* self = (myui::HPLabel*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_myui__List (lua_State* tolua_S)
{
 myui::List* self = (myui::List*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
#ifndef Mtolua_typeid
#define Mtolua_typeid(L,TI,T)
#endif
 tolua_usertype(tolua_S,"CCPoint");
 Mtolua_typeid(tolua_S,typeid(CCPoint), "CCPoint");
 tolua_usertype(tolua_S,"CCLayer");
 Mtolua_typeid(tolua_S,typeid(CCLayer), "CCLayer");
 tolua_usertype(tolua_S,"CCTouch");
 Mtolua_typeid(tolua_S,typeid(CCTouch), "CCTouch");
 tolua_usertype(tolua_S,"myui::List");
 Mtolua_typeid(tolua_S,typeid(myui::List), "myui::List");
 tolua_usertype(tolua_S,"myui::TouchHandle");
 Mtolua_typeid(tolua_S,typeid(myui::TouchHandle), "myui::TouchHandle");
 tolua_usertype(tolua_S,"cocos2d::CCEvent");
 Mtolua_typeid(tolua_S,typeid(cocos2d::CCEvent), "cocos2d::CCEvent");
 tolua_usertype(tolua_S,"myui::Panel");
 Mtolua_typeid(tolua_S,typeid(myui::Panel), "myui::Panel");
 tolua_usertype(tolua_S,"CCNode");
 Mtolua_typeid(tolua_S,typeid(CCNode), "CCNode");
 tolua_usertype(tolua_S,"std::list<myui::Base*>");
 Mtolua_typeid(tolua_S,typeid(std::list<myui::Base*>), "std::list<myui::Base*>");
 tolua_usertype(tolua_S,"CCNodeRGBA");
 Mtolua_typeid(tolua_S,typeid(CCNodeRGBA), "CCNodeRGBA");
 tolua_usertype(tolua_S,"myui::Button");
 Mtolua_typeid(tolua_S,typeid(myui::Button), "myui::Button");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 Mtolua_typeid(tolua_S,typeid(std::vector<std::string>), "std::vector<std::string>");
 tolua_usertype(tolua_S,"std::list<myui::Image*>");
 Mtolua_typeid(tolua_S,typeid(std::list<myui::Image*>), "std::list<myui::Image*>");
 tolua_usertype(tolua_S,"myui::Slider");
 Mtolua_typeid(tolua_S,typeid(myui::Slider), "myui::Slider");
 tolua_usertype(tolua_S,"CCRect");
 Mtolua_typeid(tolua_S,typeid(CCRect), "CCRect");
 tolua_usertype(tolua_S,"myui::Bubble");
 Mtolua_typeid(tolua_S,typeid(myui::Bubble), "myui::Bubble");
 tolua_usertype(tolua_S,"std::vector<CCLabelAtlas*>");
 Mtolua_typeid(tolua_S,typeid(std::vector<CCLabelAtlas*>), "std::vector<CCLabelAtlas*>");
 tolua_usertype(tolua_S,"myui::Label");
 Mtolua_typeid(tolua_S,typeid(myui::Label), "myui::Label");
 tolua_usertype(tolua_S,"CCSize");
 Mtolua_typeid(tolua_S,typeid(CCSize), "CCSize");
 tolua_usertype(tolua_S,"CCAction");
 Mtolua_typeid(tolua_S,typeid(CCAction), "CCAction");
 tolua_usertype(tolua_S,"myui::ScrollView");
 Mtolua_typeid(tolua_S,typeid(myui::ScrollView), "myui::ScrollView");
 tolua_usertype(tolua_S,"myui::Choice");
 Mtolua_typeid(tolua_S,typeid(myui::Choice), "myui::Choice");
 tolua_usertype(tolua_S,"myui::Base");
 Mtolua_typeid(tolua_S,typeid(myui::Base), "myui::Base");
 tolua_usertype(tolua_S,"CCImage");
 Mtolua_typeid(tolua_S,typeid(CCImage), "CCImage");
 tolua_usertype(tolua_S,"myui::Image");
 Mtolua_typeid(tolua_S,typeid(myui::Image), "myui::Image");
 tolua_usertype(tolua_S,"cocos2d::CCSet");
 Mtolua_typeid(tolua_S,typeid(cocos2d::CCSet), "cocos2d::CCSet");
 tolua_usertype(tolua_S,"myui::Tree");
 Mtolua_typeid(tolua_S,typeid(myui::Tree), "myui::Tree");
 tolua_usertype(tolua_S,"myui::Window");
 Mtolua_typeid(tolua_S,typeid(myui::Window), "myui::Window");
 tolua_usertype(tolua_S,"CCSprite");
 Mtolua_typeid(tolua_S,typeid(CCSprite), "CCSprite");
 tolua_usertype(tolua_S,"std::vector<myui::Image*>");
 Mtolua_typeid(tolua_S,typeid(std::vector<myui::Image*>), "std::vector<myui::Image*>");
 tolua_usertype(tolua_S,"myui::Table");
 Mtolua_typeid(tolua_S,typeid(myui::Table), "myui::Table");
 tolua_usertype(tolua_S,"myui::HPLabel");
 Mtolua_typeid(tolua_S,typeid(myui::HPLabel), "myui::HPLabel");
 tolua_usertype(tolua_S,"CCObject");
 Mtolua_typeid(tolua_S,typeid(CCObject), "CCObject");
}

/* method: create of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_create00
static int tolua_MyUI_myui_Panel_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Panel* tolua_ret = (myui::Panel*)  myui::Panel::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Panel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: uis of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_get_myui__Panel_uis
static int tolua_get_myui__Panel_uis(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uis'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->uis,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uis of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_set_myui__Panel_uis
static int tolua_set_myui__Panel_uis(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uis'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->uis = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: actives of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_get_myui__Panel_actives
static int tolua_get_myui__Panel_actives(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actives'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->actives,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: actives of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_set_myui__Panel_actives
static int tolua_set_myui__Panel_actives(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actives'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->actives = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: firsts of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_get_myui__Panel_firsts
static int tolua_get_myui__Panel_firsts(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firsts'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->firsts,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: firsts of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_set_myui__Panel_firsts
static int tolua_set_myui__Panel_firsts(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firsts'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->firsts = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachTouch of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_attachTouch00
static int tolua_MyUI_myui_Panel_attachTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->attachTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addUI of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_addUI00
static int tolua_MyUI_myui_Panel_addUI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addUI'",NULL);
#endif
  {
   self->addUI(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_visit00
static int tolua_MyUI_myui_Panel_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLocation of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_setLocation00
static int tolua_MyUI_myui_Panel_setLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
  myui::AlignType alignType = ((myui::AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLocation'",NULL);
#endif
  {
   self->setLocation(alignType,*splitSize,*gridLocation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSize of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_setSize00
static int tolua_MyUI_myui_Panel_setSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSize'",NULL);
#endif
  {
   self->setSize(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rect of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_get_myui__Panel_rect
static int tolua_get_myui__Panel_rect(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->rect,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rect of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_set_myui__Panel_rect
static int tolua_set_myui__Panel_rect(lua_State* tolua_S)
{
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rect = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getSize of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_getSize00
static int tolua_MyUI_myui_Panel_getSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getSize'",NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoint of class  myui::Panel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Panel_getPoint00
static int tolua_MyUI_myui_Panel_getPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Panel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Panel* self = (myui::Panel*)  tolua_tousertype(tolua_S,1,0);
  myui::AlignType alignType = ((myui::AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPoint'",NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->getPoint(alignType,*splitSize,*gridLocation);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_new00
static int tolua_MyUI_myui_Base_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Base* tolua_ret = (myui::Base*)  Mtolua_new((myui::Base)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Base");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_new00_local
static int tolua_MyUI_myui_Base_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Base* tolua_ret = (myui::Base*)  Mtolua_new((myui::Base)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Base");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_checkIn00
static int tolua_MyUI_myui_Base_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bindTouchHandle of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_bindTouchHandle00
static int tolua_MyUI_myui_Base_bindTouchHandle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::TouchHandle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchHandle* touchHandle = ((myui::TouchHandle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'bindTouchHandle'",NULL);
#endif
  {
   self->bindTouchHandle(touchHandle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bindTouchHandle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setMoveable of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_setMoveable00
static int tolua_MyUI_myui_Base_setMoveable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  bool moveableTag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setMoveable'",NULL);
#endif
  {
   self->setMoveable(moveableTag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setMoveable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attachTouch of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_attachTouch00
static int tolua_MyUI_myui_Base_attachTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attachTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->attachTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attachTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_doTouch00
static int tolua_MyUI_myui_Base_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: touch of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_touch_ptr
static int tolua_get_myui__Base_touch_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'touch'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->touch,"CCTouch");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: touch of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_touch_ptr
static int tolua_set_myui__Base_touch_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'touch'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowTouchPoint of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_nowTouchPoint
static int tolua_get_myui__Base_nowTouchPoint(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchPoint'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->nowTouchPoint,"CCPoint");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowTouchPoint of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_nowTouchPoint
static int tolua_set_myui__Base_nowTouchPoint(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchPoint'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowTouchPoint = *((CCPoint*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isActive of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_isActive
static int tolua_get_myui__Base_isActive(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isActive'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isActive);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isActive of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_isActive
static int tolua_set_myui__Base_isActive(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isActive'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isActive = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: moveAble of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_moveAble
static int tolua_get_myui__Base_moveAble(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moveAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->moveAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: moveAble of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_moveAble
static int tolua_set_myui__Base_moveAble(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'moveAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->moveAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: panel of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_panel_ptr
static int tolua_get_myui__Base_panel_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'panel'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->panel,"myui::Panel");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: panel of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_panel_ptr
static int tolua_set_myui__Base_panel_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'panel'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Panel",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->panel = ((myui::Panel*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parent of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_get_myui__Base_parent_ptr
static int tolua_get_myui__Base_parent_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->parent,"CCNode");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parent of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_set_myui__Base_parent_ptr
static int tolua_set_myui__Base_parent_ptr(lua_State* tolua_S)
{
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->parent = ((CCNode*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLocation of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_setLocation00
static int tolua_MyUI_myui_Base_setLocation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  myui::AlignType alignType = ((myui::AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLocation'",NULL);
#endif
  {
   self->setLocation(alignType,*splitSize,*gridLocation);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLocation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInView of class  myui::Base */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Base_setInView00
static int tolua_MyUI_myui_Base_setInView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Base",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Base* self = (myui::Base*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInView'",NULL);
#endif
  {
   self->setInView(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleDown of class  myui::TouchHandle */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_TouchHandle_handleDown00
static int tolua_MyUI_myui_TouchHandle_handleDown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::TouchHandle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::TouchHandle* self = (myui::TouchHandle*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleDown'",NULL);
#endif
  {
   self->handleDown(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handleDown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleMove of class  myui::TouchHandle */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_TouchHandle_handleMove00
static int tolua_MyUI_myui_TouchHandle_handleMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::TouchHandle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::TouchHandle* self = (myui::TouchHandle*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleMove'",NULL);
#endif
  {
   self->handleMove(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handleMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleEnd of class  myui::TouchHandle */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_TouchHandle_handleEnd00
static int tolua_MyUI_myui_TouchHandle_handleEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::TouchHandle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::TouchHandle* self = (myui::TouchHandle*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleEnd'",NULL);
#endif
  {
   self->handleEnd(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handleEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: handleClick of class  myui::TouchHandle */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_TouchHandle_handleClick00
static int tolua_MyUI_myui_TouchHandle_handleClick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::TouchHandle",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::TouchHandle* self = (myui::TouchHandle*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'handleClick'",NULL);
#endif
  {
   self->handleClick(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'handleClick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_create00
static int tolua_MyUI_myui_Image_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* pngName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   myui::Image* tolua_ret = (myui::Image*)  myui::Image::create(pngName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Image");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_checkIn00
static int tolua_MyUI_myui_Image_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_checkIn01
static int tolua_MyUI_myui_Image_checkIn01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(*point);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI_myui_Image_checkIn00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pngName of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_get_myui__Image_pngName
static int tolua_get_myui__Image_pngName(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pngName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->pngName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pngName of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_set_myui__Image_pngName
static int tolua_set_myui__Image_pngName(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pngName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pngName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: outlinePngName of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_get_myui__Image_outlinePngName
static int tolua_get_myui__Image_outlinePngName(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outlinePngName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->outlinePngName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: outlinePngName of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_set_myui__Image_outlinePngName
static int tolua_set_myui__Image_outlinePngName(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'outlinePngName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->outlinePngName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOutLine of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_setOutLine00
static int tolua_MyUI_myui_Image_setOutLine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const char* pngName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOutLine'",NULL);
#endif
  {
   self->setOutLine(pngName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOutLine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_doTouch00
static int tolua_MyUI_myui_Image_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sprite of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_get_myui__Image_sprite_ptr
static int tolua_get_myui__Image_sprite_ptr(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->sprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sprite of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_set_myui__Image_sprite_ptr
static int tolua_set_myui__Image_sprite_ptr(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_show00
static int tolua_MyUI_myui_Image_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: replacePng of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_replacePng00
static int tolua_MyUI_myui_Image_replacePng00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'replacePng'",NULL);
#endif
  {
   self->replacePng(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'replacePng'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_checkIn02
static int tolua_MyUI_myui_Image_checkIn02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint point = *((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* sprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
  const char* fileName = ((const char*)  tolua_tostring(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(point,sprite,fileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI_myui_Image_checkIn01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkInRect of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_checkInRect00
static int tolua_MyUI_myui_Image_checkInRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"CCSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint point = *((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  CCSprite* sprite = ((CCSprite*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkInRect'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkInRect(point,sprite);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkInRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createImage of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_createImage00
static int tolua_MyUI_myui_Image_createImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const char* fileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  CCImage* image = ((CCImage*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'createImage'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->createImage(fileName,image);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
    tolua_pushusertype(tolua_S,(void*)image,"CCImage");
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_delete00
static int tolua_MyUI_myui_Image_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'",NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_new00
static int tolua_MyUI_myui_Image_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Image* tolua_ret = (myui::Image*)  Mtolua_new((myui::Image)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Image");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_new00_local
static int tolua_MyUI_myui_Image_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Image* tolua_ret = (myui::Image*)  Mtolua_new((myui::Image)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Image");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: image of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_get_myui__Image_image_ptr
static int tolua_get_myui__Image_image_ptr(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->image,"CCImage");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: image of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_set_myui__Image_image_ptr
static int tolua_set_myui__Image_image_ptr(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCImage",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->image = ((CCImage*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: runAction of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_runAction00
static int tolua_MyUI_myui_Image_runAction00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCAction",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  CCAction* action = ((CCAction*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'runAction'",NULL);
#endif
  {
   self->runAction(action);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'runAction'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewSize of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_getViewSize00
static int tolua_MyUI_myui_Image_getViewSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewSize'",NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getViewSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: imageSize of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_get_myui__Image_imageSize
static int tolua_get_myui__Image_imageSize(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->imageSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: imageSize of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_set_myui__Image_imageSize
static int tolua_set_myui__Image_imageSize(lua_State* tolua_S)
{
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'imageSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->imageSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setsize of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_setsize00
static int tolua_MyUI_myui_Image_setsize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setsize'",NULL);
#endif
  {
   self->setsize(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setsize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setInView of class  myui::Image */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Image_setInView00
static int tolua_MyUI_myui_Image_setInView00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* self = (myui::Image*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setInView'",NULL);
#endif
  {
   self->setInView(*size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setInView'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Button_create00
static int tolua_MyUI_myui_Button_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Button",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   myui::Button* tolua_ret = (myui::Button*)  myui::Button::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Button");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Button_doTouch00
static int tolua_MyUI_myui_Button_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Button",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Button* self = (myui::Button*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: upName of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_get_myui__Button_upName
static int tolua_get_myui__Button_upName(lua_State* tolua_S)
{
  myui::Button* self = (myui::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->upName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: upName of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_set_myui__Button_upName
static int tolua_set_myui__Button_upName(lua_State* tolua_S)
{
  myui::Button* self = (myui::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->upName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: downName of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_get_myui__Button_downName
static int tolua_get_myui__Button_downName(lua_State* tolua_S)
{
  myui::Button* self = (myui::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->downName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: downName of class  myui::Button */
#ifndef TOLUA_DISABLE_tolua_set_myui__Button_downName
static int tolua_set_myui__Button_downName(lua_State* tolua_S)
{
  myui::Button* self = (myui::Button*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->downName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Choice_create00
static int tolua_MyUI_myui_Choice_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Choice",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   myui::Choice* tolua_ret = (myui::Choice*)  myui::Choice::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Choice");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Choice_doTouch00
static int tolua_MyUI_myui_Choice_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Choice",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: upName of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_get_myui__Choice_upName
static int tolua_get_myui__Choice_upName(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->upName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: upName of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_set_myui__Choice_upName
static int tolua_set_myui__Choice_upName(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->upName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: downName of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_get_myui__Choice_downName
static int tolua_get_myui__Choice_downName(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->downName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: downName of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_set_myui__Choice_downName
static int tolua_set_myui__Choice_downName(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->downName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: choiceAble of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_get_myui__Choice_choiceAble
static int tolua_get_myui__Choice_choiceAble(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'choiceAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->choiceAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: choiceAble of class  myui::Choice */
#ifndef TOLUA_DISABLE_tolua_set_myui__Choice_choiceAble
static int tolua_set_myui__Choice_choiceAble(lua_State* tolua_S)
{
  myui::Choice* self = (myui::Choice*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'choiceAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->choiceAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Bubble_create00
static int tolua_MyUI_myui_Bubble_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Bubble",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   myui::Bubble* tolua_ret = (myui::Bubble*)  myui::Bubble::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Bubble");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Bubble_doTouch00
static int tolua_MyUI_myui_Bubble_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Bubble",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: upName of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_get_myui__Bubble_upName
static int tolua_get_myui__Bubble_upName(lua_State* tolua_S)
{
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->upName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: upName of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_set_myui__Bubble_upName
static int tolua_set_myui__Bubble_upName(lua_State* tolua_S)
{
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'upName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->upName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: downName of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_get_myui__Bubble_downName
static int tolua_get_myui__Bubble_downName(lua_State* tolua_S)
{
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->downName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: downName of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_set_myui__Bubble_downName
static int tolua_set_myui__Bubble_downName(lua_State* tolua_S)
{
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'downName'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->downName = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: popUp of class  myui::Bubble */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Bubble_popUp00
static int tolua_MyUI_myui_Bubble_popUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Bubble",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Bubble* self = (myui::Bubble*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'popUp'",NULL);
#endif
  {
   self->popUp();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'popUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_create00
static int tolua_MyUI_myui_Slider_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   myui::Slider* tolua_ret = (myui::Slider*)  myui::Slider::create(upName,downName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Slider");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_init00
static int tolua_MyUI_myui_Slider_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
  const char* upName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* downName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(upName,downName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_checkIn00
static int tolua_MyUI_myui_Slider_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_doTouch00
static int tolua_MyUI_myui_Slider_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: backSprite of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_get_myui__Slider_backSprite_ptr
static int tolua_get_myui__Slider_backSprite_ptr(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->backSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: backSprite of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_set_myui__Slider_backSprite_ptr
static int tolua_set_myui__Slider_backSprite_ptr(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->backSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: sliderSprite of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_get_myui__Slider_sliderSprite_ptr
static int tolua_get_myui__Slider_sliderSprite_ptr(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sliderSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->sliderSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: sliderSprite of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_set_myui__Slider_sliderSprite_ptr
static int tolua_set_myui__Slider_sliderSprite_ptr(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'sliderSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->sliderSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getValue of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_getValue00
static int tolua_MyUI_myui_Slider_getValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getValue'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setValue of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_setValue00
static int tolua_MyUI_myui_Slider_setValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setValue'",NULL);
#endif
  {
   self->setValue(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_get_myui__Slider_value
static int tolua_get_myui__Slider_value(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_set_myui__Slider_value
static int tolua_set_myui__Slider_value(lua_State* tolua_S)
{
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_new00
static int tolua_MyUI_myui_Slider_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Slider* tolua_ret = (myui::Slider*)  Mtolua_new((myui::Slider)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Slider");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_new00_local
static int tolua_MyUI_myui_Slider_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Slider* tolua_ret = (myui::Slider*)  Mtolua_new((myui::Slider)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Slider");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMaxValue of class  myui::Slider */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Slider_getMaxValue00
static int tolua_MyUI_myui_Slider_getMaxValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Slider",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Slider* self = (myui::Slider*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getMaxValue'",NULL);
#endif
  {
   float tolua_ret = (float)  self->getMaxValue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMaxValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_create00
static int tolua_MyUI_myui_Label_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  {
   myui::Label* tolua_ret = (myui::Label*)  myui::Label::create(content,*size);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Label");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_init00
static int tolua_MyUI_myui_Label_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
  const CCSize* size = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(content,*size);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArgs of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_getArgs00
static int tolua_MyUI_myui_Label_getArgs00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"std::vector<std::string>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
  int argc = ((int)  tolua_tonumber(tolua_S,3,0));
  std::vector<std::string>* args = ((std::vector<std::string>*)  tolua_tousertype(tolua_S,4,0));
  {
   const char* tolua_ret = (const char*)  myui::Label::getArgs(content,argc,*args);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArgs'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_checkIn00
static int tolua_MyUI_myui_Label_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_doTouch00
static int tolua_MyUI_myui_Label_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: rect of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_get_myui__Label_rect
static int tolua_get_myui__Label_rect(lua_State* tolua_S)
{
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->rect,"CCRect");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: rect of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_set_myui__Label_rect
static int tolua_set_myui__Label_rect(lua_State* tolua_S)
{
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'rect'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCRect",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->rect = *((CCRect*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNumber of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_setNumber00
static int tolua_MyUI_myui_Label_setNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
  double value = ((double)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNumber'",NULL);
#endif
  {
   self->setNumber(tag,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumber of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Label_getNumber00
static int tolua_MyUI_myui_Label_getNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Label",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
  int tag = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumber'",NULL);
#endif
  {
   double tolua_ret = (double)  self->getNumber(tag);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numbers of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_get_myui__Label_numbers
static int tolua_get_myui__Label_numbers(lua_State* tolua_S)
{
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numbers'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->numbers,"std::vector<CCLabelAtlas*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: numbers of class  myui::Label */
#ifndef TOLUA_DISABLE_tolua_set_myui__Label_numbers
static int tolua_set_myui__Label_numbers(lua_State* tolua_S)
{
  myui::Label* self = (myui::Label*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numbers'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<CCLabelAtlas*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->numbers = *((std::vector<CCLabelAtlas*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_HPLabel_create00
static int tolua_MyUI_myui_HPLabel_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::HPLabel",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* backName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* showName = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   myui::HPLabel* tolua_ret = (myui::HPLabel*)  myui::HPLabel::create(backName,showName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::HPLabel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_HPLabel_init00
static int tolua_MyUI_myui_HPLabel_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::HPLabel",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
  const char* backName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* showName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(backName,showName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setValue of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_HPLabel_setValue00
static int tolua_MyUI_myui_HPLabel_setValue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::HPLabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
  float value = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setValue'",NULL);
#endif
  {
   self->setValue(value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setValue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: viewSize of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_myui__HPLabel_viewSize
static int tolua_get_myui__HPLabel_viewSize(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'viewSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->viewSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: viewSize of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_myui__HPLabel_viewSize
static int tolua_set_myui__HPLabel_viewSize(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'viewSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->viewSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: maxValue of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_myui__HPLabel_maxValue
static int tolua_get_myui__HPLabel_maxValue(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxValue'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->maxValue);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: maxValue of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_myui__HPLabel_maxValue
static int tolua_set_myui__HPLabel_maxValue(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'maxValue'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->maxValue = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: value of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_myui__HPLabel_value
static int tolua_get_myui__HPLabel_value(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->value);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: value of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_myui__HPLabel_value
static int tolua_set_myui__HPLabel_value(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'value'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->value = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: backSprite of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_myui__HPLabel_backSprite_ptr
static int tolua_get_myui__HPLabel_backSprite_ptr(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->backSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: backSprite of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_myui__HPLabel_backSprite_ptr
static int tolua_set_myui__HPLabel_backSprite_ptr(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'backSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->backSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: valueSprite of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_get_myui__HPLabel_valueSprite_ptr
static int tolua_get_myui__HPLabel_valueSprite_ptr(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'valueSprite'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->valueSprite,"CCSprite");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: valueSprite of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_set_myui__HPLabel_valueSprite_ptr
static int tolua_set_myui__HPLabel_valueSprite_ptr(lua_State* tolua_S)
{
  myui::HPLabel* self = (myui::HPLabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'valueSprite'",NULL);
  if (!tolua_isusertype(tolua_S,2,"CCSprite",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->valueSprite = ((CCSprite*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_HPLabel_new00
static int tolua_MyUI_myui_HPLabel_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::HPLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::HPLabel* tolua_ret = (myui::HPLabel*)  Mtolua_new((myui::HPLabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::HPLabel");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::HPLabel */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_HPLabel_new00_local
static int tolua_MyUI_myui_HPLabel_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::HPLabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::HPLabel* tolua_ret = (myui::HPLabel*)  Mtolua_new((myui::HPLabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::HPLabel");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_new00
static int tolua_MyUI_myui_Tree_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Tree* tolua_ret = (myui::Tree*)  Mtolua_new((myui::Tree)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Tree");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_new00_local
static int tolua_MyUI_myui_Tree_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Tree* tolua_ret = (myui::Tree*)  Mtolua_new((myui::Tree)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Tree");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_create00
static int tolua_MyUI_myui_Tree_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
  {
   myui::Tree* tolua_ret = (myui::Tree*)  myui::Tree::create(image);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Tree");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTree of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_addTree00
static int tolua_MyUI_myui_Tree_addTree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  myui::Tree* tree = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTree'",NULL);
#endif
  {
   self->addTree(tree);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_show00
static int tolua_MyUI_myui_Tree_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_visit00
static int tolua_MyUI_myui_Tree_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: parent of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_get_myui__Tree_parent_ptr
static int tolua_get_myui__Tree_parent_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->parent,"myui::Tree");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: parent of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_set_myui__Tree_parent_ptr
static int tolua_set_myui__Tree_parent_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'parent'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->parent = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: next of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_get_myui__Tree_next_ptr
static int tolua_get_myui__Tree_next_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->next,"myui::Tree");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: next of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_set_myui__Tree_next_ptr
static int tolua_set_myui__Tree_next_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'next'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->next = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: child of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_get_myui__Tree_child_ptr
static int tolua_get_myui__Tree_child_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->child,"myui::Tree");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: child of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_set_myui__Tree_child_ptr
static int tolua_set_myui__Tree_child_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->child = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: image of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_get_myui__Tree_image_ptr
static int tolua_get_myui__Tree_image_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->image,"myui::Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: image of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_set_myui__Tree_image_ptr
static int tolua_set_myui__Tree_image_ptr(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isOpen of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_get_myui__Tree_isOpen
static int tolua_get_myui__Tree_isOpen(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isOpen'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isOpen);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isOpen of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_set_myui__Tree_isOpen
static int tolua_set_myui__Tree_isOpen(lua_State* tolua_S)
{
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isOpen'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isOpen = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_show01
static int tolua_MyUI_myui_Tree_show01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  myui::Tree* tree = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0));
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->show(tree,*point);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI_myui_Tree_show00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_checkIn00
static int tolua_MyUI_myui_Tree_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_doTouch00
static int tolua_MyUI_myui_Tree_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkInTree of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_checkInTree00
static int tolua_MyUI_myui_Tree_checkInTree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
  myui::Tree* tree = ((myui::Tree*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkInTree'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkInTree(touch,tree);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkInTree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchInTree of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_touchInTree00
static int tolua_MyUI_myui_Tree_touchInTree00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
  myui::Tree* tree = ((myui::Tree*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchInTree'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->touchInTree(event,touch,tree);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchInTree'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hideCloseNode of class  myui::Tree */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Tree_hideCloseNode00
static int tolua_MyUI_myui_Tree_hideCloseNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Tree",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Tree",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Tree* self = (myui::Tree*)  tolua_tousertype(tolua_S,1,0);
  myui::Tree* node = ((myui::Tree*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'hideCloseNode'",NULL);
#endif
  {
   self->hideCloseNode(node);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hideCloseNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_new00
static int tolua_MyUI_myui_List_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::List* tolua_ret = (myui::List*)  Mtolua_new((myui::List)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::List");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_new00_local
static int tolua_MyUI_myui_List_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::List* tolua_ret = (myui::List*)  Mtolua_new((myui::List)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::List");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_create00
static int tolua_MyUI_myui_List_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
  {
   myui::List* tolua_ret = (myui::List*)  myui::List::create(image);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::List");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_create01
static int tolua_MyUI_myui_List_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
  const CCSize* cellSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  {
   myui::List* tolua_ret = (myui::List*)  myui::List::create(image,*cellSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::List");
  }
 }
 return 1;
tolua_lerror:
 return tolua_MyUI_myui_List_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_remove00
static int tolua_MyUI_myui_List_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  myui::List* list = ((myui::List*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
  {
   self->remove(list);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_add00
static int tolua_MyUI_myui_List_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* list = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
  {
   self->add(list);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_show00
static int tolua_MyUI_myui_List_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: content of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_get_myui__List_content
static int tolua_get_myui__List_content(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'content'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->content,"std::list<myui::Image*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: content of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_set_myui__List_content
static int tolua_set_myui__List_content(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'content'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Image*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->content = *((std::list<myui::Image*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: image of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_get_myui__List_image_ptr
static int tolua_get_myui__List_image_ptr(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->image,"myui::Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: image of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_set_myui__List_image_ptr
static int tolua_set_myui__List_image_ptr(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'image'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cellSize of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_get_myui__List_cellSize
static int tolua_get_myui__List_cellSize(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->cellSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cellSize of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_set_myui__List_cellSize
static int tolua_set_myui__List_cellSize(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cellSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_checkIn00
static int tolua_MyUI_myui_List_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_doTouch00
static int tolua_MyUI_myui_List_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImageIndex of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_pickImageIndex00
static int tolua_MyUI_myui_List_pickImageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImageIndex'",NULL);
#endif
  {
   int tolua_ret = (int)  self->pickImageIndex(touch);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImage of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_List_pickImage00
static int tolua_MyUI_myui_List_pickImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::List",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
  const int index = ((const int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImage'",NULL);
#endif
  {
   myui::Image* tolua_ret = (myui::Image*)  self->pickImage(index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Image");
   tolua_pushnumber(tolua_S,(lua_Number)index);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowTouchImage of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_get_myui__List_nowTouchImage_ptr
static int tolua_get_myui__List_nowTouchImage_ptr(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->nowTouchImage,"myui::Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowTouchImage of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_set_myui__List_nowTouchImage_ptr
static int tolua_set_myui__List_nowTouchImage_ptr(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowTouchImage = ((myui::Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: exchageAble of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_get_myui__List_exchageAble
static int tolua_get_myui__List_exchageAble(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->exchageAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: exchageAble of class  myui::List */
#ifndef TOLUA_DISABLE_tolua_set_myui__List_exchageAble
static int tolua_set_myui__List_exchageAble(lua_State* tolua_S)
{
  myui::List* self = (myui::List*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->exchageAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_new00
static int tolua_MyUI_myui_Table_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Table* tolua_ret = (myui::Table*)  Mtolua_new((myui::Table)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Table");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_new00_local
static int tolua_MyUI_myui_Table_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Table* tolua_ret = (myui::Table*)  Mtolua_new((myui::Table)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Table");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_create00
static int tolua_MyUI_myui_Table_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Table",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const CCSize* tableSize = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
  const CCSize* cellSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  {
   myui::Table* tolua_ret = (myui::Table*)  myui::Table::create(*tableSize,*cellSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Table");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: exchageAble of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_get_myui__Table_exchageAble
static int tolua_get_myui__Table_exchageAble(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->exchageAble);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: exchageAble of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_set_myui__Table_exchageAble
static int tolua_set_myui__Table_exchageAble(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'exchageAble'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->exchageAble = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: images of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_get_myui__Table_images
static int tolua_get_myui__Table_images(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'images'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->images,"std::vector<myui::Image*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: images of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_set_myui__Table_images
static int tolua_set_myui__Table_images(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'images'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::vector<myui::Image*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->images = *((std::vector<myui::Image*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_add00
static int tolua_MyUI_myui_Table_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
  {
   self->add(*point,image);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: push of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_push00
static int tolua_MyUI_myui_Table_push00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'push'",NULL);
#endif
  {
   self->push(image);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: remove of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_remove00
static int tolua_MyUI_myui_Table_remove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* image = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'remove'",NULL);
#endif
  {
   self->remove(image);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'remove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_checkIn00
static int tolua_MyUI_myui_Table_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_doTouch00
static int tolua_MyUI_myui_Table_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImageIndex of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_pickImageIndex00
static int tolua_MyUI_myui_Table_pickImageIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImageIndex'",NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->pickImageIndex(touch);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImageIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pickImage of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_pickImage00
static int tolua_MyUI_myui_Table_pickImage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* point = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pickImage'",NULL);
#endif
  {
   myui::Image* tolua_ret = (myui::Image*)  self->pickImage(*point);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Image");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pickImage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: show of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_show00
static int tolua_MyUI_myui_Table_show00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'show'",NULL);
#endif
  {
   self->show();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'show'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: tableSize of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_get_myui__Table_tableSize
static int tolua_get_myui__Table_tableSize(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tableSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->tableSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: tableSize of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_set_myui__Table_tableSize
static int tolua_set_myui__Table_tableSize(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'tableSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->tableSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: cellSize of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_get_myui__Table_cellSize
static int tolua_get_myui__Table_cellSize(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->cellSize,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: cellSize of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_set_myui__Table_cellSize
static int tolua_set_myui__Table_cellSize(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'cellSize'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->cellSize = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: nowTouchImage of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_get_myui__Table_nowTouchImage_ptr
static int tolua_get_myui__Table_nowTouchImage_ptr(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->nowTouchImage,"myui::Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: nowTouchImage of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_set_myui__Table_nowTouchImage_ptr
static int tolua_set_myui__Table_nowTouchImage_ptr(lua_State* tolua_S)
{
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'nowTouchImage'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->nowTouchImage = ((myui::Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_visit00
static int tolua_MyUI_myui_Table_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doExchange of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_doExchange00
static int tolua_MyUI_myui_Table_doExchange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* src = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
  myui::Image* dest = ((myui::Image*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doExchange'",NULL);
#endif
  {
   self->doExchange(src,dest);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doExchange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeIndex of class  myui::Table */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Table_removeIndex00
static int tolua_MyUI_myui_Table_removeIndex00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Table",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Table* self = (myui::Table*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* src = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeIndex'",NULL);
#endif
  {
   self->removeIndex(src);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeIndex'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_create00
static int tolua_MyUI_myui_ScrollView_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   myui::ScrollView* tolua_ret = (myui::ScrollView*)  myui::ScrollView::create(width,height);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::ScrollView");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_init00
static int tolua_MyUI_myui_ScrollView_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  float width = ((float)  tolua_tonumber(tolua_S,2,0));
  float height = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init(width,height);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_add00
static int tolua_MyUI_myui_ScrollView_add00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  myui::Image* base = ((myui::Image*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'add'",NULL);
#endif
  {
   self->add(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_visit00
static int tolua_MyUI_myui_ScrollView_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: width of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_myui__ScrollView_width
static int tolua_get_myui__ScrollView_width(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->width);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: width of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_myui__ScrollView_width
static int tolua_set_myui__ScrollView_width(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'width'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->width = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: height of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_myui__ScrollView_height
static int tolua_get_myui__ScrollView_height(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->height);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: height of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_myui__ScrollView_height
static int tolua_set_myui__ScrollView_height(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'height'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->height = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_new00
static int tolua_MyUI_myui_ScrollView_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::ScrollView* tolua_ret = (myui::ScrollView*)  Mtolua_new((myui::ScrollView)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::ScrollView");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_new00_local
static int tolua_MyUI_myui_ScrollView_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::ScrollView* tolua_ret = (myui::ScrollView*)  Mtolua_new((myui::ScrollView)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::ScrollView");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: eachTap of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_myui__ScrollView_eachTap
static int tolua_get_myui__ScrollView_eachTap(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eachTap'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->eachTap,"CCSize");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: eachTap of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_myui__ScrollView_eachTap
static int tolua_set_myui__ScrollView_eachTap(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'eachTap'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->eachTap = *((CCSize*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: scrollType of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_myui__ScrollView_scrollType
static int tolua_get_myui__ScrollView_scrollType(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->scrollType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: scrollType of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_myui__ScrollView_scrollType
static int tolua_set_myui__ScrollView_scrollType(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'scrollType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->scrollType = ((myui::ScrollView::SCROLL_TYPE) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: setEachTap of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_setEachTap00
static int tolua_MyUI_myui_ScrollView_setEachTap00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  const CCSize eachTap = *((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setEachTap'",NULL);
#endif
  {
   self->setEachTap(eachTap);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setEachTap'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScrollType of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_setScrollType00
static int tolua_MyUI_myui_ScrollView_setScrollType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  myui::ScrollView::SCROLL_TYPE scrollType = ((myui::ScrollView::SCROLL_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScrollType'",NULL);
#endif
  {
   self->setScrollType(scrollType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScrollType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: child of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_get_myui__ScrollView_child_ptr
static int tolua_get_myui__ScrollView_child_ptr(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->child,"myui::Image");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: child of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_set_myui__ScrollView_child_ptr
static int tolua_set_myui__ScrollView_child_ptr(lua_State* tolua_S)
{
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'child'",NULL);
  if (!tolua_isusertype(tolua_S,2,"myui::Image",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->child = ((myui::Image*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkIn of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_checkIn00
static int tolua_MyUI_myui_ScrollView_checkIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'checkIn'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->checkIn(touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doTouch of class  myui::ScrollView */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_ScrollView_doTouch00
static int tolua_MyUI_myui_ScrollView_doTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::ScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::ScrollView* self = (myui::ScrollView*)  tolua_tousertype(tolua_S,1,0);
  myui::TouchEvent event = ((myui::TouchEvent) (int)  tolua_tonumber(tolua_S,2,0));
  CCTouch* touch = ((CCTouch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doTouch'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->doTouch(event,touch);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_create00
static int tolua_MyUI_myui_Window_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   myui::Window* tolua_ret = (myui::Window*)  myui::Window::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"myui::Window");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_init00
static int tolua_MyUI_myui_Window_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesBegan of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_ccTouchesBegan00
static int tolua_MyUI_myui_Window_ccTouchesBegan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cocos2d::CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"cocos2d::CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::CCSet* pTouches = ((cocos2d::CCSet*)  tolua_tousertype(tolua_S,2,0));
  cocos2d::CCEvent* pEvent = ((cocos2d::CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesBegan'",NULL);
#endif
  {
   self->ccTouchesBegan(pTouches,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesBegan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesMoved of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_ccTouchesMoved00
static int tolua_MyUI_myui_Window_ccTouchesMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cocos2d::CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"cocos2d::CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::CCSet* pTouch = ((cocos2d::CCSet*)  tolua_tousertype(tolua_S,2,0));
  cocos2d::CCEvent* pEvent = ((cocos2d::CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesMoved'",NULL);
#endif
  {
   self->ccTouchesMoved(pTouch,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesEnded of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_ccTouchesEnded00
static int tolua_MyUI_myui_Window_ccTouchesEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"cocos2d::CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"cocos2d::CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::CCSet* pTouch = ((cocos2d::CCSet*)  tolua_tousertype(tolua_S,2,0));
  cocos2d::CCEvent* pEvent = ((cocos2d::CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesEnded'",NULL);
#endif
  {
   self->ccTouchesEnded(pTouch,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: uis of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_get_myui__Window_uis
static int tolua_get_myui__Window_uis(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uis'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->uis,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uis of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_set_myui__Window_uis
static int tolua_set_myui__Window_uis(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uis'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->uis = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: actives of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_get_myui__Window_actives
static int tolua_get_myui__Window_actives(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actives'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->actives,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: actives of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_set_myui__Window_actives
static int tolua_set_myui__Window_actives(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'actives'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->actives = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: firsts of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_get_myui__Window_firsts
static int tolua_get_myui__Window_firsts(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firsts'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->firsts,"std::list<myui::Base*>");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: firsts of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_set_myui__Window_firsts
static int tolua_set_myui__Window_firsts(lua_State* tolua_S)
{
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'firsts'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::list<myui::Base*>",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->firsts = *((std::list<myui::Base*>*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: addUI of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_addUI00
static int tolua_MyUI_myui_Window_addUI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"myui::Base",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
  myui::Base* base = ((myui::Base*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addUI'",NULL);
#endif
  {
   self->addUI(base);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_visit00
static int tolua_MyUI_myui_Window_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::Window* self = (myui::Window*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'",NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getWindowSize of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_getWindowSize00
static int tolua_MyUI_myui_Window_getWindowSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCSize tolua_ret = (CCSize)  myui::Window::getWindowSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getWindowSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPoint of class  myui::Window */
#ifndef TOLUA_DISABLE_tolua_MyUI_myui_Window_getPoint00
static int tolua_MyUI_myui_Window_getPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"myui::Window",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCSize",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  myui::AlignType alignType = ((myui::AlignType) (int)  tolua_tonumber(tolua_S,2,0));
  const CCSize* splitSize = ((const CCSize*)  tolua_tousertype(tolua_S,3,0));
  const CCPoint* gridLocation = ((const CCPoint*)  tolua_tousertype(tolua_S,4,0));
  {
   CCPoint tolua_ret = (CCPoint)  myui::Window::getPoint(alignType,*splitSize,*gridLocation);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_MyUI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"myui",0);
  tolua_beginmodule(tolua_S,"myui");
   tolua_constant(tolua_S,"TOUCH_DOWN",myui::TOUCH_DOWN);
   tolua_constant(tolua_S,"TOUCH_MOVE",myui::TOUCH_MOVE);
   tolua_constant(tolua_S,"TOUCH_END",myui::TOUCH_END);
   tolua_constant(tolua_S,"ALIGN_LEFT",myui::ALIGN_LEFT);
   tolua_constant(tolua_S,"ALIGN_RIGHT",myui::ALIGN_RIGHT);
   tolua_constant(tolua_S,"ALIGN_UP",myui::ALIGN_UP);
   tolua_constant(tolua_S,"ALIGN_BOTTOM",myui::ALIGN_BOTTOM);
   tolua_constant(tolua_S,"ALIGN_CENTER",myui::ALIGN_CENTER);
   tolua_constant(tolua_S,"FIT_SELF",myui::FIT_SELF);
   tolua_constant(tolua_S,"FIT_GRID",myui::FIT_GRID);
   tolua_cclass(tolua_S,"Panel","myui::Panel","myui::Image",NULL);
   tolua_beginmodule(tolua_S,"Panel");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Panel_create00);
    tolua_variable(tolua_S,"uis",tolua_get_myui__Panel_uis,tolua_set_myui__Panel_uis);
    tolua_variable(tolua_S,"actives",tolua_get_myui__Panel_actives,tolua_set_myui__Panel_actives);
    tolua_variable(tolua_S,"firsts",tolua_get_myui__Panel_firsts,tolua_set_myui__Panel_firsts);
    tolua_function(tolua_S,"attachTouch",tolua_MyUI_myui_Panel_attachTouch00);
    tolua_function(tolua_S,"addUI",tolua_MyUI_myui_Panel_addUI00);
    tolua_function(tolua_S,"visit",tolua_MyUI_myui_Panel_visit00);
    tolua_function(tolua_S,"setLocation",tolua_MyUI_myui_Panel_setLocation00);
    tolua_function(tolua_S,"setSize",tolua_MyUI_myui_Panel_setSize00);
    tolua_variable(tolua_S,"rect",tolua_get_myui__Panel_rect,tolua_set_myui__Panel_rect);
    tolua_function(tolua_S,"getSize",tolua_MyUI_myui_Panel_getSize00);
    tolua_function(tolua_S,"getPoint",tolua_MyUI_myui_Panel_getPoint00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Base","myui::Base","CCNodeRGBA",tolua_collect_myui__Base);
   #else
   tolua_cclass(tolua_S,"Base","myui::Base","CCNodeRGBA",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Base");
    tolua_function(tolua_S,"new",tolua_MyUI_myui_Base_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_Base_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_Base_new00_local);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Base_checkIn00);
    tolua_function(tolua_S,"bindTouchHandle",tolua_MyUI_myui_Base_bindTouchHandle00);
    tolua_function(tolua_S,"setMoveable",tolua_MyUI_myui_Base_setMoveable00);
    tolua_function(tolua_S,"attachTouch",tolua_MyUI_myui_Base_attachTouch00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Base_doTouch00);
    tolua_variable(tolua_S,"touch",tolua_get_myui__Base_touch_ptr,tolua_set_myui__Base_touch_ptr);
    tolua_variable(tolua_S,"nowTouchPoint",tolua_get_myui__Base_nowTouchPoint,tolua_set_myui__Base_nowTouchPoint);
    tolua_variable(tolua_S,"isActive",tolua_get_myui__Base_isActive,tolua_set_myui__Base_isActive);
    tolua_variable(tolua_S,"moveAble",tolua_get_myui__Base_moveAble,tolua_set_myui__Base_moveAble);
    tolua_variable(tolua_S,"panel",tolua_get_myui__Base_panel_ptr,tolua_set_myui__Base_panel_ptr);
    tolua_variable(tolua_S,"parent",tolua_get_myui__Base_parent_ptr,tolua_set_myui__Base_parent_ptr);
    tolua_function(tolua_S,"setLocation",tolua_MyUI_myui_Base_setLocation00);
    tolua_function(tolua_S,"setInView",tolua_MyUI_myui_Base_setInView00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"TouchHandle","myui::TouchHandle","CCObject",NULL);
   tolua_beginmodule(tolua_S,"TouchHandle");
    tolua_function(tolua_S,"handleDown",tolua_MyUI_myui_TouchHandle_handleDown00);
    tolua_function(tolua_S,"handleMove",tolua_MyUI_myui_TouchHandle_handleMove00);
    tolua_function(tolua_S,"handleEnd",tolua_MyUI_myui_TouchHandle_handleEnd00);
    tolua_function(tolua_S,"handleClick",tolua_MyUI_myui_TouchHandle_handleClick00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Image","myui::Image","myui::Base",tolua_collect_myui__Image);
   #else
   tolua_cclass(tolua_S,"Image","myui::Image","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Image");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Image_create00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Image_checkIn00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Image_checkIn01);
    tolua_variable(tolua_S,"pngName",tolua_get_myui__Image_pngName,tolua_set_myui__Image_pngName);
    tolua_variable(tolua_S,"outlinePngName",tolua_get_myui__Image_outlinePngName,tolua_set_myui__Image_outlinePngName);
    tolua_function(tolua_S,"setOutLine",tolua_MyUI_myui_Image_setOutLine00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Image_doTouch00);
    tolua_variable(tolua_S,"sprite",tolua_get_myui__Image_sprite_ptr,tolua_set_myui__Image_sprite_ptr);
    tolua_function(tolua_S,"show",tolua_MyUI_myui_Image_show00);
    tolua_function(tolua_S,"replacePng",tolua_MyUI_myui_Image_replacePng00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Image_checkIn02);
    tolua_function(tolua_S,"checkInRect",tolua_MyUI_myui_Image_checkInRect00);
    tolua_function(tolua_S,"createImage",tolua_MyUI_myui_Image_createImage00);
    tolua_function(tolua_S,"delete",tolua_MyUI_myui_Image_delete00);
    tolua_function(tolua_S,"new",tolua_MyUI_myui_Image_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_Image_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_Image_new00_local);
    tolua_variable(tolua_S,"image",tolua_get_myui__Image_image_ptr,tolua_set_myui__Image_image_ptr);
    tolua_function(tolua_S,"runAction",tolua_MyUI_myui_Image_runAction00);
    tolua_function(tolua_S,"getViewSize",tolua_MyUI_myui_Image_getViewSize00);
    tolua_variable(tolua_S,"imageSize",tolua_get_myui__Image_imageSize,tolua_set_myui__Image_imageSize);
    tolua_function(tolua_S,"setsize",tolua_MyUI_myui_Image_setsize00);
    tolua_function(tolua_S,"setInView",tolua_MyUI_myui_Image_setInView00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Button","myui::Button","myui::Image",NULL);
   tolua_beginmodule(tolua_S,"Button");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Button_create00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Button_doTouch00);
    tolua_variable(tolua_S,"upName",tolua_get_myui__Button_upName,tolua_set_myui__Button_upName);
    tolua_variable(tolua_S,"downName",tolua_get_myui__Button_downName,tolua_set_myui__Button_downName);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Choice","myui::Choice","myui::Image",NULL);
   tolua_beginmodule(tolua_S,"Choice");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Choice_create00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Choice_doTouch00);
    tolua_variable(tolua_S,"upName",tolua_get_myui__Choice_upName,tolua_set_myui__Choice_upName);
    tolua_variable(tolua_S,"downName",tolua_get_myui__Choice_downName,tolua_set_myui__Choice_downName);
    tolua_variable(tolua_S,"choiceAble",tolua_get_myui__Choice_choiceAble,tolua_set_myui__Choice_choiceAble);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Bubble","myui::Bubble","myui::Choice",NULL);
   tolua_beginmodule(tolua_S,"Bubble");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Bubble_create00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Bubble_doTouch00);
    tolua_variable(tolua_S,"upName",tolua_get_myui__Bubble_upName,tolua_set_myui__Bubble_upName);
    tolua_variable(tolua_S,"downName",tolua_get_myui__Bubble_downName,tolua_set_myui__Bubble_downName);
    tolua_function(tolua_S,"popUp",tolua_MyUI_myui_Bubble_popUp00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Slider","myui::Slider","myui::Image",tolua_collect_myui__Slider);
   #else
   tolua_cclass(tolua_S,"Slider","myui::Slider","myui::Image",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Slider");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Slider_create00);
    tolua_function(tolua_S,"init",tolua_MyUI_myui_Slider_init00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Slider_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Slider_doTouch00);
    tolua_variable(tolua_S,"backSprite",tolua_get_myui__Slider_backSprite_ptr,tolua_set_myui__Slider_backSprite_ptr);
    tolua_variable(tolua_S,"sliderSprite",tolua_get_myui__Slider_sliderSprite_ptr,tolua_set_myui__Slider_sliderSprite_ptr);
    tolua_function(tolua_S,"getValue",tolua_MyUI_myui_Slider_getValue00);
    tolua_function(tolua_S,"setValue",tolua_MyUI_myui_Slider_setValue00);
    tolua_variable(tolua_S,"value",tolua_get_myui__Slider_value,tolua_set_myui__Slider_value);
    tolua_function(tolua_S,"new",tolua_MyUI_myui_Slider_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_Slider_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_Slider_new00_local);
    tolua_function(tolua_S,"getMaxValue",tolua_MyUI_myui_Slider_getMaxValue00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Label","myui::Label","myui::Base",NULL);
   tolua_beginmodule(tolua_S,"Label");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Label_create00);
    tolua_function(tolua_S,"init",tolua_MyUI_myui_Label_init00);
    tolua_function(tolua_S,"getArgs",tolua_MyUI_myui_Label_getArgs00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Label_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Label_doTouch00);
    tolua_variable(tolua_S,"rect",tolua_get_myui__Label_rect,tolua_set_myui__Label_rect);
    tolua_function(tolua_S,"setNumber",tolua_MyUI_myui_Label_setNumber00);
    tolua_function(tolua_S,"getNumber",tolua_MyUI_myui_Label_getNumber00);
    tolua_variable(tolua_S,"numbers",tolua_get_myui__Label_numbers,tolua_set_myui__Label_numbers);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"HPLabel","myui::HPLabel","myui::Base",tolua_collect_myui__HPLabel);
   #else
   tolua_cclass(tolua_S,"HPLabel","myui::HPLabel","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"HPLabel");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_HPLabel_create00);
    tolua_function(tolua_S,"init",tolua_MyUI_myui_HPLabel_init00);
    tolua_function(tolua_S,"setValue",tolua_MyUI_myui_HPLabel_setValue00);
    tolua_variable(tolua_S,"viewSize",tolua_get_myui__HPLabel_viewSize,tolua_set_myui__HPLabel_viewSize);
    tolua_variable(tolua_S,"maxValue",tolua_get_myui__HPLabel_maxValue,tolua_set_myui__HPLabel_maxValue);
    tolua_variable(tolua_S,"value",tolua_get_myui__HPLabel_value,tolua_set_myui__HPLabel_value);
    tolua_variable(tolua_S,"backSprite",tolua_get_myui__HPLabel_backSprite_ptr,tolua_set_myui__HPLabel_backSprite_ptr);
    tolua_variable(tolua_S,"valueSprite",tolua_get_myui__HPLabel_valueSprite_ptr,tolua_set_myui__HPLabel_valueSprite_ptr);
    tolua_function(tolua_S,"new",tolua_MyUI_myui_HPLabel_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_HPLabel_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_HPLabel_new00_local);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Tree","myui::Tree","myui::Base",tolua_collect_myui__Tree);
   #else
   tolua_cclass(tolua_S,"Tree","myui::Tree","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Tree");
    tolua_function(tolua_S,"new",tolua_MyUI_myui_Tree_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_Tree_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_Tree_new00_local);
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Tree_create00);
    tolua_function(tolua_S,"addTree",tolua_MyUI_myui_Tree_addTree00);
    tolua_function(tolua_S,"show",tolua_MyUI_myui_Tree_show00);
    tolua_function(tolua_S,"visit",tolua_MyUI_myui_Tree_visit00);
    tolua_variable(tolua_S,"parent",tolua_get_myui__Tree_parent_ptr,tolua_set_myui__Tree_parent_ptr);
    tolua_variable(tolua_S,"next",tolua_get_myui__Tree_next_ptr,tolua_set_myui__Tree_next_ptr);
    tolua_variable(tolua_S,"child",tolua_get_myui__Tree_child_ptr,tolua_set_myui__Tree_child_ptr);
    tolua_variable(tolua_S,"image",tolua_get_myui__Tree_image_ptr,tolua_set_myui__Tree_image_ptr);
    tolua_variable(tolua_S,"isOpen",tolua_get_myui__Tree_isOpen,tolua_set_myui__Tree_isOpen);
    tolua_function(tolua_S,"show",tolua_MyUI_myui_Tree_show01);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Tree_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Tree_doTouch00);
    tolua_function(tolua_S,"checkInTree",tolua_MyUI_myui_Tree_checkInTree00);
    tolua_function(tolua_S,"touchInTree",tolua_MyUI_myui_Tree_touchInTree00);
    tolua_function(tolua_S,"hideCloseNode",tolua_MyUI_myui_Tree_hideCloseNode00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"List","myui::List","myui::Base",tolua_collect_myui__List);
   #else
   tolua_cclass(tolua_S,"List","myui::List","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"List");
    tolua_function(tolua_S,"new",tolua_MyUI_myui_List_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_List_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_List_new00_local);
    tolua_function(tolua_S,"create",tolua_MyUI_myui_List_create00);
    tolua_function(tolua_S,"create",tolua_MyUI_myui_List_create01);
    tolua_function(tolua_S,"remove",tolua_MyUI_myui_List_remove00);
    tolua_function(tolua_S,"add",tolua_MyUI_myui_List_add00);
    tolua_function(tolua_S,"show",tolua_MyUI_myui_List_show00);
    tolua_variable(tolua_S,"content",tolua_get_myui__List_content,tolua_set_myui__List_content);
    tolua_variable(tolua_S,"image",tolua_get_myui__List_image_ptr,tolua_set_myui__List_image_ptr);
    tolua_variable(tolua_S,"cellSize",tolua_get_myui__List_cellSize,tolua_set_myui__List_cellSize);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_List_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_List_doTouch00);
    tolua_function(tolua_S,"pickImageIndex",tolua_MyUI_myui_List_pickImageIndex00);
    tolua_function(tolua_S,"pickImage",tolua_MyUI_myui_List_pickImage00);
    tolua_variable(tolua_S,"nowTouchImage",tolua_get_myui__List_nowTouchImage_ptr,tolua_set_myui__List_nowTouchImage_ptr);
    tolua_variable(tolua_S,"exchageAble",tolua_get_myui__List_exchageAble,tolua_set_myui__List_exchageAble);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"Table","myui::Table","myui::Base",tolua_collect_myui__Table);
   #else
   tolua_cclass(tolua_S,"Table","myui::Table","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"Table");
    tolua_function(tolua_S,"new",tolua_MyUI_myui_Table_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_Table_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_Table_new00_local);
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Table_create00);
    tolua_variable(tolua_S,"exchageAble",tolua_get_myui__Table_exchageAble,tolua_set_myui__Table_exchageAble);
    tolua_variable(tolua_S,"images",tolua_get_myui__Table_images,tolua_set_myui__Table_images);
    tolua_function(tolua_S,"add",tolua_MyUI_myui_Table_add00);
    tolua_function(tolua_S,"push",tolua_MyUI_myui_Table_push00);
    tolua_function(tolua_S,"remove",tolua_MyUI_myui_Table_remove00);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_Table_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_Table_doTouch00);
    tolua_function(tolua_S,"pickImageIndex",tolua_MyUI_myui_Table_pickImageIndex00);
    tolua_function(tolua_S,"pickImage",tolua_MyUI_myui_Table_pickImage00);
    tolua_function(tolua_S,"show",tolua_MyUI_myui_Table_show00);
    tolua_variable(tolua_S,"tableSize",tolua_get_myui__Table_tableSize,tolua_set_myui__Table_tableSize);
    tolua_variable(tolua_S,"cellSize",tolua_get_myui__Table_cellSize,tolua_set_myui__Table_cellSize);
    tolua_variable(tolua_S,"nowTouchImage",tolua_get_myui__Table_nowTouchImage_ptr,tolua_set_myui__Table_nowTouchImage_ptr);
    tolua_function(tolua_S,"visit",tolua_MyUI_myui_Table_visit00);
    tolua_function(tolua_S,"doExchange",tolua_MyUI_myui_Table_doExchange00);
    tolua_function(tolua_S,"removeIndex",tolua_MyUI_myui_Table_removeIndex00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"ScrollView","myui::ScrollView","myui::Base",tolua_collect_myui__ScrollView);
   #else
   tolua_cclass(tolua_S,"ScrollView","myui::ScrollView","myui::Base",NULL);
   #endif
   tolua_beginmodule(tolua_S,"ScrollView");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_ScrollView_create00);
    tolua_function(tolua_S,"init",tolua_MyUI_myui_ScrollView_init00);
    tolua_function(tolua_S,"add",tolua_MyUI_myui_ScrollView_add00);
    tolua_function(tolua_S,"visit",tolua_MyUI_myui_ScrollView_visit00);
    tolua_variable(tolua_S,"width",tolua_get_myui__ScrollView_width,tolua_set_myui__ScrollView_width);
    tolua_variable(tolua_S,"height",tolua_get_myui__ScrollView_height,tolua_set_myui__ScrollView_height);
    tolua_function(tolua_S,"new",tolua_MyUI_myui_ScrollView_new00);
    tolua_function(tolua_S,"new_local",tolua_MyUI_myui_ScrollView_new00_local);
    tolua_function(tolua_S,".call",tolua_MyUI_myui_ScrollView_new00_local);
    tolua_variable(tolua_S,"eachTap",tolua_get_myui__ScrollView_eachTap,tolua_set_myui__ScrollView_eachTap);
    tolua_constant(tolua_S,"UP_DOWN",myui::ScrollView::UP_DOWN);
    tolua_constant(tolua_S,"LEFT_RIGHT",myui::ScrollView::LEFT_RIGHT);
    tolua_constant(tolua_S,"ALL",myui::ScrollView::ALL);
    tolua_variable(tolua_S,"scrollType",tolua_get_myui__ScrollView_scrollType,tolua_set_myui__ScrollView_scrollType);
    tolua_function(tolua_S,"setEachTap",tolua_MyUI_myui_ScrollView_setEachTap00);
    tolua_function(tolua_S,"setScrollType",tolua_MyUI_myui_ScrollView_setScrollType00);
    tolua_variable(tolua_S,"child",tolua_get_myui__ScrollView_child_ptr,tolua_set_myui__ScrollView_child_ptr);
    tolua_function(tolua_S,"checkIn",tolua_MyUI_myui_ScrollView_checkIn00);
    tolua_function(tolua_S,"doTouch",tolua_MyUI_myui_ScrollView_doTouch00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Window","myui::Window","CCLayer",NULL);
   tolua_beginmodule(tolua_S,"Window");
    tolua_function(tolua_S,"create",tolua_MyUI_myui_Window_create00);
    tolua_function(tolua_S,"init",tolua_MyUI_myui_Window_init00);
    tolua_function(tolua_S,"ccTouchesBegan",tolua_MyUI_myui_Window_ccTouchesBegan00);
    tolua_function(tolua_S,"ccTouchesMoved",tolua_MyUI_myui_Window_ccTouchesMoved00);
    tolua_function(tolua_S,"ccTouchesEnded",tolua_MyUI_myui_Window_ccTouchesEnded00);
    tolua_variable(tolua_S,"uis",tolua_get_myui__Window_uis,tolua_set_myui__Window_uis);
    tolua_variable(tolua_S,"actives",tolua_get_myui__Window_actives,tolua_set_myui__Window_actives);
    tolua_variable(tolua_S,"firsts",tolua_get_myui__Window_firsts,tolua_set_myui__Window_firsts);
    tolua_function(tolua_S,"addUI",tolua_MyUI_myui_Window_addUI00);
    tolua_function(tolua_S,"visit",tolua_MyUI_myui_Window_visit00);
    tolua_function(tolua_S,"getWindowSize",tolua_MyUI_myui_Window_getWindowSize00);
    tolua_function(tolua_S,"getPoint",tolua_MyUI_myui_Window_getPoint00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_MyUI (lua_State* tolua_S) {
 return tolua_MyUI_open(tolua_S);
};
#endif

