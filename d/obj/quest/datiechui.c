inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIY"大号铁锤"NOR, ({"datie chui", "chui"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一把打铁用的锤子。\n");
                set("unit", "把");
                set("owner_name","铁匠");
                set("owner_id","tiejiang");
        }
}
