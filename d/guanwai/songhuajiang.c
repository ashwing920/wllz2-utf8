//guanwai/songhuajiang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "松花江面");
	set("long", @LONG
这里是松花江的江面，冰面早已解冻，清澈的江水涛涛北去，两岸是
如烟如雾松支，柳条。船夫悠闲地在船尾把着舵。
LONG
);
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
