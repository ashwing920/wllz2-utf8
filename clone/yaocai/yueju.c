// yueju.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"越橘草"NOR, ({ "yue ju", "yueju", }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "这是一株越橘草。\n");
		set("value", 30);
		set("material", "grass");
		set("cure_s",75);
		set("cure_d",30);
		set("cure_n",12);
	}
	setup();
}
int is_yaocai(){ return 1;}
