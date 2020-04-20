//Cracked by Kafei
// douli.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIG"大红猩毡斗笠"NOR, ({ "dou li", "li" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("long", "这是一顶大红猩毡斗笠。\n");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 4);
	}
	setup();
}
