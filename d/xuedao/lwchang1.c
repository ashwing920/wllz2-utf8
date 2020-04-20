// Room: /d/xuedao/lwchang1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	  set("short", "练武场");
	set("long", @LONG
这里是血刀门的练武场。四周都是暗红，让人烦躁的想发泄。练武场
中间竖立着不少木人，东面有一个厨房。
LONG
);
	set("exits", ([
		"west" : __DIR__"guangchang",
		"east" : __DIR__"chufang",
		"northeast" : __DIR__"shi",
	]));
	set("objects",([
		"/d/shaolin/npc/mu-ren": 5
	]));
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

