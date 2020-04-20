//guanwai/xiaoxiang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小巷");
	set("long", @LONG
这是一个僻静幽深的小巷，四周寂静无声，一个人影也没有。长长的
石板路上落了一层厚厚的积雪，踩在脚下发出“咯吱”的响声。小巷的尽
头有一座土屋。
LONG
);
	set("exits", ([
		"south" : __DIR__"tuwu",
		"east"  : __DIR__"beicheng",
	]));
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}

