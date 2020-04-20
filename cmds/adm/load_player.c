// load_player.c
// Created by robert@wllz

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob,player;

	if( me != this_player(1) ) return 0;

	if(SECURITY_D->get_status(me) != "(admin)")
		return notify_fail("你的权限不足以使用这个指令。\n");

	if(!arg)
		return notify_fail("指令格式：load_player <sd id> \n");

	seteuid(ROOT_UID);
	
	if(find_player(arg))
		return notify_fail("目前该玩家正在游戏中。\n");

	ob = new(LOGIN_OB);
	ob->set("id",arg);
	if(!ob->restore()){
		write("没有这个玩家。\n");
		destruct(ob);
		return 1;
	}
	destruct(ob);

	player = UPDATE_D->load_player(arg);
	player->restore_autoload();
	player->move(environment(me));
	write(sprintf("%s载入成功。\n",player->name(2)));
	player->delete_temp("temp_loaded");

	return 1;
}

int help(object me)
{
	write(@HELP

指令格式：load_player <sb id>

这个指令是让你载入一个玩家的ID。

HELP
	);
	return 1;
}
