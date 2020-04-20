 // respirate.c

#include <skill.h>
#include <ansi.h>

private int respirate_cost;
int respirating(object me);
int halt_respirate(object me);

int main(object me, string arg)
{
	object where = environment(me);
	seteuid(getuid());

	if( me->query("age") < 15 )
		return notify_fail("你现在还年轻，等以后再练吧！\n");

	if( where->query("restrict_action"))
		return notify_fail("这里不能做这件事情。\n");
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");
	if (me->is_busy())
		return notify_fail("你现在正忙着呢！\n");
	if( me->is_fighting() )
		return notify_fail("战斗也是一种修行，但不能和精力的修行同时进行。\n");
	if(me->query_skill("taoism",1)<10 && me->query_skill("buddhism",1)<10
	&& me->query_skill("lamaism",1) < 10 &&  me->query_skill("mahayana",1)<10
	&&  me->query_skill("poison",1)<10)
		return notify_fail("你没有可以值得吐纳的心法。\n");
	if( !arg || !sscanf(arg, "%d", respirate_cost))
		return notify_fail("你要花多少精修行？\n");
	if (respirate_cost < 10)
		return notify_fail("你最少要花 10 点精力才能进行修行。\n");
	if( (int)me->query("jing") < respirate_cost )
		return notify_fail("你现在精不足，无法修行精力！\n");
	if( (int)me->query("qi") * 100 / (int)me->query("max_qi") < 70 )
		return notify_fail("你现在身体状况太差了，无法集中精神！\n");
	write("你闭上眼睛开始打坐。\n");
	me->set_temp("pending/respirate", 1);
	me->set_temp("respirate_cost", respirate_cost);
	me->set_short_desc("正坐在地下吐纳炼精。");
	message("vision",me->name()+"盘膝坐下，开始吐纳炼精。\n", environment(me),({me}));
	me->start_busy((: respirating :), (: halt_respirate :));
	return 1;
}
int respirating(object me)
{
	int respirate_cost = (int)me->query_temp("respirate_cost");
	int jingli_gain,jingli_skill;

	if((int)me->query_skill("taoism",1)){
		jingli_gain = 2*(int)me->query_skill("taoism",1);
		jingli_skill = (int)me->query_skill("taoism",1);
	}else if((int)me->query_skill("buddhism",1)){
		jingli_gain = 2*(int)me->query_skill("buddhism",1);
		jingli_skill = (int)me->query_skill("buddhism",1);
	}else if((int)me->query_skill("lamaism",1)){
		jingli_gain = 2*(int)me->query_skill("lamaism",1);
		jingli_skill = (int)me->query_skill("lamaism",1);
	}else if((int)me->query_skill("mahayana",1)){
		jingli_gain = 2*(int)me->query_skill("mahayana",1);
		jingli_skill = (int)me->query_skill("mahayana",1);
	}
	else if((int)me->query_skill("poison",1)){
		jingli_gain = 2*(int)me->query_skill("poison",1);
		jingli_skill = (int)me->query_skill("poison",1);
	}

	if (respirate_cost < jingli_gain) jingli_gain = respirate_cost;
	if (respirate_cost>2*jingli_gain) jingli_gain = respirate_cost/2;

	me->add("jingli", jingli_gain);
	me->set_temp("respirate_cost", respirate_cost -= jingli_gain);
	me->add("jing", -jingli_gain);
	if (respirate_cost > 0) return 1;
	me->set_temp("pending/respirate", 0);
	respirate_cost = 0;
	message_vision("$N吐纳完毕，睁开双眼，站了起来。\n", me);
	me->set_short_desc(0);
	if((int)me->query("jingli") < (int)me->query("max_jingli") * 2)
		return 0;
	else {
		if((int)me->query("max_jingli") >= (int)me->max_jingli()){
			write("你的精力修为似乎已经达到了瓶颈。\n");
			me->set("max_jingli",(int)me->max_jingli());
			me->set("jingli", (int)me->query("max_jingli"));
			me->set_short_desc(0);
			return 0;

		}
		else
		{
			me->add("max_jingli",jingli_skill /10);
			me->set("jingli", (int)me->query("max_jingli"));
			write(HIC"你的精力增加了！！\n"NOR);
			me->set_short_desc(0);
			return 0;
		}
	}
}
int halt_respirate(object me)
{
	if ((int)me->query("jingli") > (int)me->query("max_jingli") * 2)
		me->set("jingli", (int)me->query("max_jingli") * 2);
	me->set_temp("pending/respirate", 0);
	me->set_short_desc(0);
	return 1;
}
int help(object me)
{
		write(@HELP
指令格式 : respirate [<耗费「精」的量>]

打坐修行，利用「炼精化气，炼气化神，炼神还虚」的方法将你的精转变
成精力，但你必须学会禅宗心法或道家学说。

See also: exercise
HELP
		);
		return 1;
}
