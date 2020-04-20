//Room: /d/huashan/shop.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山顶小店");
	set("long", @LONG
这里是华山山顶的一间小店，卖些简单的饮食，专门赚那些游客的钱。
LONG
);
	set("exits", ([
		"east" : __DIR__"square",
	]));
	set("objects", ([
		"/d/huashan/npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

