// iron-zhanjia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( WHT "铁锁战甲" NOR, ({ "tiesuo zhanjia", "zhanjia" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件铁锁战甲。\n");
                set("unit", "件");
                set("value", 5000);
		set("material", "iron");
		set("armor_type", "cloth");
		set("armor_prop/armor", 5 );
		// set("armor_prop/defense", 5 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
