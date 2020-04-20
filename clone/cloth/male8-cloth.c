
// male8-cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIB"天蓝长袍"NOR, ({ "cloth" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件天蓝长袍。\n");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}

