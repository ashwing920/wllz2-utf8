// Room: /d/gaibang/undertree.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "谷场槐树边");
	set("long", @LONG
这是谷场槐树边的谷堆，四周都是大谷堆。四周丢满了各种杂物，还
有丐帮弟子收集的破铜烂铁等。从这里通往丐帮的秘密通道。
LONG
);

	set("exits", ([
		"up" : "/d/village/square",
		"south":__DIR__"xcandao2",
	]));

	set("objects",([
		CLASS_D("gaibang") + "/ma-jw" : 1,
		CLASS_D("gaibang") + "/mo-bu" : 1,
	]));

	setup();
	replace_program(ROOM);
}
