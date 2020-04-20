// sleep.c

inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{
	object *list, env;
	int i, flag;

	if( arg && arg != "" ) return 0;
	if( me->is_busy()) return notify_fail("你正忙着呢！\n");
	if( me->query_temp("sleeping") ) return notify_fail("你现在正躺着呢。\n");

	env = environment(me);
	if( env->query("restrict_action") && !env->query("player_house"))
		return notify_fail("这里不能做这件事情。\n");
	if( env->query("fight_room") ||
	    env->query("no_sleep_room"))
		return notify_fail("这里不是你能睡的地方。\n");
    

	if( me->is_fighting() ) return notify_fail("你现在正在战斗。\n");

	flag = 0;
	list = all_inventory(me);
	i = sizeof(list);  
	while ( i-- ) 
		if ((string)list[i]->query("id") == "sleepbag") flag = 1;

	if(environment(me)->query("sleep_room") || me->query("family/family_name") == "丐帮")
		message_vision("$N往下一躺，不一会儿就进入了梦乡。\n",me);
	else {
		if( flag == 1 ) {
			if((int)me->query("combat_exp") < 30000 ) {
				message_vision("$N展开一只睡袋，钻了进去，不一会儿就进入了梦乡。\n", me);
			}
			else {
				return notify_fail("你现在已经可以不需要睡袋了。\n");
			}
		}
		else {
			return notify_fail("这里不是你睡觉的地方！\n");
		}
	}

	me->sleep();
	return 1;
}

int help()
{
	write(@HELP
指令格式：sleep

这条命令可以使你很快恢复体力。
HELP
	);
	return 1;
}
