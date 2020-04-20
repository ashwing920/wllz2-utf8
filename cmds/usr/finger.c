// finger.c

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

private void create() { seteuid(getuid());}

int main(object me, string arg)
{

	if(!arg ) {
		if(!wizardp(me)) return help(me);
	else 
		write(FINGER_D->finger_all());
		return 1;
	}
	if(arg && arg != ""){
		if((int)me->query("jing") <= 50)
			return notify_fail("你现在精神不好。\n");
		me->receive_damage("jing", 10);
		write( FINGER_D->finger_user(arg) );
		return 1;
	}
}

int help(object me)
{
  write(@HELP
指令格式 : finger [使用者姓名]
 
这个指令可以显示有关某个玩家的连线, 权限等资料。
 
see also : who
HELP
	);
	return 1;
}
