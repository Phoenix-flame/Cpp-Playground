#include <iostream>
#include <string.h>
#include <lua5.1/lua.hpp>
#define LOG(x) std::cout << x << std::endl;

#define NAME(name) #name
#define setFloatValue(var) setVar(#var, var)

int main(){

    std::cout << "** Test Lua embedding" << std::endl;
    std::cout << "** Init Lua" << std::endl;
    lua_State *L;
    L = luaL_newstate();
    luaL_openlibs(L);
    if (luaL_loadfile(L, "luascript.lua")) {
        std::cerr << "Something went wrong loading the chunk (syntax error?)" << std::endl;
        std::cerr << lua_tostring(L, -1) << std::endl;
        lua_pop(L,1);
    }

    if (lua_pcall(L,0, LUA_MULTRET, 0)) {
        std::cerr << "Something went wrong during execution" << std::endl;
        std::cerr << lua_tostring(L, -1) << std::endl;
        lua_pop(L,1);
    }

    auto setVar = [&](std::string name, float val){
        lua_pushnumber(L, val);
        lua_setglobal(L, name.c_str());
    };

    float speed_x = 2.0;
    float speed_y = 1.0;
    float pos_x = 10.0;
    float pos_y = 10.0;
    
    setFloatValue(speed_x);
    setFloatValue(speed_y);
    setFloatValue(pos_x);
    setFloatValue(pos_y);

    for (float dt = 0 ; dt < 20; dt += 0.1){
        lua_getglobal(L, "update");
        lua_pushnumber(L, 0.1);
        lua_pcall(L, 1, 2, 0);
        float ret1 = lua_tonumber(L, -2);
        float ret2 = lua_tonumber(L, -1);
        lua_pop(L, 2);
        std::cout << "Position: [" << ret1 << ", " << ret2 << "]" << std::endl;
    }

    lua_close(L);
}
