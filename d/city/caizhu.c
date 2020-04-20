// caizhu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "财主大门");
	set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大
门两侧，朱漆大门足足有三寸厚。门上挂着两个灯笼，写着“崔”字。崔
家是当地首富，而且以蛮横著称。几条狼狗嚎叫着向你冲了过来。
LONG );
	set("exits", ([
		"south" : __DIR__"xidajie2",
		"north" : __DIR__"dayuan",
	]));
	set("objects", ([
		__DIR__"npc/wolfdog" : 2,
	]));

	setup();

}

