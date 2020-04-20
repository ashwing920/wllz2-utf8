// xiaodao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走到这条小路上，前面已经可以隐隐约约看到一座小小的院落的影
子，你可以非常的肯定，琴声就是从这个小院里发出来的，想到立刻就可
以见到大庄主黄钟公了，你不禁一阵紧张。 
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"xiaoyuan",
		"westdown" : __DIR__"qhpo",
	]));
	set("outdoors", "meizhuang");
	setup();
	replace_program(ROOM);
}

