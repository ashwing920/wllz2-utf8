// chan.c 「缠」字诀

#include <ansi.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target))
                return notify_fail("正两仪剑法「缠」字诀只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if(me->query("neili") < 200)
                return notify_fail("你的内力不够了。\n");

        if(living(target) && target->is_busy())
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
                
        if( (int)me->query_skill("zhengliangyi-sword", 1) < 120 )
                return notify_fail("你的正两仪剑法不够娴熟，不会使用「缠」字诀。\n");

        msg = HIC"$N使出正两仪剑法「缠」字诀，剑意圈转，手中"+ weapon->name() + HIC"化做数道剑影，\n连绵不绝，连递数个虚招企图扰乱$n的攻势。\n"NOR;

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/ 2 ) {
                msg += HIR"$p被$P闹个手忙脚乱，惊慌失措，呆在当场，不知如何应对！\n" NOR;
                target->start_busy( (int)me->query_skill("zhengliangyi-sword",1) / 40 );
        } else {
                msg += "可是$p看破了$P的企图，镇定逾恒，全神应对自如。\n" NOR;
                me->start_busy(3);
        }
        message_vision(msg, me, target);
        me->add("neili",-200);
        return 1;
}
