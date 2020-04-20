// tan.c 六脉神剑 - 弹

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        object ob;
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target ||  !target->is_character() ||  !me->is_fighting(target))
                return notify_fail("「弹」字决指法只能对战斗中的对手使用。\n");

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你不能使用武器！\n");

        if (! objectp(ob = target->query_temp("weapon")))
                return notify_fail("对方并没有武器，你不用担心！\n");

        if( (int)me->query_skill("liumai-shenjian", 1) < 120 )
                return notify_fail("你的六脉神剑太生疏，不会使用「弹」字决。\n");

        if((int)me->query_skill("kurong-changong",1) < 150)
                return notify_fail("你的枯荣禅功不够娴熟，无法使用六脉神剑特殊攻击法！\n");

        if ( me->query("neili") < 200)
                return notify_fail("你的内力不够，现在无法使用「弹」字决。\n");

        me->clean_up_enemy();
        me->add("neili", - 200);
        msg = HIY "$N长出一口气，使出六脉神剑「弹」式，一道犀利无比的剑气直奔$n而去。\n";
        me->start_busy(2);
        if( random( me->query_skill("force")) > random((int)target->query_skill("force"))){
                if (ob->query("ownmake")){
                        msg += HIR " $p忙用" + ob->query("name") + "招架，只觉得虎口剧震，所幸兵器完好无损。\n" NOR;

                        }
                else
                        {
                        msg += HIW " $p连忙招架，只听见「啪」地一声，$p手中的" + ob->name()+ "已经断为数截，激飞上天！\n" NOR;
                        ob->unequip();
                        ob->move(environment(target));
                        ob->set("name", "断掉的" + ob->query("name"));
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                }
                target->start_busy(2);
        }
                else
                        {
                        msg += "$p真气贯注" + ob->query("name") + "，和$P剑气相交，冒出点点火光。\n" NOR;
                }
        message_vision(msg, me, target);

        return 1;
}
