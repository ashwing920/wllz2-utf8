//六脉神剑 slowly.c

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

string *per_msg = ({
        HIC"\n少阳剑！\n"NOR,
        HIB"\n商阳剑！\n"NOR,
        HIR"\n中冲剑！\n"NOR,
        HIM"\n关冲剑！\n"NOR,
        HIG"\n少冲剑！\n"NOR,
        HIW"\n少泽剑！\n"NOR,
});
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i;

        if(!target) target = offensive_target(me);
        if(!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「六脉神剑」只能在战斗中使用。\n");

        if((int)me->query_skill("liumai-shenjian", 1) < 150 )
                return notify_fail("你的「六脉神剑」不够娴熟，不能使用外功！\n");

        if((int)me->query_skill("kurong-changong", 1) < 150 )
                return notify_fail("你的「枯荣禅功」不够娴熟，不能使用外功！\n");

        if(objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你不能使用武器！\n");

        if( (int)me->query("neili") < 400  )
                return notify_fail("你的内力不够。\n");

        me->clean_up_enemy();
        msg = HIY "$N运用真气，指尖轻弹，六道剑气象狂风般的向$n刺去！\n"NOR;
        message_vision(msg,me,target);
        for(i = 0; i < 6; i++)
                if (me->is_fighting(target) && target->is_fighting(me) && target->query("eff_qi")>0){
                me->set_temp("action_flag",1);
                msg = per_msg[random(sizeof(per_msg))];
                message_vision(msg + NOR, me,target);
                if(me->query_temp("weapon")) break;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                me->set_temp("action_flag",0);
        }else break;
        me->add("neili", -400);
        me->start_busy(4);
        return 1;
}
