// zang.c
// 八方藏刀

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg,dodge_skill;
        int i;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("「八方藏刀」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("你使用的武器不对。\n");
        
        if((int)me->query_dex() < 30)
                return notify_fail("你的身法不够, 目前还不能使用这项绝技！\n");
        
        if((int)me->query_skill("force",1) < 150)
                return notify_fail("你的内力修为不够, 不能使用这一绝技！\n");

        if((int)me->query_skill("hujia-daofa",1) < 150)
                return notify_fail("你的刀法修为不够，目前不能使用八方藏刀！\n");

        if( (int)me->query("neili") < 400)
                return notify_fail("你的内力不足！\n");

        me->clean_up_enemy();
        msg = HIW"$N募的使出一招「八方藏刀」，顿时剑光中无数朵刀花从四面八方涌向$n全身！\n" NOR;
        message_vision(msg, me,target);
        if(( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4)) {
                msg = HIR"结果$p被$P攻了个措手不及！\n" NOR;
                message_vision(msg, me,target);
        for(i = 0; i < 8; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                if (!weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
                me->set_temp("action_flag",0);
                }else break;
                        me->add("neili", -400);
                        me->start_busy(4);
                }
                else {
                        dodge_skill = target->query_skill_mapped("dodge");
                        if( !dodge_skill ) dodge_skill = "dodge";
                        msg = HIC + SKILL_D(dodge_skill)->query_dodge_msg(target,1) + "\n"NOR;
                        message_vision(msg, me,target);
                        me->start_busy(5);
                }
        return 1;
}
