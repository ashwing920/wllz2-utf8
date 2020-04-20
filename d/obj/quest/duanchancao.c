
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIG"断肠草"NOR, ({"duanchan cao" ,"cao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一棵毒性剧烈的断肠草。\n");
                set("unit","棵");
		set("owner_name","杨过");
		set("owner_id","yang guo");
        }
}

