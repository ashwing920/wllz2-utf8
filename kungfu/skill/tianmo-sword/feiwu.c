#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i,skill;
        skill = (int)me->query_skill("tianmo-sword");

        if(!me->is_fighting())
                return notify_fail("天魔飞舞只能在战斗中使用。\n");

        if( !target ) target = offensive_target(me);
        if( !target||  !target->is_character()||  !me->is_fighting(target) || !living(target))
                return notify_fail("天魔飞舞攻击只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("tianmo-sword", 1) < 150 )
                return notify_fail("你的天魔剑法还不够娴熟，无法使用天魔飞舞。\n");

        if( (int)me->query_skill("sword", 1) < 150 )
                return notify_fail("你的基本剑法功力太浅，无法使用天魔飞舞。\n");

        if( (int)me->query_skill("tianmo-dafa", 1) < 150 )
                return notify_fail("你的天魔大法功力太浅，无法使用天魔飞舞。\n");

        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("你的内力修为不够，无法使用天魔飞舞。\n");

        if( (int)me->query("neili") < skill )
                return notify_fail("你的内力不够，无法使用天魔飞舞。\n");

        if (me->query_skill_mapped("force") != "tianmo-dafa")
                return notify_fail("你必须以天魔大法为基础才可以发挥天魔飞舞的威力。\n");

        if (!(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "sword"
        || me->query_skill_mapped("sword") != "tianmo-sword")
                return notify_fail("你使得了天魔剑法的绝技吗？\n");

        if( me->query_temp("tiammofeiwu"))
                return notify_fail("你刚使完「天魔飞舞」，目前气血翻涌，无法再次运用！\n");
        
        me->add("neili", -skill);
        message_vision(HIR"\n$N突然暴喝一声，“哇”的吐出一口鲜血，紧接着举剑挺刺，在半空中划出道道血光，\n空中气劲激荡，阵阵剑气夹带着血腥向$n奔袭而去！\n" NOR,me, target);

        me->add_temp("apply/damage", skill);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        me->start_busy(2+random(3));
        me->add_temp("apply/damage", -skill);
        me->set_temp("tiammofeiwu", 1); 
        i = (int)me->query_skill("sword")/30;
        if( 15 - i <= 4) i = 4;
        call_out("remove_effect", i, me);
        me->start_busy(1);
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("tiammofeiwu");
        tell_object(me, HIG"\n你经过一段时间调气养息，又可以使用「天魔飞舞」了。\n"NOR); 
}
