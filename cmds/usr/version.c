// version.c

#include <mudlib.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        write(__VERSION__+"\n");
        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : version
 
这个指令会显示游戏目前的版本信息。
 
HELP
        );
        return 1;
}
