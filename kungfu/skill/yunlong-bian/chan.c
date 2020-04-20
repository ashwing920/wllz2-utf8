// chan.c 云龙鞭法 缠字诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg,dodge_skill;
        object weapon;

        if(!target) target = offensive_target(me);
        if(!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

        if(!objectp(weapon = me->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的兵器类型不对。\n");

        if((int)me->query("neili") < 200)
                return notify_fail("你的内力不够！\n");

        if((int)me->query_skill("yunlong-bian",1) < 150)
                return notify_fail("你的「云龙鞭法」功力太浅，使不了「缠」字诀！\n");

        if(target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

        msg = WHT"$N使出云龙鞭法「缠」字诀，手中"+ weapon->query("name")+ NOR + WHT"顿时化做长龙一般向$n缠绕而去。\n"NOR;

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 ) {
                me->add("neili",-200);
                msg += HIR"结果$p闪躲不及，被$P的"+ weapon->query("name")+ NOR + HIR"紧紧缠住，动弹不得！！\n" NOR;
                target->start_busy( (int)me->query_skill("yunlong-bian") / 60 + 1);
                me->start_busy(1+ random(2));
        } else {
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += HIC + SKILL_D(dodge_skill)->query_dodge_msg(target,1) + "\n"NOR;
                me->add("neili",-100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        return 1;
}
