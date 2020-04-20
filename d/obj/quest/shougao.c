
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(WHT"礼记手稿"NOR, ({"liji shougao" ,"gao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一本礼记手稿，密密麻麻的写满了字。\n");
                set("unit","本");
		set("owner_name","朱熹");
		set("owner_id","zhu xi");
        }
}

