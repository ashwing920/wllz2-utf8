// ktpd.c  开天劈地

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg,w_name;
        int i,lvl,attack_time;

        lvl = (int)me->query_skill("jinwu-daofa",1);
        if( lvl <= 150) attack_time = 4;
        if( lvl <= 250 && lvl > 150 ) attack_time = 6;
        if( lvl <= 350 && lvl > 250 ) attack_time = 8;
        if( lvl > 350 ) attack_time = 12;
 
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
               return notify_fail("「开天劈地」只能在战斗中使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("「开天劈地」开始时必须拿着一把刀！\n");

        if((int)me->query("neili") < 200 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query_skill("blade",1) < 150 )
                return notify_fail("你的基本刀法还没到家，无法使用开天劈地！\n");

        if((int)me->query_skill("jinwu-daofa",1) < 150)
                return notify_fail("你的金乌刀法还没到火候，无法发挥出开天劈地的威力。\n");

        if((int)me->query_skill("jiuyang-shengong",1) < 150)
                return notify_fail("你的九阳神功修为不够，无法使用开天劈地！\n");

        weapon = me->query_temp("weapon");
        w_name = weapon->query("name");

        message_vision(HIY"$N手举"+ w_name + HIY +"，暴喝一声「开天劈地」，"+ w_name + HIY"泛起一片刀光，直向$n飞去！\n"NOR,me,target);
        me->clean_up_enemy();
        ob = me->select_opponent();
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
        msg = CYN "结果$p被$P攻了个措手不及！\n" NOR;
        message_vision(msg, me,target);
        for(i = 0; i < attack_time; i++)
                if(me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                if(!weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set_temp("action_flag",0);
        }else break;
                me->add("neili", -200);
                me->start_busy(2);
        }
        else
                {
                msg = "$p轻身闪开，躲避了$P凶猛的招式。\n" NOR;
                message_vision(msg, me,target);
                me->add("neili",-400);
                me->start_busy(5);
        }

        return 1;
}
