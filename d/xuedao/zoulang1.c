// 99/04/09
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long",@LONG
这里是血刀门内的走廊。这里有点幽暗，阴森森的，可能有机关。
LONG
);
	set("exits",([
		"south"   : __DIR__"cedian1",
		"west"   : __DIR__"neishi",
		"northwest" : __DIR__"midao1",
	]));
	setup();
}


