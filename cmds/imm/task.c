// by Tie@fy3 hehe
#include <ansi.h>
int main(object me, string str)
{
        string output;
        output = TASK_D->dyn_quest_list();
        me->start_more(output);
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: tasks

这个指令是用来得知目前的所有使命.

HELP
        );
        return 1;
}
