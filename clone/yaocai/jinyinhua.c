// honghua.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY"金银花"NOR, ({ "jinyin hua", "hua" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵药用的金银花。\n");
		set("value", 30);
		set("material", "grass");
	}
	setup();
}
int is_yaocai() { return 1;}