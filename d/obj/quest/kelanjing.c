inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
	set_name("可兰经", ({"kelan jing", "jing"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一本回族的圣经。\n");
                set("unit", "本");
 		set("owner_name","霍青桐");
		set("owner_id","huo qingtong");
        }
}


