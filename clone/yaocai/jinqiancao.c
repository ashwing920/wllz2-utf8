// jinqiancao.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL"金钱草"NOR, ({ "jin qiancao", "jin", "qiancao", }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("value", 30);
		set("material", "grass");
	}
	setup();
}
int is_yaocai() { return 1;}
