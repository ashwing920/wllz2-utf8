//Cracked by Kafei
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(HIY"菊梗"NOR, ({"jugeng"}));
	set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "钱");
		set("long","菊梗：菊花根茎，清热败火。\n");
		set("value", 50);
		set("cure_s",0);
		set("cure_d",5);
		set("cure_n",0);
	}
	setup();
}
int is_yaocai() { return 1;}
