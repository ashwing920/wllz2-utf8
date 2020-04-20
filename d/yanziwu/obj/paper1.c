// paper1.c

inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIW"世袭表"NOR, ({ "biao" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "这是一张慕容世家的世袭表，上面写着历代慕容世家的家谱。\n");
		set("value", 100);
		set("material", "paper");
	}
	setup();
}
