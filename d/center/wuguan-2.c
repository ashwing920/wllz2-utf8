//wuguan-2.c
//Design By 蝴蝶君 Email:Robert_st@263.net 

inherit ROOM;

void create()
{

	set("short","武馆正厅");
	set("long",@LONG
你来到了枫林武馆的正厅之中。只见正厅中央的墙壁上挂着一张字画
，上面写着「$HIY$精湛武艺，以武会友$NOR$」八个大字。几个武馆弟子正在教头的
带领下，在比划拳脚。正厅南边有一扇门，门的那边是枫林武馆的兵
器库。
LONG
);

	set("outdoors","taoyuan");
	set("exits",([
		"west": __DIR__"wuguan",
		"south":__DIR__"wuguan-3",
	]));
	set("objects",([
		"/d/city/npc/dizi": 5,
		__DIR__"npc/jiaotou":1,
	]));
	setup();

}
