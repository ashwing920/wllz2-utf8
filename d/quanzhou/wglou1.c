// wglou1.c 万国烟雨楼

inherit ROOM;

void create()
{
	set("short", "万国烟雨楼");
	set("long", @LONG
「人道不思归，烟雨伴君眠」，傍湖而建，情趣盎然的万国烟雨楼名
虽酒楼，实是远近闻名的一景。楼分两层，一进大门，即可见园林中亭台
楼榭，假山流水，一池碧水，荷藕映红。环池漫步，客房绵延。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"up" : __DIR__"wglou2.c",
		"west" : __DIR__"jiedao2.c",
	]));
	set("objects", ([
		__DIR__"npc/qzxiaoer" : 1,
	]));
	setup();
	replace_program(ROOM);
}
