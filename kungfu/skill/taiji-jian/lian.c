// lian.c 太极剑法「连」字诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time,lvl;

        lvl = me->query_skill("taiji-jian",1);
        if( lvl <= 150) attack_time = 4;
        if( lvl > 150  &&  lvl <= 250 ) attack_time = 6;
        if( lvl >= 250 &&  lvl <= 350 ) attack_time = 8;
        if( lvl > 350 ) attack_time = 12;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「连」字诀只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if( (int)me->query("neili") < 300)      
                return notify_fail("你的内力不够了！\n");
        if( (int)me->query_skill("taiji-jian", 1) < 120 )
                return notify_fail("你的太剑法极不够娴熟，不会使用「连」字诀。\n");

        if( (int)me->query_skill("taiji-shengong", 1) < 120 )
                return notify_fail("你的太剑神功火候不够，不能使用「连」字诀。\n");
        
        me->clean_up_enemy();
        msg = HIY"\n$N使出太极剑法「连」字诀，招式陡然变快。\n\n"NOR;
        message_vision(msg, me, target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/ 4 ){
        message_vision(HIC"$N紧跟着连续刺出"+ chinese_number(attack_time)+"剑，结果$n被$N攻了个措手不及！\n"NOR,me,target);
        for(i = 0; i < attack_time; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                        me->set_temp("action_flag",1);
                        if (!weapon->query("equipped")) break;
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0) ;
                        me->set_temp("action_flag",0);
                }else break;
                me->start_busy(3);
                me->add("neili", -300);
        }
        else
        {
                msg = "可是$p看破了$P的企图，并没有上当。\n" NOR;
                message_vision(msg, me, target);       
                me->start_busy(5);
        }
        return 1;
}
