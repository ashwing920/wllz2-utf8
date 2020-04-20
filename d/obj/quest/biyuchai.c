
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIG"碧玉钗"NOR, ({"biyu chai" ,"chai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一支晶莹剃透的碧玉钗。\n");
                set("unit","支");
		set("owner_name","岳灵珊");
		set("owner_id","yue lingshan");
        }
}

