// stone-1.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"金刚石"NOR, ({ "jingang stone","stone" }) );
        set_weight(100);
        set("is_monitored",1);
        set("long","一个金光闪闪的"+ this_object()->query("name")+"。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value",8000000);
                set("material","diamond");
        };
        setup();
}
