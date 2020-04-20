inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name("天下英雄令", ({"yingxiong ling", "ling"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一块天下英雄令。\n");
                set("unit", "块");
 		set("owner_name","江百胜");
		set("owner_id","jiang baisheng");
        }
}
