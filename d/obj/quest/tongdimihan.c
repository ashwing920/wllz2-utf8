
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIW"通敌秘函"NOR, ({"tongdi mihan" ,"mihan"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这是一份通敌秘函。\n");
                set("unit","份");
		set("owner_name","段天德");
		set("owner_id","duan tiande");
        }
}

