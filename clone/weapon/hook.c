// hammer.c

#include <weapon.h>

inherit HOOK;

void create()
{
	set_name("铁钩", ({ "hook" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把弯入月牙的铁钩，打造的相当坚实。\n");
		set("value", 300);
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_hook(15);
	setup();
}
