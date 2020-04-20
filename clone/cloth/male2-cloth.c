// male2-cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIB"青衫"NOR, ({ "qing shan", "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件很普通的粗布青衫。\n");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}

