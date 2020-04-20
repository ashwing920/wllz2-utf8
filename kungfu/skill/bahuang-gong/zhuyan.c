// yangxin.c 养心术

#include <ansi.h>

inherit F_SSERVER;

int update_player(object me);

int exert(object me)
{
	int lvl,age;
	age = (int)me->query("age");
	lvl = (int)me->query_skill("bahuang-gong",1);

	if((string)me->query("family/family_name") != "灵鹫宫")
		return notify_fail("你不是灵鹫宫弟子，怎么学来的驻颜之术？\n");

	if( me->is_fighting() )
		return notify_fail("蝴蝶君笑道：战斗中还想变年轻啊？死都想死得美？\n");

	if((int)me->query_temp("zhuyan"))
		return notify_fail("你正在修炼驻颜之术呢！\n");

	if(!environment(me)->query("sleep_room"))
		return notify_fail("修炼驻颜之术还是到休息室去吧！\n");

	if((int)me->query("neili") < 1000 )
		return notify_fail("你的内力不够！\n");

	if((int)me->query("jing") <= 100 )
		return notify_fail("你的精神不够了！\n");

	if((int)me->query("qi") < 500 )
		return notify_fail("你的气血不够！\n");

	if((int)me->query_skill("bahuang-gong",1) < 400)
		return notify_fail("你的八荒六合神功还很粗浅，无法领会驻颜之术！\n");

	if(age <= 30)
		return notify_fail("你现在还年轻呢，这些事情以后再说吧！\n");

	me->add("qi", -100);
	me->add("neili",-300);
	me->receive_damage("jing",80);

	message_vision(HIM"$N盘膝座下，闭上眼睛，开始修炼驻颜之术。\n" NOR, me);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), lvl / 100);
	me->set_temp("zhuyan",1);
	me->start_busy(lvl / 100);
	return 1;
}
void remove_effect(object me, int lvl)
{
	int age, i;

	age = (int)me->query("age");
	lvl = (int)me->query_skill("bahuang-gong",1);

	if(!me) return;
	i = efun::to_int( pow( efun::to_float(lvl), 1.0 / 2.0 ) );
	if( i > random(100)) {
		if( random(age)*2 < 30) {
			me->add("age_modify", 1 );
			me->set("age", 14 + (int)me->query("age_modify") + ((int)me->query("mud_age") / 86400));
			write( HIR "你觉得脑中一片混乱，开始感觉衰老了！\n" NOR );
			me->delete_temp("zhuyan");
			me->start_busy(1);
			return;
		}
		if((int)me->query("age")<=31) {
			write(HIG"可是你只觉得一无所获。\n"NOR);
			me->delete_temp("zhuyan");
			me->start_busy(1);
			return;
		}
		me->add("age_modify", -1);
		me->set("age", 14 + (int)me->query("age_modify") + ((int)me->query("mud_age") / 86400));
		write(HIG"你的驻颜之术修炼成功了，你觉得自己好象年轻了许多了！\n" NOR);
		me->delete_temp("zhuyan");
		me->start_busy(1);
		return;
	}
	write("可是你只觉得一无所获。\n");
	me->delete_temp("zhuyan");
	me->start_busy(1);
	return;
}
