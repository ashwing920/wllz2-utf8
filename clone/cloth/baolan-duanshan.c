// baolan-duanshan.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIB "宝蓝缎衫" NOR, ({ "baolan-duanshan", "duanshan", "cloth" }) ); 
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件宝蓝缎衫。\n");
                set("unit", "件");
                set("value", 10000);
		set("material", "silk");
		set("armor_type", "cloth");
		set("armor_prop/armor", 1 );
		// set("armor_prop/defense", 0 );
                set("armor_prop/dodge", 5 );
        }
        setup();
}
