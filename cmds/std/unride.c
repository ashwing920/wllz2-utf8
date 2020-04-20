// unride.c

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object ob;

	if( !arg ) return help( me );

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if( !mapp( ob->query("horse_prop")) )
		return notify_fail("你没有骑这样东西。\n");

	if( !objectp(me->query_temp("ride_ob")))
		return notify_fail("你没有骑任何坐骑。\n");

	if( !ob->query("equipped"))
		return notify_fail("你并没有骑"+ ob->name() +"。\n");
	
	ob->delete("equipped");
	me->delete_temp("is_riding");
	me->delete_temp("ride_ob");

	if( stringp(ob->query("unride_msg")) ) 
		message_vision(convert_color(ob->query("unride_msg")), me, ob);
	else
		message_vision(YEL"$N一翻身，从「$n" YEL "」上跳了下来。\n"NOR,me,ob);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：unride <坐骑名称>

下马。

HELP
	);

	return 1;
}

