// minzai.c 宅区
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "宅区");
	set("long", @LONG
这是泉州居民区。区内小巷纵横，四通八达。一式的石砌矮屋，红顶
青墙，方正对称，极具闽南特色，可谓错致落有，小巧玲珑。北边和南边
都是宅区。西边则是泉州最大的「扬威武馆」。西南可通至源和堂。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"minzai1",
		"south" : __DIR__"minzai3",
		"west" : __DIR__"wgdamen",
		"southwest" : __DIR__"yuanhe",
	]));
	set("objects", ([
		__DIR__"npc/oldwoman" : 1,
		__DIR__"npc/xiao-hai" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
