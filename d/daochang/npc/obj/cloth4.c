// cloth.c example cloth

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name(HIW"百战战袍"NOR,({ "cloth" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 0);
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/personality", 1);
		set("armor_prop/armor",250);
		set("wear_msg","$N穿上一件$n。\n");
		set("remove_msg","$将$n脱了下来。\n");
	}
}
