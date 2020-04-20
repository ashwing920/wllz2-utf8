//guanwai/chuanchang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "船厂");
	set("long", @LONG
这里是古镇船厂。船厂是位于关外大平原中部的一个古老的小镇，此
镇西、南、北、三面是以高墙垒筑，利于坚守。东面临松花江天成天险，
乃兵家必争的要地。松花江在冬春时结冰可通行，夏秋化冻你只好找船家
帮忙了。
LONG
);
	set("exits", ([
		"south"  : __DIR__"xuedi3",
		"east"   : __DIR__"bingmian",
	]));
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
