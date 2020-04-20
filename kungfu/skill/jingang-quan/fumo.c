// fumo.c 大金刚拳 perform 金刚伏魔

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, string arg)
{
        object target;
        string msg;
        int i,z;
        i = (int)me->query_str() * 2;
        z = (int)me->query_skill("yijinjing",1)/5+(int)me->query_skill("jingang-quan",1)/4;

        if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("「金刚伏魔」只能在战斗中对对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手使用「金刚伏魔」！\n");

        if( (int)me->query_skill("jingang-quan",1) < 120 )
                return notify_fail("你的大金刚拳不够娴熟，不会使用「金刚伏魔」！\n");

        if( (int)me->query_skill("yijinjing",1) < 100 )
                return notify_fail("你的易筋经等级不够，不能使用「金刚伏魔」！\n");

        if(me->query_skill_mapped("force") != "yijinjing")
                    return notify_fail("你没有运用易筋经内功，无法使用「金刚伏魔」进行攻击。\n");

        if(me->query_temp("fenxin"))
                     return notify_fail("你现在正在使用焚心绝技，不能用「金刚伏魔」。\n");

        if( (int)me->query_str() < 28 )
                return notify_fail("你的臂力不够强，不能使用「金刚伏魔」！\n");

        if( (int)me->query("max_neili") < 1000 )
                return notify_fail("你的内力太弱，不能使用「金刚伏魔」！\n");

        if( (int)me->query("neili") < 700 )
                return notify_fail("你的内力太少了，无法使用出「金刚伏魔」！\n");

        if( me->query_skill_mapped("cuff") != "jingang-quan")
                    return notify_fail("你现在无法使用「金刚伏魔」进行攻击。\n");

        if( me->query_temp("fumo"))
                return notify_fail("你正在使用大金刚拳的特殊攻击「金刚伏魔」！\n");

        msg = HIR"$N突然全身骨骼作响，口中默念「金刚伏魔」，运起易筋经神功，脸上一阵红色，全身好象有使不完的力量一样！\n" NOR;

        message_vision(msg, me, target);
        me->add_temp("apply/strength", i);
        me->set_temp("fumo",1);
        me->add("neili", - 600);
        me->add("jingli", - 250);

        call_out("check_fight", 1, me, i, z);
        me->start_busy(1);
        return 1;
}
void remove_effect(object me, int i)
{
        if(me->query_temp("fumo")){
                me->add_temp("apply/strength", -i);
                me->delete_temp("fumo");
                tell_object(me,HIR"你的「金刚伏魔」运功完毕，你的脸色好看多了。\n"NOR);
        }

}
void check_fight(object me, int i, int z)
{

        if (!me) return;
        if (me->query_temp("weapon")
        || me->query_temp("secondary_weapon")
        || me->query_skill_mapped("cuff"!="jingang-quan")){
                remove_effect(me, i);
                return;
        }
        if (z < 1 || !me->is_fighting()) {
                remove_effect(me, i);
                return;
        }
        call_out("check_fight", 1, me, i, z-1);
}
