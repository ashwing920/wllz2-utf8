#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	int damage;

	damage = me->query_condition("dashouyin") +2;
	damage *= me->query_con();

	tell_object(me, "突然你感觉胸口疼痛异常，刚才被大手印拍中的肋骨处好象要裂开了似的，鲜血也从口中喷了出来！\n");
	tell_room(environment(me), HIR + me->name()+"突然一言不发，双手捂胸，蹬蹬磴倒退了数步，接着哇得一声吐出口鲜血来！\n" NOR,({ me }));
	me->receive_damage("qi", damage);
	me->receive_wound("qi", damage/2);
	me->set_temp("die_for", "大手印劲力发作而死！");
	me->apply_condition("dashouyin", duration - 1);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
