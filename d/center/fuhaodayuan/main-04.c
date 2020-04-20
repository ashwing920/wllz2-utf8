// main-03.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
	set("short", "偏厅");
	set("long", @LONG
这里是主人家的偏厅，只见偏厅正中挂着一副画像，一个眉目慈祥的
老者身居画中，你心想应该是主人家的祖辈吧。画像前有一张茶几，茶几
上还放着一些茶具和一盆盆栽，让人看了倍感舒适。一个年约五旬坐在茶
几旁，正和几个家丁模样的男子说话。
LONG
);
	set("exits", ([
		"south": __DIR__"main-03",
	]));
	set("objects", ([
		__DIR__"npc/jiading":2,
		__DIR__"npc/zongguan":1,
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("no_sleep_room",1);
	set("no_beg",1);
	set("no_kill",1);
	setup();
	replace_program(ROOM);
}
