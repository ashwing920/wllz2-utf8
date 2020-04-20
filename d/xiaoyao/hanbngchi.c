// hanbingchi.c 寒冰池
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
#include <ansi.h>

inherit ROOM;

int do_out();

void create()
{
	set("short", "寒冰池");
	set("long", @LONG
这里是逍遥派重地寒冰池。由于这里的湖面终年结冰因而得名，湖水
很深也很冷，一般不会武功的人是不敢下去的。近年来这里胜产一种娃娃
鱼，时常有人潜(out)下池去搜寻它，总也不知道结果如何。
LONG
);
	set("exits", ([
		"east"	 : __DIR__"xiaodao22",
	]));
	set("outdoors", "xiaoyao");

	setup();
}

void init()
{
	add_action("do_out","out");
}

int do_out()
{
	object me;
	me = this_player();
	
	message_vision("$N纵身跃起，空中一个浪里翻花，头下脚上，咚的一声潜入池中不见了。\n", me);
	message("channel:rumor",HIM"【武林奇闻】某人："+ me->name()+"跳到寒冰池里去了，生死未卜......\n"NOR,users());
	me->move(__DIR__"chi1");
	return 1;
}

