//Cracked by Kafei
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(HIY"田七"NOR, ({"tianqi"}));
	set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "钱");
		set("long","田七：草本植物，可解毒。\n");
		set("value", 4500);
		set("cure_s",5);
		set("cure_d",30);
		set("cure_n",0);
	}
	setup();
}
int is_yaocai() { return 1;}
