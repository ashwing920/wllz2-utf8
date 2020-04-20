
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIM"姻缘簿"NOR, ({"yinyuan pu" ,"pu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一本姻缘簿\n");
                set("unit","本");
		set("owner_name","媒婆");
		set("owner_id","mei po");
        }
}

