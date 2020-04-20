// gold-zhanjia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( HIY "金锁战甲" NOR, ({ "jinsuo zhanjia", "zhanjia" }) );
        set_weight(40000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件金锁战甲。\n");
                set("unit", "件");
                set("value", 20000);
		set("material", "gold");
		set("armor_type", "cloth");
		set("armor_prop/armor", 30 );
		// set("armor_prop/defense", 20 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
