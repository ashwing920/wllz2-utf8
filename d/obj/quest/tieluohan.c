inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name("铁罗汉", ({"tie luohan", "luohan"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是少林的铁罗汉，是郭襄送给张三丰的。\n");
                set("unit", "只");
               set("owner_name","张三丰");
               set("owner_id","zhang sanfeng");
        }
}


