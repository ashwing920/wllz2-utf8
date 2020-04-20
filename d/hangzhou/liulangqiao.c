// liulangqiao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "柳浪桥");
	set("long", @LONG
每当春至，站在桥上，沿湖垂柳在风中摇曳如翠浪翻空，黄莺在枝头
迎春嬉戏，鸣声婉转，故得名“浪桥闻莺”。
LONG
);
	set("exits", ([
		"southwest" : __DIR__"jujingyuan",
	]));
	set("objects", ([
		__DIR__"npc/maque" : 2,
		__DIR__"npc/wuya" : 1,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
