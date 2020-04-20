// pojian.c 破剑式

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = (int)me->query_skill("lonely-sword",1);

        if(!me->is_fighting())
                return notify_fail("「破剑式」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (!objectp(weapon2 = target->query_temp("weapon"))
        || (string)weapon2->query("skill_type") != "sword")
                return notify_fail("对方没有使剑，你用不了「破剑式」。\n");

        if( skill < 100)
                return notify_fail("你的独孤九剑等级不够, 不能使用「破剑式」！\n");

        if( me->query("neili") < (int)me->query("max_neili") / 20)
                return notify_fail("你的内力不够，无法运用「破剑式」！\n");

        msg = HIC "$N举剑画弧，默潜独孤九剑之「破剑式」, 绵绵剑意，漫天铺地袭向$n。\n";
        message_vision(msg, me, target);

        damage = 10 + random(skill / 2);
        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("sword") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                me->add("neili",-(int)me->query("max_neili") / 20 );
                msg = "$n顿时觉得眼前一花，手腕一麻，手中";
                msg += weapon2->name();
                msg += "脱手而出！\n" NOR;
                me->start_busy(random(2));
                target->receive_damage("qi", damage,me);
                target->start_busy(2);
                weapon2->move(environment(me));
                if (weapon2->query("ownmake")==1)
                {
                weapon2->move(target);
                msg += "那可是$n的随身家伙！$n手一伸将它捡回来。\n" NOR;
                }
        }
        else
        {
                if(userp(me))
                me->add("neili",-(int)me->query("max_neili") / 80);
                msg = "可是$n看破了$N的剑路，立刻将手中" + weapon2->name()+"舞得风雨不透，使$N的「破剑式」没有起到作用。\n"NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        return 1;
}
