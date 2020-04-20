// kuangfeng.c  狂风绝技

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
        int damage;
 
        if( !target ) target = offensive_target(me);
        if( !me->is_fighting() )
                return notify_fail("「狂风绝技」只能在战斗中使用。\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("「狂风绝技」开始时不能拿着兵器！\n");

        if( (int)me->query("neili") < 400)
                return notify_fail("你的内力不够！\n");

        if( (int)me->query_skill("bibo-shengong",1) < 100)
                return notify_fail("你的碧波神功不够！\n");

        if( (int)me->query_skill("luoying-zhang",1) < 100 ||
                me->query_skill("xuanfeng-leg",1) < 100)
                return notify_fail("你的腿掌功夫还不到家，无法使用狂风绝技！\n");

        msg = HIY "$N使出桃花岛绝技「狂风绝技」，整个人朝$n飞去！！\n" NOR;
 	if (random(me->query_skill("force")) > target->query_skill("force")/3 ){
		me->start_busy(3);
		damage = (int)me->query_skill("xuanfeng-leg", 1);
		damage = damage*5;
		target->receive_damage("qi", damage*4,me);
		target->receive_wound("qi", damage*2,me);
		me->add("neili", -damage/3);

	if( damage < 20 )
			msg += HIY"结果$n受到$N的腿法攻击，闷哼一声。\n"NOR;
	else if( damage < 40 )
			msg += HIY"结果$n被$N以腿法攻击，「嘿」地一声退了两步。\n"NOR;
	else if( damage < 80 )
			msg += RED"结果$n被$N以腿法攻击，胸口有如受到一记重锤，连退了五六步！\n"NOR;
		else
			msg += HIR"结果$n被$N的腿法攻击，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;

	}
	else
	{
		me->start_busy(4);
		msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
	}
	message_vision(msg, me, target);

	return 1;
}
