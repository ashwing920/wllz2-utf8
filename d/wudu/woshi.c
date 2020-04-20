// Room: /d/wudu/caofang1.c

inherit ROOM;

void create()
{
	set("short","卧室");
	set("long", @LONG
这是五毒神教主的卧室，布置的十分漂亮，墙上挂着些兵器，右手一
张大床，前面供有历代教主的画像，这里打扫得十分的干净，光线明亮，
全没有外面的邪气。
LONG
);
	set("exits", ([
		"south" : __DIR__"jinshetang",
	]));
	set("objects", ([
		CLASS_D("wudu") + "/hetieshou" : 1,
	]));
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
