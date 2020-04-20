//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "大官道");
	set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东通向函谷关，
往西北则直达长安城。
LONG
);
	set("exits",([
		"northwest" : __DIR__"road4",
		"east"	 : __DIR__"zhongnan",
		"west"	 : "/d/quanzhen/guandao1",
	]));
	set("outdoors","changan");

	setup();
	replace_program(ROOM);
}






