
inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIM"真丝手绢"NOR, ({"zhensi juan" ,"juan"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一条真丝手绢，手工十分精细。\n");
                set("unit","条");
		set("owner_name","念慈");
		set("owner_id","nian ci");
        }
}

