//Room: /d/dali/jianchuan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","剑川镇");
	set("long",@LONG
这里是剑川的镇中心，镇子不大，居民绝大部分是乌夷族，几乎全都
以狩猎为生。由于山高地寒，附近山林的野兽大多皮粗毛厚，有不少皮货
商在这里和当地猎人交易。北出山口则属大理北疆，也是入蜀之途，南穿
苍山则可抵大理内陆。
LONG
);
	set("objects", ([
		__DIR__"npc/lieren": 1,
		__DIR__"npc/pihuoshang": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"jianchuankou",
		"south"	  : __DIR__"cangshanzhong",
	]));
	setup();
	replace_program(ROOM);
}

