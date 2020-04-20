
inherit ROOM;

void create()
{
	set("short","柳树林");
	set("long",@LONG
这是一片碧绿的柳树林，一片碧绿的颜色，柳树看上去枝叶茂盛，树
上几只小鸟唧唧喳喳的叫个不停，柳条随着微风轻轻摆动。
LONG);
	set("exits",([
		"south" : __DIR__"xiaojing5",
		"east" : __DIR__"liulin1",
	]));
	set("objects",([
		__DIR__"npc/obj/liutiao" : 2,
	]));
	setup();
	replace_program(ROOM);
}
