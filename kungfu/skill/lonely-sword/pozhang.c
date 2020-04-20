// pozhang.c 「破掌式」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg,weapon_name;
        object weapon, weapon2, target;
        int skill, ap, dp, wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = (int)me->query_skill("lonely-sword",1);

        if(!me->is_fighting())
                return notify_fail("「破掌式」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("对方手里拿了武器，你用不了「破掌式」。\n");

        if( skill < 100)
                return notify_fail("你的独孤九剑等级不够, 不能使用「破掌式」！\n");

        if( me->query("neili") <(int)me->query("max_neili") / 20)
                return notify_fail("你的内力不够，无法运用「破掌式」！\n");

        msg = HIC "$N使出独孤九剑之「破掌式」, 劲力聚在剑尖，企图以意使剑.\n";
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 1000;
        dp = target->query("combat_exp") / 4;
        weapon_name = weapon->query("name");
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
        if(userp(me))
        
        me->add("neili",-(int)me->query("max_neili") / 20);
        msg = HIR"$N运起「破掌式」, 手中"+ weapon_name +HIR"猛的往$n手掌刺去，一道血口在$n手中裂开。\n"NOR;

        wound = (int)me->query_skill("sword",1)/2 + skill;
        wound = wound/2 + random(wound);
                me->start_busy(random(2));
                target->receive_damage("qi",wound,me);
                target->start_busy(2);
        }
        else
        {
                if(userp(me))
                me->add("neili",- (int)me->query("max_neili") / 20);
                msg = "可是$n看破了$N的企图，全力防守，堪堪抵住了$N的攻势。\n"NOR;
                me->start_busy(random(3));
        }
        message_vision(msg, me, target);
        return 1;
}
