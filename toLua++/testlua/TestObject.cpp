/*
** Lua binding: TestObject
** Generated automatically by tolua++-1.0.92 on 08/27/13 10:15:24.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "TestObj.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_TestObject_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_TestObject (lua_State* tolua_S)
{
 TestObject* self = (TestObject*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"TestObject");
}

/* method: new of class  TestObject */
#ifndef TOLUA_DISABLE_tolua_TestObject_TestObject_new00
static int tolua_TestObject_TestObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TestObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TestObject* tolua_ret = (TestObject*)  Mtolua_new((TestObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TestObject");
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

/* method: new_local of class  TestObject */
#ifndef TOLUA_DISABLE_tolua_TestObject_TestObject_new00_local
static int tolua_TestObject_TestObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TestObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TestObject* tolua_ret = (TestObject*)  Mtolua_new((TestObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"TestObject");
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

/* method: callFunc of class  TestObject */
#ifndef TOLUA_DISABLE_tolua_TestObject_TestObject_callFunc00
static int tolua_TestObject_TestObject_callFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TestObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TestObject* self = (TestObject*)  tolua_tousertype(tolua_S,1,0);
  const char* funcStr = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'callFunc'",NULL);
#endif
  {
   self->callFunc(funcStr);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'callFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: doFunc of class  TestObject */
#ifndef TOLUA_DISABLE_tolua_TestObject_TestObject_doFunc00
static int tolua_TestObject_TestObject_doFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TestObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TestObject* self = (TestObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'doFunc'",NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->doFunc();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'doFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_TestObject_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"TestObject","TestObject","",tolua_collect_TestObject);
  #else
  tolua_cclass(tolua_S,"TestObject","TestObject","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"TestObject");
   tolua_function(tolua_S,"new",tolua_TestObject_TestObject_new00);
   tolua_function(tolua_S,"new_local",tolua_TestObject_TestObject_new00_local);
   tolua_function(tolua_S,".call",tolua_TestObject_TestObject_new00_local);
   tolua_function(tolua_S,"callFunc",tolua_TestObject_TestObject_callFunc00);
   tolua_function(tolua_S,"doFunc",tolua_TestObject_TestObject_doFunc00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_TestObject (lua_State* tolua_S) {
 return tolua_TestObject_open(tolua_S);
};
#endif

