// enforce.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int pts,jiali;
        
        jiali = (int)me->query_skill("force") / 2;

        if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("指令格式：enforce|jiali <使出几成内力伤敌>|none\n");

        if( !me->query_skill_mapped("force") )
                return notify_fail("你必须先 enable 一种内功。\n");

        if( arg=="none" )
                me->delete("jiali");
        else {
                if( pts < 0 )
                        return notify_fail("你只能用 none 表示不运内力，或数字表示每一击用几点内力。\n");
                if( pts > jiali )
                        return notify_fail("按照你现在的等级，你只能把加力设置为 "HIC + jiali + NOR" 点。\n");
                me->set("jiali", pts);
        }

        write("Ok.\n");
        return 1;
}

int help (object me)
{
        write(@HELP
指令格式: enforce|jiali <使出几点内力伤敌>|none
 
这个指令让你指定每次击中敌人时，要发出几点内力伤敌。

enforce none 则表示你不使用内力。 

See Also: enable
HELP
        );
        return 1;
}
