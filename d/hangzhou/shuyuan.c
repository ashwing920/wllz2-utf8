// shuyuan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "凤池书院");
	set("long", @LONG
书院正中有一匾“凤池书院”。书院里坐着两位老者，他们正在吟诗
作对。他们身旁的桌上铺着宣纸和笔墨。
LONG
);
	set("exits", ([
		"west"	  : __DIR__"road12",
	]));
	setup();
	replace_program(ROOM);
}
