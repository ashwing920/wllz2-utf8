// up-01s3e.c - 千金楼（厢房）

inherit ROOM;

void create()
{
	set("short","厢房");
	set("long", @LONG
这里是千金楼二楼一间普通的厢房。厢房里收拾得十分干净，一张大
床陈列在厢房的右侧，床上挂着一廉粉红色的床帘，十分好看。厢房中央
有一张八仙桌，几个女子正坐在桌旁和一个年轻公子喝酒划拳。
LONG
);
	set("exits", ([
		"west"  : __DIR__"up-01s3",
	]));

	set("objects", ([
		__DIR__"npc/mingji-m": 1,
		__DIR__"npc/jinu": 2,
		__DIR__"npc/nianqing-gongzi": 1,
	]));
	setup();
	replace_program(ROOM);
}