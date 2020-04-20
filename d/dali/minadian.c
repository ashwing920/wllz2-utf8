//Room: /d/dali/minadian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","蜜纳甸");
	set("long",@LONG
这里是乌夷分支乌蒙族阔部聚居的镇子，阔部领蜜纳甸和阔州。附近
有溪流汇入泸水，灌溉颇便利，因而农业相对谷中其他地区较发达。镇中
尽是些简陋的民居，也无甚客商过往。
LONG
);
	set("objects", ([
		__DIR__"npc/shaonu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"west"	  : __DIR__"gelucheng",
		"southwest" : __DIR__"zhenxiong",
	]));
	setup();
	replace_program(ROOM);
}

