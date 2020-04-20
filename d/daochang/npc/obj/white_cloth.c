// white-cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"白色长袍" NOR, ({ "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "一件长袖的白色长袍。\n");
                set("unit", "件");
                set("value", 50);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor",500);
		set("armor_prop/defense",100);
                set("armor_prop/dodge",100);
        }
        setup();
}
