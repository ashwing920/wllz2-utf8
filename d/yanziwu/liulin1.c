
inherit ROOM;

void create()
{
	set("short","柳树林");
	set("long",@LONG
这是一片碧绿的柳树林，一片碧绿的颜色，柳树看上去枝叶茂盛，树
上几只小鸟唧唧喳喳的叫个不停，柳条随着微风轻轻摆动。
LONG);
	set("exits",([
		"west" : __DIR__"liulin",
		"east" : __DIR__"liulin2",
		"north" : __DIR__"liulin3",
		"south" : __DIR__"xiaojing6",
	]));
	setup();
	replace_program(ROOM);
}
