// zh啊没n.c 猴拳「粘」字诀
// snowman

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("「粘」字诀只能对战斗中的对手使用。\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你现在真气不够，强行使用「粘」是发挥不了它的威力的！\n");

        if((int)me->query("jingli") < 200)
                return notify_fail("你现在精力不足，强行使用「粘」是发挥不了它的威力的！\n");
        
        if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");     

        if( me->query_skill("houquan",1) < 120)
                return notify_fail("你的猴拳还不够娴熟，无法发挥「粘」的威力！\n");

        if( target->is_busy())
                return notify_fail("对方正自顾不暇呢，你不忙使用「粘」字诀。\n");   
                
        msg = HIM"$N默运神功，使出猴拳中的「沾」字诀，企图以内力牵制$n！\n"NOR;

        if(random(me->query("combat_exp")) > target->query("combat_exp")/3){
                damage = (int)me->query_skill("taiji-quan", 1)/20; 
                damage = 2+random(damage);
                if(damage > 7) damage = 7; 
                target->start_busy((int)me->query_skill("houquan",1) / 60);
                me->add("neili", -(damage*40));
                me->add("jingli", -50);
                me->start_busy(1);
                msg += HIR"结果$n被$N的内力内力牵制，动弹不得！！\n"NOR;       
        } 
        else{
                me->start_busy(3);
                me->add("jingli", -25);
                me->add("neili", -150);
                msg += HIY"$n只觉在$N猴拳牵制之下，不能动弹只得运用轻功闪开一旁。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}
