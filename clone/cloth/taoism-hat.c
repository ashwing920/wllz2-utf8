// taoism-pao.c 

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name( HIY "道冠" NOR, ({ "dao guan", "guan", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一顶杏黄道冠。\n");
                set("unit", "顶");
                set("value", 200);
		set("material", "cloth");
		set("armor_type", "head");
		set("armor_prop/armor", 2 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 1 );
        	set("wear_msg", "$N将$n取出戴在头上。\n");
        }
        setup();
}
