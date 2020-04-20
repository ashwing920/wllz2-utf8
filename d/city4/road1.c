//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","关洛道");
	set("long",@LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向脂粉之都
的扬州，往西则直达长安城。
LONG
);
	set("exits",([
		"east" : "/d/city/ximenroad",
		"west" : __DIR__"hanguguan",
	]));
	set("objects",([
		"/d/mingjiao/yuan/zhaomin" : 1,
		"/d/mingjiao/yuan/zhao1" : 1,
		"/d/mingjiao/yuan/qian2" : 1,
		"/d/mingjiao/yuan/sun3" : 1,
		"/d/mingjiao/yuan/li4" : 1,
	]));
	set("outdoors","changan");

	setup();
	replace_program(ROOM);
}






