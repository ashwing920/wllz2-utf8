// riyue.c -「日月无光」

#include <ansi.h>

inherit F_SSERVER;
void remove_effect(object me);
int perform(object me, object target)
{
        object weapon;
        int damage,time;
        string dodge;

        if( !me->is_fighting())
                return notify_fail("日月无光只能在战斗中使用。\n");

        if( !target ) target = offensive_target(me);
        if( !target||!target->is_character()||!me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用「日月无光」。\n");

        if((int)me->query_skill("beiming-shengong",1) < 200)
                return notify_fail("你的北冥神功修为不够，无法使用日月无光。\n");

        if( me->query_skill_mapped("blade") != "ruyi-dao")
                return notify_fail("你没有激发如意刀，如何能使用日月无光？\n");

        if( (int)me->query_skill("ruyi-dao",1) < 120)
                return notify_fail("你目前功力还使不出「日月无光」。\n");


        if(!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你的兵器类型不对！\n");

        if((int)me->query("max_neili") < 1000)
                return notify_fail("你的内力修为不够。\n");

        if( (int)me->query("neili") < 300)
                return notify_fail("你的内力不够。\n");

        time = (int)me->query_skill("ruyi-dao") / 60;
        me->add("neili", -300);
        me->clean_up_enemy();
        if( me->query_skill_mapped("dodge"))
        dodge = to_chinese((string)me->query_skill_mapped("dodge"));
        else
        dodge = "绝顶轻功";

        message_vision(HIY"只见$N运起"+ dodge +"，凌空跃起，暴喝一声：日月无光！一片刀光凌空向$n飞去！\n"NOR,me,target);

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 ) {
                message_vision(HIW"\n天地之间突然为之变色，狂风骤起，风沙中夹带着$N的身影和片片刀光，耀得$n睁不开眼睛。\n\n"NOR,me,target);
                if(!target->is_busy()){
                        target->start_busy(time);
                }
                tell_object(target,HIW"一道耀眼的光束射入你的眼睛，你只觉得眼前一片白芒. . .\n"NOR);
                damage = (int)me->query_skill("ruyi-dao",1) + (int)me->query_skill("blade", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/4,me);
                me->start_busy(2);
                message_vision(HIR"$n闪躲不及，胸口被重重的划开了一刀，鲜血狂涌而出，喷得$N满脸！\n\n"NOR,me,target);
                me->set_temp("block_msg/all",1);
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me,3:));
        } else {
                message_vision(HIC"可是$p急忙抽身躲开，轻轻松松的躲开了$P的刀光。\n"NOR,me,target);
                me->start_busy(4);
        }
        COMBAT_D->report_status(target);
        return 1;
}
void remove_effect(object me)
{
        if(!me) return;
        if( me->query_temp("block_msg/all")){
                me->delete_temp("block_msg/all");
                message_vision(HIW"许久，$N抹了抹眼前的血迹，终于看清了眼前的一切。\n"NOR,me);
        }
}
int clean_up()
{
        return 1;
}
void reset()
{
}
