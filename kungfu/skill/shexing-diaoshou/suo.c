// suo.c 锁喉

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, damage;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("「锁喉」只能对战斗中的对手使用。\n");

        if(!me->is_fighting())
                return notify_fail("「锁喉」只能对战斗中的对手使用。\n");

        if(objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你必须放下"+ weapon->name()+"才可以使用锁喉！\n");

        if( me->query_str() < 35 )
                return notify_fail("你的后天膂力太弱, 不能使用「锁喉」！\n");

        if( me->query_skill("huntian-qigong",1) < 150
        && me->query_skill("hamagong",1) < 150)
                return notify_fail("你的内功心法不够，不能使用锁喉！\n");

        if( me->query("jiali") < 10)
                return notify_fail("你的加力太少，无法给对手造成伤害。\n");

        skill = me->query_skill("shexing-diaoshou",1);

        if( skill < 150)
                return notify_fail("你的蛇形刁手等级不够, 不能使用「锁喉」！\n");

        if( me->query("neili") < 200)
                return notify_fail("你的内力不够，无法运用「锁喉」！\n");

        me->clean_up_enemy();
        msg = HIR"只见$N手法变幻异常，形如灵蛇，刚中带柔，瞬间向$n喉头抓去。\n"NOR;

        damage = skill + me->query_skill("hand") + me->query("jiali") * 2;
        ap = me->query_skill("hand")/3 + skill + me->query_str();
        dp = target->query_skill("dodge")/2;
        if( dp < 1 ) dp = 1;
        if( random(ap) > random(dp) ){
                me->add("neili",- 200);
                msg += HIR"$n闪躲不及，被$N紧紧扣住，“哇”的吐出一口鲜血。\n"NOR;
                me->start_busy(2);
                target->receive_wound("qi",damage,me);
                target->receive_damage("qi",damage / 2,me);
                target->start_busy(random(2));
        }
        else{
                msg += HIY"$n早已看穿了$N的攻势，轻身避开。\n"NOR;
                me->add("neili",- 100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        return 1;
}
