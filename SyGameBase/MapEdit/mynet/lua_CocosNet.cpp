/*
** Lua binding: luaCocosNet
** Generated automatically by tolua++-1.0.92 on Sun Oct 20 17:03:27 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

#include "CocosNet.h"
using namespace cocos2d;
using namespace mynet;
/* Exported function */
TOLUA_API int  tolua_luaCocosNet_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_LuaReqData (lua_State* tolua_S)
{
 LuaReqData* self = (LuaReqData*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_stReqData (lua_State* tolua_S)
{
 stReqData* self = (stReqData*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_CocosNet (lua_State* tolua_S)
{
 CocosNet* self = (CocosNet*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Net");
 tolua_usertype(tolua_S,"CocosNet");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"LuaReqData");
 tolua_usertype(tolua_S,"stReqData");
}

/* get function: reqId of class  stReqData */
#ifndef TOLUA_DISABLE_tolua_get_stReqData_reqId
static int tolua_get_stReqData_reqId(lua_State* tolua_S)
{
  stReqData* self = (stReqData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reqId'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->reqId);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: reqId of class  stReqData */
#ifndef TOLUA_DISABLE_tolua_set_stReqData_reqId
static int tolua_set_stReqData_reqId(lua_State* tolua_S)
{
  stReqData* self = (stReqData*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'reqId'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->reqId = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  stReqData */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_stReqData_new00
static int tolua_luaCocosNet_stReqData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"stReqData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   stReqData* tolua_ret = (stReqData*)  Mtolua_new((stReqData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"stReqData");
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

/* method: new_local of class  stReqData */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_stReqData_new00_local
static int tolua_luaCocosNet_stReqData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"stReqData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   stReqData* tolua_ret = (stReqData*)  Mtolua_new((stReqData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"stReqData");
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

/* method: delete of class  stReqData */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_stReqData_delete00
static int tolua_luaCocosNet_stReqData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"stReqData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  stReqData* self = (stReqData*)  tolua_tousertype(tolua_S,1,0);
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

/* method: setContent of class  LuaReqData */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_LuaReqData_setContent00
static int tolua_luaCocosNet_LuaReqData_setContent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaReqData",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaReqData* self = (LuaReqData*)  tolua_tousertype(tolua_S,1,0);
  const char* content = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContent'",NULL);
#endif
  {
   self->setContent(content);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setContent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LuaReqData */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_LuaReqData_new00
static int tolua_luaCocosNet_LuaReqData_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaReqData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaReqData* tolua_ret = (LuaReqData*)  Mtolua_new((LuaReqData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaReqData");
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

/* method: new_local of class  LuaReqData */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_LuaReqData_new00_local
static int tolua_luaCocosNet_LuaReqData_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaReqData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaReqData* tolua_ret = (LuaReqData*)  Mtolua_new((LuaReqData)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaReqData");
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

/* method: delete of class  LuaReqData */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_LuaReqData_delete00
static int tolua_luaCocosNet_LuaReqData_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LuaReqData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LuaReqData* self = (LuaReqData*)  tolua_tousertype(tolua_S,1,0);
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

/* method: create of class  LuaReqData */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_LuaReqData_create00
static int tolua_luaCocosNet_LuaReqData_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LuaReqData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LuaReqData* tolua_ret = (LuaReqData*)  LuaReqData::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaReqData");
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

/* method: new of class  CocosNet */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_CocosNet_new00
static int tolua_luaCocosNet_CocosNet_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CocosNet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CocosNet* tolua_ret = (CocosNet*)  Mtolua_new((CocosNet)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CocosNet");
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

/* method: new_local of class  CocosNet */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_CocosNet_new00_local
static int tolua_luaCocosNet_CocosNet_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CocosNet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CocosNet* tolua_ret = (CocosNet*)  Mtolua_new((CocosNet)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CocosNet");
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

/* method: delete of class  CocosNet */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_CocosNet_delete00
static int tolua_luaCocosNet_CocosNet_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CocosNet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CocosNet* self = (CocosNet*)  tolua_tousertype(tolua_S,1,0);
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

/* method: newClient of class  CocosNet */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_CocosNet_newClient00
static int tolua_luaCocosNet_CocosNet_newClient00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CocosNet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CocosNet* self = (CocosNet*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  const char* ip = ((const char*)  tolua_tostring(tolua_S,3,0));
  unsigned short port = ((unsigned short)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'newClient'",NULL);
#endif
  {
   self->newClient(index,ip,port);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'newClient'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: updateClient of class  CocosNet */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_CocosNet_updateClient00
static int tolua_luaCocosNet_CocosNet_updateClient00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CocosNet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CocosNet* self = (CocosNet*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'updateClient'",NULL);
#endif
  {
   self->updateClient(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'updateClient'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMe of class  CocosNet */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_CocosNet_getMe00
static int tolua_luaCocosNet_CocosNet_getMe00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CocosNet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CocosNet& tolua_ret = (CocosNet&)  CocosNet::getMe();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"CocosNet");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMe'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  CocosNet */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_CocosNet_init00
static int tolua_luaCocosNet_CocosNet_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CocosNet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CocosNet* self = (CocosNet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'",NULL);
#endif
  {
   self->init();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  CocosNet */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_CocosNet_stop00
static int tolua_luaCocosNet_CocosNet_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CocosNet",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CocosNet* self = (CocosNet*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'",NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sendtoServer of class  CocosNet */
#ifndef TOLUA_DISABLE_tolua_luaCocosNet_CocosNet_sendtoServer00
static int tolua_luaCocosNet_CocosNet_sendtoServer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CocosNet",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"LuaReqData",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CocosNet* self = (CocosNet*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
  LuaReqData* reqData = ((LuaReqData*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'sendtoServer'",NULL);
#endif
  {
   self->sendtoServer(index,reqData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sendtoServer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_luaCocosNet_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"stReqData","stReqData","CCObject",tolua_collect_stReqData);
  #else
  tolua_cclass(tolua_S,"stReqData","stReqData","CCObject",NULL);
  #endif
  tolua_beginmodule(tolua_S,"stReqData");
   tolua_variable(tolua_S,"reqId",tolua_get_stReqData_reqId,tolua_set_stReqData_reqId);
   tolua_function(tolua_S,"new",tolua_luaCocosNet_stReqData_new00);
   tolua_function(tolua_S,"new_local",tolua_luaCocosNet_stReqData_new00_local);
   tolua_function(tolua_S,".call",tolua_luaCocosNet_stReqData_new00_local);
   tolua_function(tolua_S,"delete",tolua_luaCocosNet_stReqData_delete00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LuaReqData","LuaReqData","stReqData",tolua_collect_LuaReqData);
  #else
  tolua_cclass(tolua_S,"LuaReqData","LuaReqData","stReqData",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LuaReqData");
   tolua_function(tolua_S,"setContent",tolua_luaCocosNet_LuaReqData_setContent00);
   tolua_function(tolua_S,"new",tolua_luaCocosNet_LuaReqData_new00);
   tolua_function(tolua_S,"new_local",tolua_luaCocosNet_LuaReqData_new00_local);
   tolua_function(tolua_S,".call",tolua_luaCocosNet_LuaReqData_new00_local);
   tolua_function(tolua_S,"delete",tolua_luaCocosNet_LuaReqData_delete00);
   tolua_function(tolua_S,"create",tolua_luaCocosNet_LuaReqData_create00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"CocosNet","CocosNet","",tolua_collect_CocosNet);
  #else
  tolua_cclass(tolua_S,"CocosNet","CocosNet","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"CocosNet");
   tolua_function(tolua_S,"new",tolua_luaCocosNet_CocosNet_new00);
   tolua_function(tolua_S,"new_local",tolua_luaCocosNet_CocosNet_new00_local);
   tolua_function(tolua_S,".call",tolua_luaCocosNet_CocosNet_new00_local);
   tolua_function(tolua_S,"delete",tolua_luaCocosNet_CocosNet_delete00);
   tolua_function(tolua_S,"newClient",tolua_luaCocosNet_CocosNet_newClient00);
   tolua_function(tolua_S,"updateClient",tolua_luaCocosNet_CocosNet_updateClient00);
   tolua_function(tolua_S,"getMe",tolua_luaCocosNet_CocosNet_getMe00);
   tolua_function(tolua_S,"init",tolua_luaCocosNet_CocosNet_init00);
   tolua_function(tolua_S,"stop",tolua_luaCocosNet_CocosNet_stop00);
   tolua_function(tolua_S,"sendtoServer",tolua_luaCocosNet_CocosNet_sendtoServer00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_luaCocosNet (lua_State* tolua_S) {
 return tolua_luaCocosNet_open(tolua_S);
};
#endif

