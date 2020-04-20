
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIG"掌门扳指"NOR, ({"ban zhi", "zhi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是灵鹫宫的掌门扳指。\n");
                set("unit", "颗");
		set("owner_name","虚竹");
		set("owner_id","xu zhu");
        }
}
