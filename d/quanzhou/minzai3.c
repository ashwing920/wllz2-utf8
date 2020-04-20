// minzai.c 宅区
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "宅区");
	set("long", @LONG
这是泉州居民区。区内小巷纵横，四通八达。一式的石砌矮屋，红顶
青墙，方正对称，极具闽南特色，可谓错致落有，小巧玲珑。东边的刺桐
南路传来繁闹的喧哗声。西边有家出名的蜜饯制作铺「源和堂」，南面有
一所破败的宅子。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"minzai2",
		"east" : __DIR__"citong_s2",
		"west" : __DIR__"yuanhe",
	]));
	set("objects", ([
		__DIR__"npc/girl" : 1,
	]));
	set("outdoors", "quanzhou");
	setup();
	replace_program(ROOM);
}
