// gift.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object *users, present;
        int i;

        if( !arg || arg=="" )
                 return notify_fail("指令格式：gift <物品文件名>\n");

        if( !(present = load_object(arg)) )
                 return notify_fail("您所指定的礼物不存在或非物品，请检查您的输入。\n");
/*
        if( !(present->is_item()) )
                 return notify_fail("您所指定的礼物非物品，请检查您的输入。\n");
*/
        seteuid(getuid());
        users = users();
        i = sizeof(users);
        while(i--) {
                present=new(arg);
                present->move(users[i]);
                tell_object(users[i],HIW "天上传来一阵叮叮当当的铃声\n\n" +
                                     HIY "突然你觉得身上一下多了一样什么东西。\n\n" NOR);
                }
        write("礼物发放完毕。\n");
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : gift <礼物的文件名称>

用处 : 发放礼物到所有的在线玩家

HELP
     );
     return 1;
}
