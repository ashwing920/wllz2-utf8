// Room: /u/qfy/quanzhou/minzai1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "宅区");
	set("long", @LONG
这是泉州居民区。区内小巷纵横，四通八达。一式的石砌矮屋，红顶
青墙，方正对称，极具闽南特色，可谓错致落有，小巧玲珑。西边是间戏
院，南边也是一大片宅区。
LONG
);
	set("outdoors", "quanzhou");
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"xiyuan",
		"south" : __DIR__"minzai2",
                "east" : __DIR__"citong_s1",
                "north" : __DIR__"laozhai",
	]));
	set("objects", ([
		__DIR__"npc/boy" : 2,
	]));
	setup();
	replace_program(ROOM);
}
