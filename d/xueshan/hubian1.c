// hubian1.c 湖边小路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","湖边小路");
	set("long",@LONG
这是圣湖边的小路。路侧的湖水极为清澈。阳光下映着白顶雪山显出
一片蓝幽幽的宁静。
LONG
);
	set("outdoors","xueshan");
	set("exits",([
		"east" : __DIR__"hubian2",
		"west" : __DIR__"shenghu",
	]));
	setup();
	replace_program(ROOM);
}
