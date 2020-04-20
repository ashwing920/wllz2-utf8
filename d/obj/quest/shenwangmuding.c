
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(YEL"神木王鼎"NOR, ({"shenmu wangding" ,"wangding"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一个神木王鼎\n");
                set("unit","个");
		set("owner_name","阿紫");
		set("owner_id","a zi");
        }
}

