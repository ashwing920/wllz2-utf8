// tiejia.c 铁甲

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("藤甲", ({ "teng jia","jia" }) );
	set_weight(30000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "steel");
		set("value", 2000);
		set("armor_prop/armor", 50);
	}
	setup();
}