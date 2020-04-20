// male3-cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIK"黑色劲装" NOR, ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件很笔挺的黑色劲装。\n");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
