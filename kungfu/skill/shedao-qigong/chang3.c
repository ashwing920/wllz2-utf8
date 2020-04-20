
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int neili,damage;

	if(!me->is_fighting())
		return notify_fail("唱仙法只能在战斗中使用。\n");

	if(!target ) target = offensive_target(me);
	if(!target ||  !target->is_character() || !me->is_fighting(target) || !me->visible(target))
		return notify_fail("唱仙法只能在战斗中对对手使用。\n");

	if((int)me->query_skill("shedao-qigong", 1) < 150 )
		return notify_fail("你的蛇岛奇功不够娴熟，不会使用唱仙法吼字决。\n");

	if((int)me->query_skill("shenlong-xinfa",1) < 150 )
		return notify_fail("你的神龙心法还不够娴熟，无法使用唱仙法。\n");

	if( me->query("family/family_name") != "神龙教")
		return notify_fail("你不是神龙教弟子，如何能用唱仙大法？\n");

	if((int)me->query("neili") < 500 )
		return notify_fail("你已经唱得精疲力竭，内力不够了。\n");

	me->clean_up_enemy();
	neili = me->query("neili");
	me->add("neili", -(300+random(200)));
	me->receive_damage("qi", 10);
	me->start_busy(random(5));
	message_vision(HIY "$N深深地吸一囗气，忽然仰天长啸，高声狂叫：不死神龙，唯我不败！\n" NOR, me);
	if( neili/2 + random(neili/2) < (int)target->query("neili")/10)
		return notify_fail("敌人的内力比你高出太多,伤不了！\n");
	damage = (neili - (int)target->query("max_neili")) / 10;
	if( damage > 0 ) {
		target->receive_damage("jing", damage,me);
		target->receive_damage("qi", damage,me);
		target->receive_wound("jing", damage,me);
		target->receive_wound("qi", damage,me);
		message_vision(HIR"$N只觉脑中一阵剧痛，金星乱冒，犹如有万条金龙在眼前舞动。\n" NOR, target);
	}
		else
			{
		message_vision(HIR "$N只觉脑中微痛，似乎受了一点轻伤。\n" NOR, target);
		target->receive_damage("jing", 10,me);
		target->receive_damage("qi", 10,me );
		target->receive_wound("qi", 10,me);
	}
	return 1;
}
