// cloth.c example cloth

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIY"金丝短褂"NOR, ({ "jinsi duangua","duangua","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一件金丝织成的短褂，做工十分精美。\n");
		set("unit","件");
		set("value",2500);
		set("material", "cloth");
		set("armor_type","cloth");
		set("armor_prop/armor",280);
		set("wear_msg","$N穿上一件$n。\n");
		set("remove_msg","$将$n脱了下来。\n");
	}
	setup();
}
