inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name("百家饭", ({"baijia fan", "fan"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗寻常人家吃剩下的饭菜。\n");
                set("unit", "碗");
               set("owner_name","左全");
               set("owner_id","zuo quan");
        }
}


