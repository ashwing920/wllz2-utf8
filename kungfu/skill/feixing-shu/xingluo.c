// mthy.c 星罗漫布

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill,throw,i;

        skill = me->query_skill("feixing-shu",1);

        if( !(me->is_fighting() ))
                return notify_fail("「星罗漫布」只能在战斗中用在对手身上。\n");

	if(!target) target = offensive_target(me);
        if(!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("满天花雨只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "throwing")
                return notify_fail("你使用的武器不对。\n");

        if( skill < 300)
                return notify_fail("你的飞星术不够纯熟, 不能使用「星罗漫布」！\n");

	if (me->query_skill("huagong-dafa",1) < 200)
		return notify_fail("你的化功大法不够娴熟，无法使用星罗漫布。\n");

        throw = weapon->query_amount() / 3;

        if(throw < 30)
                return notify_fail("你身上的"+ weapon->name()+ NOR"不够了。\n");

        if( me->query("neili") < 600)
                return notify_fail("你的内力不够，无法运用「星罗漫布」！\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        msg = HIW"$N潜运内力，手中"+ weapon->name()+ HIW"突然灵光一闪，紧接着一记「星罗漫布」，数枚"+ weapon->name()+HIW"犹如夜空繁星般向$n袭去！\n"NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4) {
        msg += CYN"$p看得目瞪口呆，不知所措，刹那间已被$P攻了个措手不及！\n" NOR;
        message_vision(msg, me, target);
        if(throw > 14) throw = 14;

        for(i = 0; i < throw; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                if (!weapon->query("equipped")) break;
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->set_temp("action_flag",0);
        }else break;
                me->add("neili", -400);
                me->start_busy(3);
        }
        else {
                msg += YEL"$p却早有防备，避开了$P的攻击。\n" NOR;
                message_vision(msg, me,target);
                me->start_busy(5);
        }
        return 1;
}
