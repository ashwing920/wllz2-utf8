// snowman

#include <ansi.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg, dodge_skill;
        int p;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target)|| !living(target))
                return notify_fail("寒冰真气只能在战斗中使用。\n");

        if(me->query_temp("weapon"))
                return notify_fail("你必须空手才能使用寒冰真气。\n");
        if((int)me->query_skill("hanbing-mianzhang", 1) < 150 )
                return notify_fail("你的寒冰绵掌修为不够。\n");

        if((int)me->query_skill("force", 1) < 150 )
                return notify_fail("你的基本内功修为不够。\n");

        if(me->query_skill_mapped("force") != "jiuyang-shengong")
                return notify_fail("你没有运用九阳神功呢！\n");

        if(me->query_skill_mapped("strike") != "hanbing-mianzhang")
                return notify_fail("你没有运用寒冰绵掌！\n");

        if( me->query("max_neili") <= 1500 )
                return notify_fail("你的内力修为不够！\n");

        if( me->query("neili") <= 500 )
                return notify_fail("你的内力不够！\n");

        message_vision(BLU "\n$N将已修练了十余年的“寒冰真气”注于食指之上，拚着大耗内力，手指一伸，飞点$n的胸口！\n\n" NOR, me,target);
        me->add("neili", -350);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*6/11){
                me->add("max_neili", - (1+random(3)));
                message_vision("结果$n促不及防，被$P一指点在胸前大穴上！\n", me, target);
                if( me->query_skill("hanbing-mianzhang", 1) < target->query_skill("hanbing-mianzhang", 1) * 2){
                        tell_object(me, HIR "你一指点在" +target->query("name") +"胸口，不料此人竟然也练有寒冰真气，看来你这指是无效了。\n"NOR);
                        tell_object(target, HIY "你只觉一股寒气袭胸，立即全力运功，竟然抗住了寒气的侵袭！\n" NOR);
                        return 1;
        }
                else    {
                        tell_object(me, BLU"你一指点在" +target->query("name") +"胸口，待其运内力抵抗，将寒毒顺他“天池穴”直逼过去！" +target->query("name") +"体内。\n"NOR);
                        tell_object(target,HIW"你只觉一股寒气袭胸，立即全力运功，不料一瞬之间，寒气已将你全身冻僵！\n"NOR);
                        target->receive_damage("qi", me->query_skill("strike"),me);
                        target->receive_wound("jing", me->query_skill("hanbing-mianzhang",1),me);
                        target->apply_condition("cold_poison", me->query_skill("hanbing-mianzhang", 1)*2);
                        p = (int)target->query("qi")*100/(int)target->query("max_qi");
                        msg = damage_msg(me->query_skill("strike"), "内伤");
                        msg += "「$n"+eff_status_msg(p)+"」\n";
                        message_vision(msg, me, target);
                        return 1;
                }
        }
        else {
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
        }
        me->start_busy(2+random(3));
        return 1;
}
