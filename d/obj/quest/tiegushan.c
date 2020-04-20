inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name("铁骨扇", ({"tiegu shan","shan"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一把铁骨扇。\n");
                set("unit", "把");
		set("owner_name","贾翌");
		set("owner_id","jia yi");
        }
}


