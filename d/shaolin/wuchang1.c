// Room: /d/shaolin/wuchang1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。上千年的
踩踏已使得这些石板如同镜子般平整光滑。练武场中间竖立着不少木人。
十来个僧人正在练习武艺。东面有一长溜僧房。
LONG
);
	set("exits", ([
		"south" : __DIR__"zoulang2",
		"west" : __DIR__"banruo5",
		"east" : __DIR__"wuchang",
		"north" : __DIR__"zoulang6",
	]));
	 set("objects", ([ 
		__DIR__"npc/mu-ren" : 5
	]));
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

