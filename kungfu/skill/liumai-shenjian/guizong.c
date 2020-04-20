// liujian.c 六脉神剑   六剑齐发

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("六脉归宗只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能使用六脉归宗！\n");

        if( (int)me->query_skill("liumai-shenjian", 1) < 300 )
                return notify_fail("你的六脉神剑不够娴熟，不会使用六脉归宗。\n");

        if( me->query_skill("finger",1) < 200 )
                return notify_fail("你在指法上的造诣不够，无法使用六脉归宗。\n");

        if( me->query_skill("dodge",1) < 200 )
                return notify_fail("你在轻功上的造诣不够，无法使用六脉归宗。\n");

        if((int)me->query_skill("kurong-changong",1) < 200)
                return notify_fail("你的枯荣禅功不够娴熟，无法使用六脉神剑特殊攻击法！\n");

        if((string)me->query_skill_mapped("finger") != "liumai-shenjian")
                return notify_fail("你没有激发六脉神剑为指法，无法使用六脉归宗。\n");

        if((string)me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("你使用的内功心法与枯荣禅功相悖。\n");

        if((int)me->query("max_neili") < 1200 )
                return notify_fail("你的内力修为不够，不能使用六脉归宗。\n");

        if((int)me->query("neili") < 500)
                return notify_fail("你的内力不够发挥六脉归宗。\n");

        me->clean_up_enemy();
        message_vision(HIW"$N凌空跃起，使出了六脉神剑的最高绝技六脉归宗。六道金光疾射而出，射向$n！！！\n"NOR, me, target);
        msg = CYN"$N内力源源涌出，少商、商阳、中冲、关冲、少冲、少泽六脉剑法，$n抵御不住，顿时被剑气所创。\n"NOR;
        me->add("neili", -500);
        if(random(me->query("combat_exp")) > target->query("combat_exp") / 3){
                me->start_busy(3);
                target->start_busy(random(3));
                damage = (int)me->query_skill("force") + (int)me->query_skill("kurong-changong",1);
                damage = damage + random(damage);
                target->receive_damage("qi",damage*3,me);
                target->receive_wound("qi",damage,me);
                me->add("max_neili",-50);
                if( damage < 20 ) msg += HIY"结果$n受到$N的剑气击中，闷哼一声。\n"NOR;
                else if( damage < 40 ) msg += HIY"结果$n被$N的剑气击中，「嘿」地一声退了两步。\n"NOR;
                else if( damage < 80 ) msg += RED"结果$n被$N的剑气击中，胸口有如受到一记重锤，连退了五六步！\n"NOR;
                else msg += HIR"结果$n被$N的剑气击中，口中“哇”的吐出一口鲜血，身子如稻草人一般向后飞出丈许！！\n"NOR;
        }
        else
                {
                me->start_busy(6);
                msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}
