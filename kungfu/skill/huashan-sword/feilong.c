// feilong.c  华山剑法「天外飞龙」

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你必须装备剑才能使用「天外飞龙」！\n");
        if (!target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("「天外飞龙」只能对战斗中的对手使用。\n");
        if ((int)me->query_skill("huashan-sword", 1) < 120 )
                return notify_fail("你的华山剑法不够娴熟，使不出「天外飞龙」。\n");
        if ((int)me->query_skill("zixia-shengong", 1) < 120 )
                return notify_fail("你的紫霞神功火候不够，使不出「天外飞龙」。\n");
        if ((int)me->query("max_neili") < (int)me->query("max_neili")/ 20)
                return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);
        if ((int)me->query("neili") < (int)me->query("max_neili")/ 20){
                return notify_fail(HIC"你现在内力不够，没能将「天外飞龙」使完！\n"NOR);
        }
        msg = HIC "$N心念电闪，一提内力，勒手仗剑，运劲于臂，呼的一声向$n掷了出去，\n"NOR;
        if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ){
        me->start_busy(1);
        target->start_busy(random(3));
        damage = (int)me->query_skill("huashan-sword");
        target->receive_damage("qi", damage/10,me);
        target->receive_wound("qi", damage/10,me);
        msg += HIC"$n疾忙跃起，但剑如电闪，只觉一阵剧痛，剑刃拦腰而过，鲜血飞溅，皮肉卷起！\n"NOR;
        me->add("neili",(int)me->query("max_neili")/ 20);
        } else
        {
        me->start_busy(3);
        msg += HIY"可是$n轻轻一笑，侧身伸指，正弹在$N的剑脊上，剑斜飞落地。\n"NOR;
        me->add("neili", -200);
        }
        weapon->move(environment(me));
        message_vision(msg, me, target);
        return 1;
}
