// ill_shanghan.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;
        if( !living(me) ) {
                message("vision",HIB + me->name() + "冷不丁打了个冷战，头昏沉沉的，好象是得伤寒病了。\n"NOR, environment(me), me);
        }
        else {
                tell_object(me, HIB"你打了个冷战，头昏沉沉的，好象是得伤寒病了！\n"NOR);
                message("vision",HIB + me->name() + "冷不丁打了个冷战，头昏沉沉的，好象是得伤寒病了。\n"NOR,environment(me), me);
        }
        me->receive_wound("qi",10);
        me->receive_damage("qi",20);
        me->apply_condition("ill_shanghan", duration - 1);
        me->set_temp("die_for","伤寒不治死了！");
        me->delete_temp("last_damage_from");
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}
