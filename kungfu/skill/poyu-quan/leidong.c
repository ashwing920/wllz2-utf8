// leidong.c 雷动九天
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int improve, improve1;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("雷动九天只能对战斗中的对手使用。\n");

        if( objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你必须空手才能使用雷动九天！\n");

        if( (int)me->query_skill("poyu-quan", 1) < 120 )
                return notify_fail("你的混元掌不够娴熟，不会使用雷动九天！\n");

        if( (int)me->query_skill("zixia-shengong", 1) < 150 )
                return notify_fail("你的紫霞神功不够高，不能用出雷动九天伤敌。\n");

        if(me->query_skill_mapped("cuff") != "poyu-quan")
                return notify_fail("你现在无法使用「雷动九天」进行攻击。\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("你现在内力太弱，无法使出雷动九天。\n");

        if( me->query_temp("leidong"))
                return notify_fail("你正在使用雷动九天！\n");

        msg = HIM"$N使出劈石破玉拳的绝学雷动九天，顿时天空电闪雷鸣！\n"NOR;
        message_vision(msg, me);

        improve = (int)me->query("str");
        improve1 = (int)me->query("dex");
        me->add_temp("apply/strength", improve);
        me->add_temp("str",improve);
        me->add_temp("apply/dexerity", improve1);
        me->add_temp("dex",improve1);
        me->set_temp("leidong",1);
        me->add("neili", - 200);
        target->start_busy(random( (int)me->query_skill("leidong") / 20 + 2 ) );
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,improve,improve1:),me->query_skill("dodge",1) );
        return 1;
}

void remove_effect(object me,int improve,int improve1)
{
        me->add_temp("apply/strength",-improve);
        me->add_temp("str",-improve);
        me->add_temp("apply/dexerity",-improve1);
        me->add_temp("dex",-improve1);
        me->delete_temp("leidong");
}
