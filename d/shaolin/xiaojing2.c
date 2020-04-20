// Room: /d/shaolin/xiaojing2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "田埂边");
	set("long", @LONG
转过山坡只见几棵果实累累的大枣树孤零零地栽在田埂边，上面挂满
了红熟的枣子，使人忍不住想摘下几颗尝尝。田里种着半熟的青稞麦。西
首有三间简陋的土屋。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"xiaojing1",
		"west" : __DIR__"houshan",
	]));
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

