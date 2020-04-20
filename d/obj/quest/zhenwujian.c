
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIC"真武剑"NOR, ({"zhenwu jian" ,"jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把锋利无比的真武剑。\n");
                set("unit","把");
		set("owner_name","张三丰");
		set("owner_id","zhang sanfeng");
        }
}

