//jmqmen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "巨木旗大门");
	set("long", @LONG
这里是明教巨木旗的大门，庄严古朴，门前对插四面镶绿游龙旗。碧
绿的大门敞开着，似乎看不出有何设防。从门里望进去，只有一片苍翠的
树林。
LONG
);
	set("exits", ([
		"enter"  : __DIR__"jmqshulin1",
		"west"   : __DIR__"tojmq3",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
