
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIG"大燕国玉玺"NOR, ({"yu xi" ,"xi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这就是大燕国的玉玺。\n");
                set("unit","个");
		set("owner_name","慕容复");
		set("owner_id","murong fu");
        }
}

