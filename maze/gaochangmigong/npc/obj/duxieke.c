// duxieke.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED"毒蝎壳"NOR, ({"duxie ke","ke"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一只红褐色的毒蝎壳，薄薄的似乎可以将它捏(nie)碎。\n");
		set("unit","只");
		set("value",1000);
	}
	setup();
}

void init()
{
	if(environment() == this_player())
	add_action("do_nie","nie");
}
int do_nie(string arg)
{
	object obj;
	
	if(!id(arg)) 
		return notify_fail("你要捏碎什么？\n");
	
	if(query("nie"))
		return notify_fail("你看这东西可以捏碎嘛？\n");
	
	set("nie",1);
	message_vision("$N将$n握在手心，用力一捏，$n顿时被$N捏得粉碎。\n",this_player(),this_object());
	
	obj=new(__DIR__"duxiefeng");
	obj->move(this_player(),1);
	destruct(this_object());
	return 1;

}
