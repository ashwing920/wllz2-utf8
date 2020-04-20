// xx_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) ) {
		message("vision", me->name() + "全身瘙痒，手脚开始不由自主的乱抓。\n", environment(me), me);
	}
	else {
		tell_object(me, HIR"你全身开始瘙痒，一阵阵，仿佛有千万只蚂蚁不停的叮咬着你。\n" NOR );
		message("vision", me->name() + "全身开始逐渐发红发紫，看来是中的腐尸毒开始发作了。\n",environment(me), me);
	}
		me->receive_wound("qi",duration / 4);
		me->receive_wound("jing",duration / 10);
		me->apply_condition("corpse_poison", duration - 1);
	me->set_temp("die_for","中腐尸毒而死！");
	me->delete_temp("last_damage_from");
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
