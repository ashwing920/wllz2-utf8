// huo.c
// 火云式

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg,name;
        int damage;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("「火云式」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
                
        if((int)me->query_skill("riyue-bian",1) < 150)
                return notify_fail("你的鞭法修为不够, 不能使用这一绝技！\n");

        if( (int)me->query("neili") < 400)
                return notify_fail("你的内力不够！\n");

        me->clean_up_enemy();
        name = weapon->name();
        msg = HIY"$N贯注内力，手中"+name+ HIY"轻扬，瞬间激起一道火花，"+ name +HIY"夹着风声朝$n袭去！\n" NOR;
        message_vision(msg, me,target);
        if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp") / 10) {
        msg = CYN"$n正想抽身闪避，却已经被攻了个措手不及！\n"NOR;
        message_vision(msg, me,target);
        damage = (int)me->query_skill("riyue-bian",1) + (int)me->query_skill("force",1);
        damage = random(damage)+ damage;
        target->receive_wound("qi",damage,me);
        target->receive_damage("jing",damage,me);
        COMBAT_D->report_status(target);
        me->add("neili", -400);
        me->start_busy(3);
        }
        else {
                msg = "$p轻身闪开，躲避了$P凶猛的招式。\n" NOR;
                message_vision(msg, me,target);
                me->start_busy(5);
        }
        return 1;
}
