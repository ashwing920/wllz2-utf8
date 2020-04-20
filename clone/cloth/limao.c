// cloth.c

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
	set_name(HIR"圣诞礼帽"NOR, ({ "shengdan limao" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}

