#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage, sword;

        if(!me->is_fighting())
                return notify_fail("天魔剑气只能在战斗中使用。\n");
        if( !target) target = offensive_target(me);
        if( !target ||  !target->is_character() ||  !me->is_fighting(target) )
                return notify_fail("「天魔剑气」只能对战斗中的对手使用。\n");

        if( !objectp(weapon = me->query_temp("weapon"))
           || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，怎能运用「天魔剑气」？！\n");

        if (weapon->query("unique"))
                return notify_fail("你手中之剑已是锋利之极，使用「天魔剑气」没有什么作用！\n");

        if( me->query_temp("tianmojianqi") )
                return notify_fail("你刚使完「天魔剑气」，目前气血翻涌，无法再次运用！\n");

        if((int)me->query_skill("tianmo-sword", 1) < 150
        || (int)me->query_skill("sword", 1) < 150
        || (int)me->query_str() <= 40 )
                return notify_fail("你修为还不够，还未能领悟「天魔剑气」！\n");

        if( me->query_skill("tianmo-dafa", 1) < 150 )
                return notify_fail("你的内功修为火候未到，施展只会伤及自身！\n");

        if( me->query_skill_mapped("force") != "tianmo-dafa")
                return notify_fail("你所用的内功与「天魔剑气」心法相悖！\n");

        if (me->query_skill_mapped("sword") != "tianmo-sword" ||
            me->query_skill_mapped("parry") != "tianmo-sword")
                return notify_fail("你现在无法使用「天魔剑气」进行攻击。\n");

        if( me->query("max_neili") <= 2000 )
                return notify_fail("你的内力修为不足，劲力不足以施展「天魔剑气」！\n");

        if( me->query("neili") <= 600 )
                return notify_fail("你的内力不够，劲力不足以施展「天魔剑气」！\n");

        if( me->query("jingli") <= 200 )
                return notify_fail("你的精力有限，不足以施展「天魔剑气」！\n");

        message_vision(HIW"\n刷的一声响，$N潜运内力将"+weapon->name()+HIW"一抖。这一下使得天魔剑气纵横，竟然声震山谷。不明其理之人，无不骇异！\n\n" NOR, me);

        damage = me->query_skill("sword");
        damage = damage/3;
        sword = me->query_skill("sword")/3;
        if ( userp(me) ) {
                me->add("neili", -300);
                me->add("jingli", -50);
                if ( damage > weapon->query("weapon_prop/damage") * 4)
                        damage = weapon->query("weapon_prop/damage") * 4;
                else weapon->add("rigidity", 1);
        }

        me->set_temp("tianmojianqi", 1);
        me->add_temp("apply/damage", damage);
        me->add_temp("apply/attack", damage);
        call_out("remove_effect1", sword/4, me, weapon, damage);
        call_out("remove_effect2", sword*4/5, me);
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
        message_vision("\n$N一套「天魔剑法」使完，手中"+weapon->name()+"上的光芒渐渐也消失了。\n", me);
        weapon->add("jianqi", 1);
        if (weapon && weapon->query("jianqi") >= (3+weapon->query("rigidity"))) {
                message_vision(HIW"\n只听“嚓”的一声，$N手中的$n"HIW"被内力冲击，裂成了碎片！\n"NOR,me,weapon);
                weapon->unequip();
                weapon->move(environment(me));
                weapon->set("name", "碎裂的" + weapon->query("name"));
                weapon->set("value", 49);
                weapon->set("weapon_prop", 0);
                me->reset_action();
        }
}

void remove_effect2(object me)
{
        if (!me) return;
        me->delete_temp("tianmojianqi");
        tell_object(me, HIG"\n你经过一段时间调气养息，又可以使用「天魔剑气」了。\n"NOR);
}


