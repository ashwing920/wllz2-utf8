#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage, club;

        if( !target ) target = offensive_target(me);
        if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("「雷动九天」只能对战斗中的对手使用。\n");

        if( !objectp(weapon = me->query_temp("weapon"))
        || weapon->query("skill_type") != "club" )
                return notify_fail("你手中无棍，怎能运用「雷动九天」？！\n");

        if( me->query_temp("sl_leidong"))
                return notify_fail("你刚使完「雷动九天」，目前气血翻涌，无法再次运用！\n");

        if( (int)me->query_skill("weituo-gun", 1) < 150
        || (int)me->query_str() <=30 )
                return notify_fail("你修为还不够，还未能领悟「雷动九天」！\n");

        if( me->query_skill("yijinjing", 1) < 150 )
                return notify_fail("你的内功修为火候未到，施展只会伤及自身！\n");

        if( me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("你所用的内功与「雷动九天」心法相悖！\n");

        if (me->query_skill_mapped("club") != "weituo-gun")
                return notify_fail("你现在无法使用「雷动九天」进行攻击。\n");

        if( me->query("max_neili") <= 2000 )
                return notify_fail("你的内力修为不足，劲力不足以施展「雷动九天」！\n");

        if( me->query("neili") <= 600 )
                return notify_fail("你的内力不够，劲力不足以施展「雷动九天」！\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力有限，不足以施展「雷动九天」！\n");

        message_vision(HIR"\n突然$N大喝一声：「雷动九天」，面色唰的变得通红，须发皆飞，真气溶入"+weapon->name()+HIR"当中，“嗡”的一声，发出"HIW"闪闪光亮"HIR"！\n" NOR, me);

        damage = me->query_skill("weituo-gun", 1) + me->query_skill("buddhism",1);
        damage /= 3;
        club = me->query_skill("club")/3;
        if ( userp(me) ) {
                me->add("neili", -300);
                me->add("jingli", -50);
                if ( damage > 400)
                        damage = 400;
                else weapon->add("rigidity", 1);
        }

        me->set_temp("sl_leidong", 1);
        me->add_temp("apply/damage", damage);
        me->add_temp("apply/attack", damage);

        me->start_call_out( (: call_other, __FILE__, "remove_effect1",me,weapon,damage :), club/2);
        me->start_call_out( (: call_other, __FILE__, "remove_effect2",me :), club*2/3);

        return 1;
}

void remove_effect1(object me, object weapon, int damage)
{
        if (!me) return;
        me->add_temp("apply/attack", -damage);

        if (!weapon) {
                me->set_temp("apply/damage", 0);
                return;
        }
        me->add_temp("apply/damage", -damage);
        message_vision(HIY"\n$N一套「雷动九天」使完，手中"NOR+weapon->name()+HIY"上的光芒渐渐也消失了。\n"NOR, me);
}

void remove_effect2(object me)
{
        if (!me) return;
        me->delete_temp("sl_leidong");
        tell_object(me, HIG"\n你经过一段时间调气养息，又可以使用「雷动九天」了。\n"NOR);
}
