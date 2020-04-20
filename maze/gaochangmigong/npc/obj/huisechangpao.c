// cloth.c example cloth

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT"灰色长袍"NOR, ({ "huise changpao","changpao","pao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","一件灰色的长袍，不仔细看还以为是僧袍呢。\n");
		set("unit","件");
		set("value",2500);
		set("material", "cloth");
		set("armor_type","cloth");
		set("armor_prop/armor",275);
		set("wear_msg","$N穿上一件$n。\n");
		set("remove_msg","$将$n脱了下来。\n");
	}
	setup();
}
