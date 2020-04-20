// huanying.c  雁行刀法「无形幻影」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int i;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「无形幻影」只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("开什么玩笑，没装备刀怎么使「无形幻影」？\n");
        if ((int)me->query_skill("yanxing-dao", 1) < 120 )
                return notify_fail("你雁行刀法不够娴熟，使不出「无形幻影」。\n");
        if ((int)me->query_skill("linji-zhuang", 1) < 120 )
                return notify_fail("你临济庄火候不够，「无形幻影」不成招式。\n");
        if ((int)me->query("max_neili")< 200)
                return notify_fail("你的内力修为不足，无法运足「无形幻影」的内力。\n");
        if ((int)me->query("neili")< 200)
                return notify_fail(HIC"你现在内力不够，没能将「无形幻影」使完！\n");

        msg = HIC "$N大喝一声，全场四处游动，$n只看到$N化做数团身影，漫天刀\n"NOR;
        msg += HIC"光席卷而来，$n奋力一架，但$N刀分数路，$n只架住一刀！\n"NOR;

        me->clean_up_enemy();
        message_vision(msg, me, target);
        target->start_busy(2);
        for(i = 0; i < 5; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                if (!weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set_temp("action_flag",0);
        }else break;
        me->add("neili", -200);
        me->start_busy(4);
        return 1;
}
