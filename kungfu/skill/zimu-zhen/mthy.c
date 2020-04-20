// mthy.c 漫天花雨

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill,throw,i;

        skill = me->query_skill("zimu-zhen",1);
        
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("「漫天花雨」只能在战斗中用在对手身上。\n");

        if(!me->is_fighting())
                return notify_fail("「漫天花雨」只能在战斗中用在对手身上。\n");

        if( me->query("family/family_name") != "唐门")
                return notify_fail("「漫天花雨」乃是唐门独门绝技，你是从哪学来的？\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "throwing")
                return notify_fail("你使用的武器不对。\n");

        if( skill < 250)
                return notify_fail("你的子母针法不够纯熟, 不能使用「漫天花雨」！\n");

        if (me->query_skill("biyun-xinfa",1) < 200)
                return notify_fail("你的碧云心法不够娴熟，无法使用漫天花雨。\n");

        throw = weapon->query_amount() / 3;
        if(throw < 30)
                return notify_fail("你身上的"+ weapon->name()+"太少了，无法发挥「漫天花雨」！\n");

        if( me->query("neili") < 600)
                return notify_fail("你的内力不够，无法运用「漫天花雨」！\n");

        me->clean_up_enemy();
        msg = HIR "$N并指如刀，指缝间夹着数枚暗器，一式「漫天花雨」，密密麻麻的数枚一并向$n射去。\n"NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
        msg += CYN "结果$p被$P攻了个措手不及！\n" NOR;
        message_vision(msg, me, target);
        if(throw > 20) throw = 20;

        for(i = 0; i < throw; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                if (!weapon->query("equipped")) break;
                me->set_temp("action_flag",1);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set_temp("action_flag",0);
        }else break;
                me->add("neili", -400);
                me->start_busy(3);
        }
        else {
                msg += "$p十分轻巧，轻身闪开，避开了$P凶猛的攻击。\n" NOR;
                message_vision(msg, me,target);
                me->start_busy(5);
        }
        return 1;
}
