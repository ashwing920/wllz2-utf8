// Room: /d/mingjiao/huangtulu2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄土小路");
	set("long", @LONG
这里是茂密松林中的一条黄土小路。松林极密，四面都是蓝幽幽的感
觉，白白的冰雪反光耀眼。你来到一个山腰的危崖之边，前边有一个小洞。
LONG
);
	set("exits", ([
		"east"  : __DIR__"huangtulu1",
		"enter" : __DIR__"shandong",
	]));
	set("outdoors", "mingjiao");
	setup();
}

int valid_leave(object me, string dir)
{
	if ((dir == "enter") &&
		!objectp(present("xiao zhao", environment(me))))
	{
		return notify_fail("那是明教圣地，擅入杀无赦。\n");
	}
	return ::valid_leave(me, dir);
}
