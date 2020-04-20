// gancao.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"甘草"NOR, ({ "gan cao", "gan", "cao", }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "甘草，有清热的作用。\n");
		set("value", 30);
		set("material", "grass");
	}
	setup();
}
int is_yaocai() { return 1;}
