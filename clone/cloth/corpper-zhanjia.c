// corpper-zhanjia.c 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name( YEL "铜锁战甲" NOR, ({ "tongsuo zhanjia", "zhanjia" }) );
        set_weight(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "这是一件铜锁战甲。\n");
                set("unit", "件");
                set("value", 10000);
		set("material", "corpper");
		set("armor_type", "cloth");
		set("armor_prop/armor", 10 );
		// set("armor_prop/defense", 5 );
                set("armor_prop/dodge", 0 );
        }
        setup();
}
