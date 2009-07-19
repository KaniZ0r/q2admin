#include "g_local.h"
#include "q2a_lua.h"

int q2a_lua_gi_dprintf(lua_State *lua_L)
{
	// FIXME: do things like real printf(fmt, ...)
	char *str;
	str = (char *)lua_tostring(lua_L, 1);

	q2a_fpu_q2();

	gi.dprintf("%s", str);

	q2a_fpu_lua();

	return 0;
}

int q2a_lua_gi_cprintf(lua_State *lua_L)
{
	edict_t *ent;
	int client;
	int lvl;
	char *str;

	client = lua_tointeger(lua_L, 1);
	lvl = lua_tointeger(lua_L, 2);
	str = (char *)lua_tostring(lua_L, 3);

	ent = getEnt((client + 1));

	q2a_fpu_q2();

	gi.cprintf(ent, lvl, str);

	q2a_fpu_lua();

	return 0;
}
