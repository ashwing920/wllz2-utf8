// kaojiao.c 考教场
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "考教场");
	set("long", @LONG
这里是武馆的考教场，面积甚大。有许多武馆子弟在此习武，拳打脚
踢，舞刀弄剑，耍枪挥棒的好不热闹。穿过考教场便是武馆的前厅。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"qianting",
		"east" : __DIR__"wgdamen",
	]));
	set("objects", ([
		__DIR__"npc/xuetu" : 3,
	]));
	set("outdoors", "city" );
	setup();
	replace_program(ROOM);
}
