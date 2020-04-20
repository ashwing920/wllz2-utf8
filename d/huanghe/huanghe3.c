// Room: /huanghe/huanghe3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "黄河岸边");
	set("long", @LONG
这里是黄河岸边。黄河流淌到这里，已经泥沙浑浊了。黄色的河水在
河床里翻滚着，咆哮着，卷起一个个巨大的漩窝。
LONG
);
	set("exits", ([
		"east"  : __DIR__"huanghe4",
		"west"  : __DIR__"huanghe2",
	]));
	set("objects", ([
		__DIR__"npc/bangzong" : 1,
	]));

	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

