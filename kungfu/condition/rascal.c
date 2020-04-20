// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1) return 0;
        me->apply_condition("rascal", duration - 1);
        if (duration  == 1){
                me->delete("rascal_flag",1);
        }
        if(environment(me)->query("chat_room")){
                me->move("/d/center/yingxionglou");
                tell_object(me,"那里不是你能呆的地方。\n");
                message_vision("$N被人赶了出来。\n",me);
        }
        return 1;
}
