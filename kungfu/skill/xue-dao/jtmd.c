// xue-dao.c  绝天灭地

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;
 
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
               return notify_fail("「绝天灭地」只能在战斗中使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("「绝天灭地」开始时必须拿着一把刀！\n");

        if((int)me->query("neili") < 200 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query_skill("blade",1) < 150 )
                return notify_fail("你的基本刀法还没到家，无法使用绝天灭地！\n");

        if((int)me->query_skill("xuehai-mogong",1) < 150)
                return notify_fail("你的血海魔功还没到火候，无法发挥出灭天绝地的威力。\n");

        if((int)me->query_skill("xue-dao",1) < 150)
                return notify_fail("你的血刀刀法还没到火候，无法发挥出灭天绝地的威力。\n");

        msg=HIY"$N使出血刀绝技「绝天灭地」，大喝一声，顿时日月无光，到处一片猩红，刀风掌影扑面而来！\n"NOR;
        message_vision(msg, me);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/ 20){
        target->start_busy(1);
        msg = CYN"结果$p被$P攻了个措手不及！\n" NOR;
        message_vision(msg, me, target);
        for(i = 0; i < 5; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                if (!weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set_temp("action_flag",0);
        }else break;
        me->add("neili", -200);
        me->start_busy(2);
        } else {
                msg = "可是$p看破了$P的企图，并没有上当。\n" NOR;
                message_vision(msg, me, target);
                me->start_busy(random(4));

        }
        return 1;
}
