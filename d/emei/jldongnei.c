//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: jldongnei.c 九老洞

inherit ROOM;

void create()
{
	set("short","九老洞");
	set("long",@LONG
这就是峨嵋第一大洞，洞内深窈无比，神秘难测。你一走进来，便发
觉洞中叉叉洞多如迷宫，怪异莫测，似乎黝黑无底。洞里隐隐传来鸡犬鼓
乐之声，令人惊异间，忽有蝙蝠群涌而至，扑熄火炬，漆黑一片，还是快
快离开(leave)吧。
LONG
);
	set("objects", ([
		__DIR__"npc/poorman" : 2,
		__DIR__"npc/little_monkey" : 3,
		__DIR__"npc/bat" : 4,
	]));

	setup();
}
void init()
{
	add_action("do_leave", "leave");
}

int do_leave(string arg)
{
	object me;

	me = this_player();
	me->move(__DIR__"jiulaodong");
	return 1;
}
