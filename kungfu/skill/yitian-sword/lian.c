// lian.c
// 连剑式
#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i,lvl,attack_time;
        
        lvl = (int)me->query_skill("yitian-sword",1);
        if( lvl <= 150) attack_time = 4;
        if( lvl <= 250 && lvl > 150 ) attack_time = 6;
        if( lvl <= 350 && lvl > 250 ) attack_time = 8;
        if( lvl > 350 ) attack_time = 12;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("「连剑式」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");
        if((int)me->query_dex() < 30)
                return notify_fail("你的身法不够, 目前还不能使用这项绝技！\n");
        if((int)me->query_skill("force",1) < 150)
                return notify_fail("你的内力修为不够, 不能使用这一绝技！\n");
        if((int)me->query_skill("linji-zhuang",1) < 150)
                return notify_fail("你的临济十二庄功修为不够, 不能使用这一绝技！\n");
        if((int)me->query_skill("yitian-sword",1) < 150)
                return notify_fail("你的剑法修为不够，目前不能使用连剑式！\n");
        if( (int)me->query("neili") < 400)
                return notify_fail("你的内力不够！\n");

        me->clean_up_enemy();
        msg = HIW"$N默念口决，身子一轻，顷刻间舞出数道剑花、剑光闪闪！\n" NOR;
        message_vision(msg, me,target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
        msg = CYN"结果$p被$P攻了个措手不及！\n" NOR;
        message_vision(msg, me,target);
        for(i = 0; i < attack_time; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                if (!weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set_temp("action_flag",0);
        }else break;
        me->add("neili", -400);
        me->start_busy(4);
        }
        else {
                msg = "$p纵身跳开，躲开了$P的攻击。\n" NOR;
                me->start_busy(5);
                message_vision(msg, me,target);
        }
        return 1;
}
