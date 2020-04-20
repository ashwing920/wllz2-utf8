
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
	set_name( "铁斧" , ({ "axe" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("material", "steel");
		set("value",1000);
		set("long", "这是一把铁斧，份量很重。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n挂在腰间。\n");
	}
	init_axe(30);
	setup();
}


