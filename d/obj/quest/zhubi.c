inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name("朱笔", ({"zhu bi", "bi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这可是宝贝啊。\n");
                set("unit", "只");
		set("owner_name","朱丹臣");
		set("owner_id","zhu danchen");
        }
}
