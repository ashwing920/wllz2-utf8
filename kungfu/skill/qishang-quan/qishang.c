#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object target);
string *songs = ({
        HIY"五行之气调阴阳"HIR,
        HIY"损心伤肺摧肝肠"HIR,
        HIY"藏离精失意恍惚"HIR,
        HIY"三焦齐逆兮魂魄飞扬"HIR,
});
int perform(object me, object target)
{
        string msg, song;
        song = songs[random(sizeof(songs))];

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
        || !me->is_fighting(target) || !living(target) )
                return notify_fail("「七伤总诀」只能在战斗中对对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手使用「七伤总诀」！\n");

        if( (int)me->query_skill("qishang-quan",1) < 150 )
                return notify_fail("你的七伤拳不够娴熟，不会使用「七伤总诀」！\n");

        if(userp(me) && (int)me->query_skill("jiuyang-shengong",1) < 150 )
                return notify_fail("你的九阳神功等级不够，不能使用「七伤总诀」！\n");

        if(userp(me) && me->query_skill_mapped("force") != "jiuyang-shengong")
                return notify_fail("你没有九阳神功内功，无法使用「七伤总诀」进行攻击。\n");

        if( (int)me->query_con() < 28 )
                return notify_fail("你的身体不够强壮，不能使用「七伤总诀」！\n");

        if( (int)me->query("max_neili") < 1200 )
                return notify_fail("你的内力修为，不能使用「七伤总诀」！\n");

        if((int)me->query("jingli") < 300)
                return notify_fail("你的精力不够发挥七伤总诀！\n");

        if( (int)me->query("neili") < 700 )
                   return notify_fail("你的内力太少了，无法使用出「七伤总诀」！\n");

        if(target->query_temp("qishang"))
                return notify_fail("对方已经身受「七伤总诀」，你不用费劲了！\n");

        message_vision(HIR"\n突然$N眼射精光，朗声念出句似歌非歌、似诗非诗的拳诀：“"+song+"”，\n紧接着逼上前去，“砰”的一拳击向$n！\n"NOR,me, target);

        if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3 &&
                random((int)me->query_skill("force")) > (int)target->query_skill("force")/4){
                target->receive_damage("qi", me->query_skill("force"),me);
                me->add("neili", -400);
                me->add("jingli", -50);
                me->start_busy(2);
                target->start_busy(1);
        if((me->query("neili") + me->query("con")*20) < target->query("neili"))
                tell_object(me, HIR"你只觉"+target->name()+"体内内力极强，你暗藏在拳内的各种力道根本送不出去！\n"NOR);
        else{
                        tell_object(me, HIW"在刚一触到"+target->name()+"的身体时，你便暗暗发力，将隐藏在在拳内的七种力道送了过去！\n"NOR);
                        tell_object(target, HIW"你一晃眼，只见"+me->name()+"的拳已经打在你的身上，跟着几股说不出的暗劲顺势传了过来！\n"NOR);
                        target->set_temp("qishang", 1);
                        target->set_temp("apply/strength", -(target->query("str", 1)/2));
                        target->set_temp("apply/dexerity", -(target->query("dex", 1)/2));
                        target->set_temp("apply/intelligence", -(target->query("int", 1)/2));
                        target->set_temp("apply/constitution", -(target->query("con", 1)/2));
                        target->apply_condition("qishang_poison", 10+target->query_condition("qishang_poison"));
                        target->apply_condition("no_perform", me->query_skill("force", 1)/4);
                        target->start_call_out( (: call_other, __FILE__, "remove_effect", target :), me->query_skill("force")/2);
                }
                msg = "$n闪躲不及，被$N的招式打中！\n";
        }
        else
                {
                        me->start_busy(3);
                        me->add("neili", -(100+random(100)));
                        me->add("jingli", -200);
                        msg = HIY"只见$n轻轻一转身，已经绕到了$N身后。而$N却因劲力打空不受控制，头脑眩晕！\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;

}
void remove_effect(object target)
{
        if(!target) return;
        target->delete_temp("apply/strength");
        target->delete_temp("apply/dexerity");
        target->delete_temp("apply/intelligence");
        target->delete_temp("apply/constitution");
        target->clear_condition("no_perform");
        target->delete_temp("qishang");
        tell_object(target, HIW"终于，体内那几股暗劲在遍布你的全身后开始慢慢散去了。\n"NOR);
}
