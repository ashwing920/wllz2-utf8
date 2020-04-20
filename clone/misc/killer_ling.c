// miling.c

#include <ansi.h>
int time_period(int timep, object me);
inherit ITEM;

void create()
{
        set_name(HIR"杀手密令"NOR, ({ "mi ling", "ling" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", @TEXT
一个铁制的令牌，上面密密麻麻的写了一些小字。
TEXT);

                set("value",0);
                set("material","iron");
        }
}
void init()
{
        if( this_player() == environment() ){
                add_action("do_read", "read");
        }
}
int do_read(string arg)
{
        object me;
        mapping killer_quest;
        me = this_player();
        if( !id(arg) ) return 0;
        killer_quest = me->query("killer_quest");
        if(!killer_quest || killer_quest["time"] < time())
                return notify_fail("令牌中的字眼早已消失了。\n");
                
        tell_object(me,sprintf(HIR"杀手令牌上显示：目前你的任务是：杀%s。\n有效时间：%s内，任务地点：%s。\n"NOR,
        killer_quest["name"],CHINESE_D->chinese_time(killer_quest["time"] - time()),killer_quest["where"]));
        return 1;
}
