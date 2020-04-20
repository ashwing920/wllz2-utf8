//Room: /d/huashan/shop.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "小吃店");
	set("long", @LONG
这里是石梁边的一间小吃店，卖些简单的饮食，专门赚那些游客的钱。
LONG
);
	set("exits", ([
		"west" : __DIR__"shiliang",
	 ]));
	set("objects", ([
		"/d/city/npc/xiaoer2" : 1,
	]));
	setup();
	replace_program(ROOM);
}

