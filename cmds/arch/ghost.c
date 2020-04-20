// ghost.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object ob;

	if (wiz_level(me) >= wiz_level("(wizard)") ){
		if(arg){
		if (!find_player(arg))
			return notify_fail(HIR"这个玩家不在线上！\n"NOR);
			ob = find_player(arg);
		}
		if(!arg) ob=me;
	}
	else {
		if(!arg) ob=me;
		if(arg) 
		ob=me;
	}
	if(!ob->is_ghost()){
		ob->set_ghost(1);
		tell_object(ob,HIB"你成功地变成了一只鬼！\n"NOR);
	}
	else{
		ob->set_ghost(0);
		tell_object(ob,HIC"你又重新投胎做人了。\n"NOR);
	}
	return 1;
}



int help(object me)
{
  write(@HELP
指令格式 : ghost

让人变鬼，让鬼做人。
HELP
	);
	return 1;
}

