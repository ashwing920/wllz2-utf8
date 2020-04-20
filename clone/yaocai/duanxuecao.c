// duanxuecao.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIB"断血草"NOR, ({ "duan xuecao", "xuecao" }));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵剧毒的断血草，足以毒死一头牦牛。\n");
		set("value", 30);
		set("material", "grass");
	}
	setup();
}
int is_yaocai() { return 1;}