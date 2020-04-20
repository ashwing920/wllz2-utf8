#include <ansi.h>

inherit F_SSERVER;

int perform(object me, string arg)
{
        object weapon, weapon1, target;
        int skill, skill1;

        if (!arg) return notify_fail("你想和谁一起双剑合壁？\n");
        if (!objectp(target = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if (target==me) return notify_fail("和自己合璧？\n");
        if ( !me->is_fighting() )
                return notify_fail("双剑合壁只能在战斗中使用。\n");
        if ( !target->is_fighting() )
                return notify_fail("双剑合壁只能与战斗中的伙伴一起使用。\n");
        if (me->is_fighting(target))
                return notify_fail("你正在和"+target->name()+"打架呢。\n");

        weapon = me->query_temp("weapon");
        weapon1 = target->query_temp("weapon");

        if(!weapon || weapon->query("skill_type") != "sword"
                || me->query_skill_mapped("sword") != "quanzhen-jian"
                || me->query_skill_mapped("parry") != "quanzhen-jian")
                return notify_fail("你现在无法使用「双剑合壁」。\n");

        if(!weapon1 || weapon1->query("skill_type") != "sword"
                || target->query_skill_mapped("sword") != "quanzhen-jian"
                || target->query_skill_mapped("parry") != "quanzhen-jian")
                return notify_fail(target->name()+"现在无法使用「双剑合壁」。\n");

        skill = me->query_skill("quanzhen-jian", 1);
        skill1 = target->query_skill("quanzhen-jian", 1);

        if(me->query("marry") != target->query("id")
        && target->query("marry") != me->query("id"))
                return notify_fail("双剑合壁只能夫妻之间相互配合才能使用。\n");

        if(skill < 200 )
                return notify_fail("你的全真剑法等级不够，不能使用「双剑合壁」。\n");

        if(me->query("neili") < 500 )
                return notify_fail("你现在真气太弱，不能使用「双剑合壁」。\n");
        if(target->query("neili") < 500 )
                return notify_fail("对方现在真气太弱，不能使用「双剑合壁」。\n");
        if(me->query("max_neili") < 1000 )
                return notify_fail("你的内力修为太弱，不能使用「双剑合壁」。\n");
        if(target->query("max_neili") < 1000 )
                return notify_fail("对方的内力修为太弱，不能使用「双剑合壁」。\n");

        if(me->query_temp("hebi"))
                return notify_fail("你已经在使用「双剑合壁」了。\n");

        if (me->query_temp("hebi_target")){
                if (me->query_temp("hebi_target")==target)
                        return notify_fail("你已经做好和"+target->name()+"双剑合壁的准备了。\n");
                else
                        tell_object(me->query_temp("hebi_target"), YEL+me->name()+"决定不和你进行双剑合壁了。\n"NOR);
        }
        if (target->query_temp("hebi_target") ==me){
                message_vision(HIM"\n$N将手中"+weapon->name()+HIM+"一摆，架在$n的"+weapon1->name()+HIM+"上，双刀相加，顿时光芒四射，声震天地！\n"NOR, me, target);
                me->set_temp("hebi_target", target);
                me->set_temp("hebi", 1);
                target->set_temp("hebi", 1);
                me->add("neili", -300);
                target->add("neili", -300);
                me->add("jingli", -50);
                target->add("jingli", -50);
                me->add_temp("apply/attack", skill);
                me->add_temp("apply/dodge", skill);
                me->add_temp("apply/damage", skill);
                target->add_temp("apply/attack", skill1);
                target->add_temp("apply/dodge", skill1);
                target->add_temp("apply/damage", skill1);
                call_out("check_fight", 1, me, skill, (skill+skill1)/20);
                call_out("check_fight", 1, target, skill1, (skill+skill1)/20);
                return 1;
        }
        message_vision(HIC"\n$N将手中"+weapon->name()+HIC"一横，暗示$n和$P一起运用双剑合壁。\n"NOR, me, target);
        tell_object(target, YEL"你如果愿意和"+me->name()+"一起施展双剑合壁，请也对"+me->name()+"下一次 perform hebi "+ me->query("id")+" 的命令。\n"NOR);
        me->set_temp("hebi_target", target);
        return 1;
}

void remove_effect(object me, int skill)
{
        if(me->query_temp("hebi")){
                me->add_temp("apply/attack", -skill);
                me->add_temp("apply/dodge", -skill);
                me->add_temp("apply/damage", -skill);
                me->delete_temp("hebi");
                me->delete_temp("hebi_target");
                message_vision(HIR"$N双剑合壁完结，攻守也恢复正常了。\n"NOR, me);
        }
}

void check_fight(object me, int skill, int count)
{
        object weapon;
        object target;

        if (!me) return;
        if (count < 1 || !me->is_fighting()) {
                remove_effect(me, skill);
                return;
        }
        target = me->query_temp("hebi_target");
        if (!target || !target->is_fighting()) {
                remove_effect(me, skill);
                return;
        }
        if (target->query_temp("hebi_target") != me) {
                remove_effect(me, skill);
                return;
        }
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword") {
                remove_effect(me, skill);
                return;
        }
        if (me->query_skill_mapped("sword") != "quanzhen-jian"
                || me->query_skill_mapped("parry") != "quanzhen-jian") {
                remove_effect(me, skill);
                return;
        }
        if(environment(me) != environment(target)) {
                remove_effect(me, skill);
                return;
        }
        call_out("check_fight", 1, me, skill, count-1);
}
