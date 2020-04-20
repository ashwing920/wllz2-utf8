// boots.c example shoes

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIC"疾风靴" NOR, ({"jifeng xue","xue","boots" }));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("value",12000);
		set("material", "leather");
		set("armor_prop/dexerity",5);
		set("armor_prop/strength",-5);
		set("armor_prop/armor",10);
		set("armor_prop/dodge",5);
		set("wear_msg","$N穿上一双$n。\n");
		set("remove_msg","$N将$n脱了下来。\n");
	}
}
