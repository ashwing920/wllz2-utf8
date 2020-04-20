// exercise.c
#include <skill.h>
#include <ansi.h>

int exercising(object me);
int halt_exercise(object me);
int main(object me, string arg)
{
	int exercise_cost;
	string force;
	mapping msg;
	object where;
	seteuid(getuid());
	where = environment(me);
	if(where->query("restrict_action"))
		return notify_fail("这里不能做这件事情。\n");
	if((int)me->query_skill("force",1)<10)
		return notify_fail("你的内力修为太低了，怎么练也练不起来。\n");
	if(!(force = me->query_skill_mapped("force")) )
		return notify_fail("你必须先用 enable 选择你要用的特殊内功。\n");
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");
	if (where->query("sleep_room"))
		return notify_fail("卧室不能打坐，会影响别人休息。\n");
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");
	if( environment(me)->query("no_fight") )
		return notify_fail("这里是是非之地，不可久留，别练功了，快走吧！\n");
	if( me->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");
	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("你要花多少气练功？\n");
	if (exercise_cost < 10)
		return notify_fail("你的内功还没有达到那个境界！\n");
	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");
	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");
	msg = SKILL_D(force)->exercise_msg(me);
	if (!msg || undefinedp(msg["start_my_msg"]))
		write("你坐下来运气用功，一股内息开始在体内流动。\n");
	else
		write(msg["start_my_msg"]);

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	if(!msg || undefinedp(msg["status_msg"]))
		me->set_short_desc("正坐在地下修炼内力。");
	else
		me->set_short_desc(msg["status_msg"]);
	if (!msg || undefinedp(msg["start_other_msg"]))
		tell_room(environment(me),me->name()+"盘膝坐下，开始运功打坐。\n", ({ me }));
	else
		tell_room(environment(me),msg["start_other_msg"], ({ me }));

	me->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}
int exercising(object me)
{
	string force;
	mapping msg;

	int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 2*(int)me->query_skill("force",1) ;
	int n;

	if (exercise_cost < neili_gain) neili_gain = exercise_cost;
	if (exercise_cost>2*neili_gain) neili_gain = exercise_cost/2;
		me->add("neili", neili_gain);
		me->set_temp("exercise_cost", exercise_cost -= neili_gain);
		me->add("qi", -neili_gain);
	if (exercise_cost > 0) return 1;

	force = me->query_skill_mapped("force");
	if (force) msg = SKILL_D(force)->exercise_msg(me);
	if (exercise_cost > 0) {
		if (msg && !undefinedp(msg["exec_my_msg"]))
			tell_object(me, msg["exec_my_msg"]);
		if (!random(3) && msg && !undefinedp(msg["exec_other_msg"]))
			tell_room(environment(me), msg["exec_other_msg"], ({me}));
		return 1;
	}
	me->set_temp("pending/exercise", 0);
	me->set_short_desc(0);
	if (!msg || undefinedp(msg["end_my_msg"]))
		tell_object(me, "你运功完毕，站了起来。\n");
	else
		tell_object(me, msg["end_my_msg"]);
	if (!msg || undefinedp(msg["end_other_msg"]))
		tell_room(environment(me),me->name()+"运功完毕，站了起来。\n", ({me}));
	else
		tell_room(environment(me),msg["end_other_msg"], ({me}));

	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > (int)me->max_neili()) {
			write(HIC"你的内力修为似乎已经达到了瓶颈。\n"NOR);
			me->set("neili", (int)me->query("max_neili"));
			me->set_short_desc(0);
			return 0;
		}
		else {
			//me->add("max_neili", 1);
			n = (int)me->query_skill("force",1)/20;
			if( n < 10) n = 1;
			me->add("max_neili",n);
			me->set("neili", (int)me->query("max_neili"));
			write(HIW"你的内力增加了！！\n"NOR);
			me->set_short_desc(0);
			return 0;
		}
	}
}
int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	me->set_short_desc(0);
	return 1;
}
int help(object me)
{
		write(@HELP
指令格式 : exercise [<耗费「气」的量> 必须多于 10]
运气练功，控制体内的气在各经脉间流动，藉以训练人体肌肉骨骼的耐
力、爆发力，并且用内力的形式将能量储备下来。
HELP
		);
		return 1;
}
