// Room: /d/wudu/road1. c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
这是一条不宽的小路，上面以石板铺垫，北边，可以看见昆明南门高
高的城楼，向南而去，直通滇池，路上不时有一些渔民提着新鲜的鱼来往
，几个少数民族的妇女提着些鸡蛋，洱块也往城里赶去。
LONG
);
	set("outdoors", "wudu");
	set("exits", ([
		"south" : __DIR__"road2",
		"north" : "/d/kunming/nanmen",
	]));
	setup();
	replace_program(ROOM);
}

