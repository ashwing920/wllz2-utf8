// xiaosonglin.c - 小松林

inherit ROOM;

void create()
{
	set("short", "小松林");
	set("long", @LONG
这里是红娘庄后的一片小松林，松林中松树高大挺拔，枝叶茂盛，把
松林里遮盖得严严实实的，隐约几道光线，偷偷的投射到松林里，十分好
看。几只小松树正在松树上相互追逐、嬉闹。
LONG
);

	set("outdoors", "center");
	set("exits", ([
		"east"	: __DIR__"hongniangzhuang",
	]) );			
	set("objects", ([
		__DIR__"npc/songshu": 2,
		__DIR__"npc/hare": 2,
		__DIR__"npc/bird": 2,
	]) );
	setup();
	replace_program(ROOM);
}
