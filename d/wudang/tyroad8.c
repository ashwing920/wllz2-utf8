// tyroad8.c 桃园小路
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "桃园小路");
	set("long", @LONG
眼前豁然开朗，你轻松地走在桃园边的小路上。两边是桃树林，树上
盛开着粉红的桃花，红云一片，望不到边。不时有蜜蜂「嗡嗡」地飞过，
消失在在花丛中；几只猴子在树上互相追逐着，叽叽喳喳地争抢桃子。这
是武当山脚，西边有条陡峭的山路，通向山顶。
LONG
);
	set("outdoors", "wudang");
	set("exits", ([
		"westup" : __DIR__"tyroad7",
		"east" : __DIR__"tyroad9",
		"north" : __DIR__"tynroad",
		"south" : __DIR__"tysroad",
	]));
	setup();
	replace_program(ROOM);
}
