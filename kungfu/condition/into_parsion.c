// killer.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1 ) return 0;
        me->apply_condition("into_parsion", duration - 1);
        if (duration == 1 ){
                if(environment(me)->query("parsion_room")) {
                        tell_object(me,"囚室守卫叫道：喂！你的时间到了，走！走！走！");
                        me->move("/d/xingbu/qiushi_gate");
                }
        }
        return 1;
}
