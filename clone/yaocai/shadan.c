//Cracked by Kafei

#include <ansi.h>

inherit ITEM;

void setup()
{}

void create()
{
	set_name(MAG"鲨胆"NOR, ({"shadan","dan"}));
	set_weight(5);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "粒");
		set("long","鲨胆：一种浅海鲨鱼的胆，可解百毒。\n");
		set("value", 6500);
		set("cure_s",0);
		set("cure_d",52);
		set("cure_n",10);
	}
	setup();
}
int is_yaocai() { return 1;}
