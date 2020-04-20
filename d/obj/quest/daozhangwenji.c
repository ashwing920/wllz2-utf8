
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(CYN"道藏文辑"NOR, ({"daozang wenji" ,"wenji"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一本礼记手稿，密密麻麻的写满了字。\n");
                set("unit","本");
		set("owner_name","马钰");
		set("owner_id","ma yu");
        }
}

