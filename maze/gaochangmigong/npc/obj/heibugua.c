// cloth.c example cloth

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIK"黑色布褂"NOR, ({ "black bugua","bugua","cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","件");
		set("value",1000);
		set("material", "cloth");
		set("armor_type","cloth");
		set("armor_prop/armor",80);
		set("wear_msg","$N穿上一件$n。\n");
		set("remove_msg","$将$n脱了下来。\n");
	}
	setup();
}
