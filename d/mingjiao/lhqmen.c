//lhqmen.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "烈火旗大门");
	set("long", @LONG
这里是明教烈火旗的大门，庄严古朴，门前对插四面镶红飞龙旗。金
色门钉扣在火漆红门上，分外精神。也是通往明教总舵的必经之地。所以
来往的人也特别多。
LONG
);
	set("exits", ([
		"enter"	 : __DIR__"lhqyuan",
		"southdown" : __DIR__"lhqpaifang",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
