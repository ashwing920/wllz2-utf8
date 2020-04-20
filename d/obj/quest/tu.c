#include <ansi.h>
inherit ITEM;

int do_locate(string arg);
int do_task();

void create()
{
	set_name("藏宝图", ({"cangbao tu","tu"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@TEXT
$BYEL$$HIW$
┌───────────────────┐
│　　　       藏  宝  图　　　　　　　 │
│　　　　　　　　　　　　　　　　　　　│
│　这是一件用于寻找丢失物件的藏宝图。　│
│　能用(zhao)命令找到物品的大概位置！　│
│　　  　　　　　　　　　　　　　　　　│
└───────────────────┘
$NOR$
TEXT
);
	set("unit", "件");
	set("value",0);
	}
}

void init()
{
	if(environment()==this_player())
	add_action("do_zhao","zhao");
	add_action("do_task","task");
}
int do_task()
{
	string output;
	output="藏宝图里突然映现出一篇蝇头小字：\n\n"+"/adm/daemons/taskd"->dyn_quest_list();
	this_player()->start_more(output);
	return 1;
}

int do_zhao(string arg)
{
	if(!arg)
		return notify_fail("zhao <物品>\n");
	else
	"/adm/daemons/taskd"->locate_quest(this_player(),arg);
	return 1;
}
