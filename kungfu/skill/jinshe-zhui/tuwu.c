// tuwu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill;
        object weapon;

        if( !target ) target = offensive_target(me);
        if( !target ||!target->is_character() || !me->is_fighting(target) )
                return notify_fail("金蛇吐雾只能在战斗中使用。\n");

        if (me->query_temp("jinshe/tuwu"))
                return notify_fail("你才用的金蛇吐雾，没法接着就出招。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("id") != "jinshe zhui")
                return notify_fail("你没用金蛇锥，不能使用绝招！\n");

        if( (int)me->query_skill("jinshe-zhui", 1) < 120 )
                return notify_fail("你的金蛇锥法不够娴熟，不会使用金蛇吐雾。\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("你内力不够了。\n");

        skill = me->query_skill("jinshe-zhui", 1);
        me->clean_up_enemy();
        me->add("neili", -200);
        message_vision(
        HIY "只听一阵狂风扫叶般的声响中，$N手中的"YEL"金蛇锥"HIY"闪出夺目的光芒，闪耀得
$n眼冒金花，“金蛇吐雾”！除了眼前一重重的雾气外，$n啥也看不见了！\n" NOR, me, target);
        target->receive_damage("qi",(int)skill/ 4,me);
        me->set_temp("jinshe/tuwu", 1);
        target->set_temp("block_msg/all",1);
        call_out("tuwu_end",skill / 30,target);
        me->start_call_out( (: call_other, __FILE__,"tuwu_finish",me :),skill / 30);
        return 1;
}
void tuwu_end(object target)
{
        if(!target) return;
        target->set_temp("block_msg/all",0);
        message_vision("$N抹了抹满脸的"HIR"鲜血"NOR"，终于睁开了眼。\n", target);
        write(HIR"你终于抹掉了满脸的鲜血，看到了周围的情景。\n"NOR);
}
void tuwu_finish(object me)
{
        if(!me) return;
        me->delete_temp("jinshe/tuwu");
}
