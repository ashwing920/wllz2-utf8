// ba.c　四两拔千斤

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int extra;
        object weapon;
        string msg;
        extra = me->query_skill("lonely-sword",1);

        if( !target) target = offensive_target(me);
        if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("「封穴式」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if ( extra < 300) 
                return notify_fail("你的独孤九剑还不够纯熟！\n");

        if ( me->query("max_neili") < 1000)
                return notify_fail("你的内力修为不够，不能使出「封穴式」！\n");

        if ( me->query("neili") < 400 ) 
                return notify_fail("你的内力不足！\n");

                       
        me->clean_up_enemy();
        weapon = me->query_temp("weapon");
        msg = weapon->query("name");
        message_vision(HIY"\n只见$N手中"+ msg +"剑芒乍现，化做数道剑影，向$n飞去，$N随口念道：封穴式！！\n" NOR, me, target);
        if( random(me->query("combat_exp")) > target->query("combat_exp") / 2) {
                message_vision(HIW"突然，一阵刺眼的光芒凝聚一起，$N手中的"+ msg+ HIW"不偏不倚点中了$n的气海穴。\n"NOR,me,target);
                tell_object(target,YEL"你只觉得浑身气力溃散，头晕目眩.......\n"NOR);
                target->apply_condition("no_exert",target->query_condition("no_exert") + 10);
                target->receive_wound("qi",extra);
                me->start_busy(2);
                me->add("neili",- 400);
        }
                else {
                        message_vision(CYN"可是$n早以识破了$N的招数，轻身躲避，顿时跳开数丈之外。\n"NOR,me,target);
                        me->add("neili",-400);
                        me->start_busy(4);
                }
        return 1;
}

