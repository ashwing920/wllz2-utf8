
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIR"屠龙刀"NOR, ({"tulong dao" ,"dao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一柄锋利无比的屠龙刀。\n");
                set("unit","柄");
		set("owner_name","谢逊");
		set("owner_id","xie xun");
        }
}

