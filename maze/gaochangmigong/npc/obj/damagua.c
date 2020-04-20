// cloth.c example cloth

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIK"黑色大马褂"NOR, ({ "black magua","magua","cloth" }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一件黑色的大马褂，披肩落地，十分好看。\n");
		set("unit","件");
		set("value",2500);
		set("material", "cloth");
		set("armor_type","cloth");
		set("armor_prop/armor",140);
		set("wear_msg","$N穿上一件$n。\n");
		set("remove_msg","$将$n脱了下来。\n");
	}
	setup();
}
