// sanjiao.c 三焦齐逆诀

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("qishang-quan",1) + me->query_skill("jiuyang-shengong",1);

        if( !me->is_fighting() )
                return notify_fail("「三焦齐逆诀」只能在战斗中使用。\n");

        if( (int)me->query("neili") < 300)
                return notify_fail("你的内力不够了！\n");

        if( (int)me->query_skill("cuff",1) < 100 )
                return notify_fail("你的拳法还不到家，无法体现七伤拳的各种总诀！\n");

        if( (int)me->query_skill("qishang-quan", 1) < 100)
                return notify_fail("你七伤拳的修为不够，不能够体会三焦齐逆诀！ \n");

        if( (int)me->query_skill("jiuyang-shengong", 1) < 100)
                return notify_fail("你的九阳神功修为不足，不能随便使用三焦齐逆诀！ \n");

        if( me->query_skill_mapped("cuff") != "qishang-quan")
                return notify_fail("你没有激发七伤拳，无法运用三焦齐逆诀！\n");

        msg = HIY "$N凝神定气，企图使出七伤拳总诀中的「" HIR "三焦齐逆诀" HIY "」，将敌方招数反弹！\n"NOR;
        message_vision(msg, me, target);

        ap = me->query("combat_exp") + skill * 400;
        dp = target->query("combat_exp") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                me->add("neili",- 300);
                msg = HIR "$n只觉得胸前一阵剧痛，“哇”的一声喷出一口鲜血！\n"NOR;
                message_vision(msg, me, target);
                neili_wound = 100 + random(skill);
                if(neili_wound > target->query("neili"))
                neili_wound = target->query("neili");
                target->add("neili", -neili_wound);
                qi_wound = neili_wound / 2 + me->query_str();
                target->receive_damage("qi",qi_wound,me);
                target->start_busy(2);
                me->start_busy(random(3));
        }
        else
        {
                msg = HIW"只见$n不慌不忙，轻轻一闪，躲过了$N的必杀一击！\n"NOR;
                message_vision(msg, me, target);
                me->add("neili",- 100);
                me->start_busy(2);
        }
        return 1;
}
