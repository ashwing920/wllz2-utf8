// ride.c

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object ob;

	if( !arg ) return help( me );

	if( !objectp(ob = present(arg, me)))
		return notify_fail("你身上没有这样东西。\n");

	if( !mapp(ob->query("horse_prop")) )
		return notify_fail("你不能骑这样东西。\n");

	if((string)me->query_temp("is_riding") || objectp(me->query_temp("ride_ob")))
		return notify_fail("你已经骑着坐骑了。\n");

	if(!environment(me)->query("outdoors"))
		return notify_fail("这里地方太小了，不能骑马。\n");

	ob->set("equipped","horse");
	me->set_temp("is_riding", ob->name());
	me->set_temp("ride_ob",ob);

	if( stringp(ob->query("ride_msg")) ) 
		message_vision(convert_color(ob->query("ride_msg")), me, ob);
	else 
		message_vision(YEL"$N轻身一跃，骑上一" + sprintf("%s", ob->query("unit"))
			+ "「$n" YEL "」。\n" NOR , me, ob);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：ride <坐骑名称>

骑马。

HELP
	);

	return 1;
}
