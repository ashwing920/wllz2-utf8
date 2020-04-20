
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIW +BLK"率意贴"NOR, ({"shuaiyi tie","tie"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这可是一件宝贝啊。\n");
                set("unit","份");
		set("owner_name","秃笔翁");
		set("owner_id","tubi weng");
        }
}

