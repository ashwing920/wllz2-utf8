// zui.c
// 醉八打

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg, name;
        int i,lvl,attack_time;


        lvl = me->query_skill("zui-gun",1);
        if( lvl <= 150) attack_time = 4;
        if( lvl <= 250 && lvl > 150 ) attack_time = 6;
        if( lvl <= 400 && lvl > 250 ) attack_time = 8;
        else attack_time = 12;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("「醉八打」只能在战斗中使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "club")
                return notify_fail("你使用的武器不对。\n");
        if((int)me->query_skill("force",1) < 150)
                return notify_fail("你的内力修为不够, 不能使用这一绝技！\n");
        if((int)me->query_skill("zui-gun",1) < 150)
                return notify_fail("你的醉棍修为不够，目前不能使用醉八打！\n");
        if( (int)me->query("neili") < 400)
                return notify_fail("你的内力不够！\n");

        me->clean_up_enemy();
        name = weapon->query("name");
        msg = HIC "$N借助酒力，使出醉棍中的精髓醉八打，手中"+ name +"舞出数个棍花。\n" NOR;
        message_vision(msg, me,target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/ 4 ){
        msg = CYN"结果$n被$N攻了个措手不及！\n"NOR;
        message_vision(msg, me,target);
        for(i = 0; i < attack_time; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                        me->set_temp("action_flag",1);
                        if (!weapon->query("equipped")) break;
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0) ;
                        me->set_temp("action_flag",0);
                }else break;
                me->start_busy(3);
                me->add("neili", -400);
        }
        else
        {
                msg = "可是$p看破了$P的企图，并没有上当。\n" NOR;
                message_vision(msg, me, target);       
                me->start_busy(5);
        }
        return 1;
}
