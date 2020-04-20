
#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("黯然只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手使掌才能使用！\n");       
                        
        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("你内力不雄厚不能使用黯然。\n");

        if( (int)me->query("neili")  < 500 )
                return notify_fail("你现在没有足够的内力使用。\n");

        if( (int)me->query_skill("xiaohun-zhang", 1) < 150 )
                return notify_fail("你的火侯还没到，无法领悟出黯然伤敌。\n");

        if(me->query_temp("anran"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force") / 2;
        skill = skill + me->query_skill("unarmed");
        skill = skill / 4;
        me->add("neili", -(me->query_skill("unarmed")+100));
        me->add("jingli", -50);
        message_vision(YEL "$N使出黯然消魂，威力大增，势不可当！源源不绝的掌力排山倒海般地压向$n！\n" NOR, me, target);
        me->set_temp("anran", 1);
        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill/2);
        if( me->is_fighting() ) me->start_busy(1);
        return 1;
}
void remove_effect(object me, int amount)
{        
        me->delete_temp("anran");
        me->add("neili", -(random(200)));
        message_vision(YEL "\n$N的掌风威力也恢复寻常了。\n" NOR, me);
        
}
