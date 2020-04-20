// spth.c -「石破天荒」

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg,dodge,weapon_name;

        if( !target ) target = offensive_target(me);
        if( !target||!target->is_character()||!me->is_fighting(target) )
                return notify_fail("你只能对战斗中的对手使用「石破天荒」。\n");
                
        if( (int)me->query_skill("fanliangyi-dao",1) < 150)
                return notify_fail("你目前反两仪刀还不够火候，不能使用「石破天荒」。\n");
                
        if((int)me->query_skill("zixia-shengong",1) < 150)
                return notify_fail("你的紫霞神功修为不够，无法使用「石破天荒」。\n");

        if(!objectp(weapon = me->query_temp("weapon")) || 
                (string)weapon->query("skill_type") != "blade")
                return notify_fail("你的兵器类型不对！\n");

        if( (int)me->query("neili") < 300)
                return notify_fail("你的内力不够。\n");
        
        me->add("neili", -300);
        me->clean_up_enemy();
        if( me->query_skill_mapped("dodge"))
        dodge = to_chinese((string)me->query_skill_mapped("dodge"));
        else
        dodge = "绝顶轻功";
        weapon_name = weapon->query("name");
        msg=HIW"只见$N运起"+ dodge +"， 手中"+ weapon_name + HIW"泛出一阵刺眼的光芒，飞起向$n砍去。\n"NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {

        damage = (int)me->query_skill("fanliangyi-dao", 1)+(int)me->query_skill("zixia-shengong", 1);
        damage += damage + random(damage);

        target->receive_damage("qi", damage,me);
        target->receive_wound("jing", damage/2,me);
                msg += HIR + weapon_name+"在$n的胸口划开，露出一道深可见骨的刀口。\n" NOR;
                me->start_busy(2);
        } else {
                msg += HIC "可是$p急忙抽身躲开，避开了$P的攻击。\n" NOR;
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        return 1;
}
