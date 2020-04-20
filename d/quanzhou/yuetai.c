// yuetai.c 月台广场
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "月台广场");
	set("long", @LONG
这是平坦光滑的石面广场，中间凸起一台面，面放置一焚吊炉。台座
边嵌着七十二幅狮身人面青石浮雕，有着浓厚的异国风味。东西各有一座
恢宏的石塔。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"ganlu",
		"south" : __DIR__"dxbaodian",
		"east" : __DIR__"dongta",
		"west" : __DIR__"xita",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
