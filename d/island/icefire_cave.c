//Cracked by Kafei
// kane: 98/3/025

inherit ROOM;

void create()
{
	set("short", "冰火岛");
	set("long", @LONG
这个山洞极是宽敞，有八九丈纵深，中间透入一线天光，宛似天窗一
般。洞中放着一张石床，地下堆放着几个陶碗，一个土灶砌在洞的角落处
．诸般日用物品虽然粗拙，倒也齐备。
LONG
);
	set("exits", ([
		"out" : __DIR__"icefire3",
	]));
	set("resource/water", 1);
	set("objects", ([
		"/d/island/npc/xiexun" : 1,
	]) );
	set("outdoors", "island");
	setup();
	replace_program(ROOM);
}
