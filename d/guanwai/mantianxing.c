//guanwai/mantianxing.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "满天星");
	set("long", @LONG
这里是一片开阔的平原，附近不但没有任何小山丘陵，就连一棵树也
找不到。抬眼望去，地平线笔直的将蓝天与雪原分隔在两边。据说夜间因
这里无物遮挡，可遍观满天星斗。进山的人们多在此祈求上苍的保佑。
LONG
);
	set("exits", ([
		"southeast" : __DIR__"caoguduo",
		"west"	  : __DIR__"ermenkan",
	]));
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
