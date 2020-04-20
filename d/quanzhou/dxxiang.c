// dxxiang.c 打锡巷
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "打锡巷");
	set("long", @LONG
这是普普通通的一条石板小路。走在上面，也许你根本想不到这是施
琅将军攻克台湾后为显其战功，将其城池的砌石运回铺成此路。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"citong_s1",
		"east" : __DIR__"jiangfu",
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
