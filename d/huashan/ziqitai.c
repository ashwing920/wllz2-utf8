// Roon: ziqitai.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "紫气台");
	set("long", @LONG
紫气台终年云遮雾掩，迷蒙不见天日，更为怪异的是：没逢下雨天，
山谷之中就隐隐有紫气出现，在紫气台还有些松树（tree）树的下面有一
些不同于别处的地方，好像曾经有人在这做过手脚。
LONG
);
	set("outdoors", "xx");
	set("exits",([ /* sizeof() == 1 */
		"eastdown": __DIR__"chaopath2",
	]));
	setup();
}
void init()
{
	add_action("do_climb","climb");
}
int do_climb()
{
	object me;
	me=this_player();
	message_vision("$N顺着刚绑上的绳子，一步步地爬到了树的顶上。\n",me);	
	this_player()->move("/d/huashan/shudin");
	return 1;
}
