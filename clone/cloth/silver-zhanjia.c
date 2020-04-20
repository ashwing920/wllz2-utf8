// silver-zhanjia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIW "银锁战甲" NOR, ({ "yinsuo zhanjia", "zhanjia" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件银锁战甲。\n");
                set("unit", "件");
                set("value", 15000);
		set("material", "silver");
		set("armor_type", "cloth");
		set("armor_prop/armor", 20 );
		// set("armor_prop/defense", 10 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
