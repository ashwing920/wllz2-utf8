// qixing. 七星绝命剑

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int damage;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("七星绝命剑只能对战斗中的对手使用。\n");

        if((int)me->query_skill("quanzhen-jian", 1) < 250 )
                return notify_fail("你的全真剑法不够熟练，使不出七星绝命剑。\n");
  
        if(!objectp(weapon = me->query_temp("weapon")) 
        || weapon->query("skill_type") != "sword")
                return notify_fail("你手中无剑，如何使用七星绝命剑？\n");
        
        if(me->query_skill_mapped("sword") != "quanzhen-jian")
                return notify_fail("你现在无法使用七星绝命剑。\n");

        if((int)me->query("neili") < 500)
                return notify_fail("你的内力不够，无法使用七星绝命剑。\n");

        if((int)me->query("jingli") < 400)
                return notify_fail("你的精力不足以使用七星绝命剑。\n");

        me->clean_up_enemy();
        msg = MAG "$N一声长啸，一抖手中剑，顿时形成一道剑幕，狂风暴雨般压向$n。\n就在$n慌乱之间，剑幕中飞出七朵寒星，如流星般射向$n。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += "$n躲闪不及，已然中剑！\n";
                damage = 4 * (int)me->query_skill("quanzhen-jian", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", damage,me);
                target->receive_wound("qi", damage/2,me);
                if( damage < 40 ) msg += HIY"$n已身中数剑，身上到处是血。\n"NOR;
                else if( damage < 80 ) msg += HIR"$n身中七剑，鲜血狂喷而出！\n"NOR;
                else msg += RED"$n“哇”的狂叫一声，身上喷出七道血剑！\n"NOR;
        } 
        else {
                msg += HIW"$n情急之中向后激飞，随机趴下，堪堪躲过了这致命一击。\n" NOR;
        }
        me->start_busy(2);
        me->add("neili",-500);
        me->add("jingli",-400);
        message_vision(msg, me, target);
        return 1;
}
