// powerup.c 玉女心法加力

#include <ansi.h>

void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        if( target != me )
                return notify_fail("你只能用玉女心法来提升自己的战斗力。\n");

        if((int)me->query("neili") < 100)
                return notify_fail("你的内力不够。\n");

        if( (int)me->query_skill("yunv-xinfa",1) < 100)
                return notify_fail("你的玉女心法还不够精熟。\n");

        if((int)me->query_temp("powerup"))
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");
        me->add("neili", -100);
        me->receive_damage("qi", 0);
     
        message_vision(HIC"$N脸色微微一沉，双掌向外一分，姿势曼妙，如一朵"HIW"白玉兰花"HIC"盛开在初冬的寒风中！\n"NOR,me);

        me->add_temp("apply/attack", skill / 2);
        me->add_temp("apply/dodge", skill / 2);
        me->set_temp("powerup",1);
        
        me->start_call_out((:call_other, __FILE__, "remove_effect", me, skill/2
:), skill/2);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的玉女心法运行完毕，将内力收回丹田。\n");
}

int clean_up()
{
        return 1;
}
void reset()
{
}
