// shecao.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(MAG"蛇草"NOR, ({ "she cao", "shecao", }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵产之西域的蛇草。\n");
		set("value", 30);
		set("material", "grass");
	}
	setup();
}
int is_yaocai() { return 1;}