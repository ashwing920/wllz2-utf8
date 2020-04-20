//Design By Robert 蝴蝶君 email:stcoolman@21cn.com


inherit ROOM;

void create()
{
	set("short","大官道");
	set("long", @LONG
这是一条宽阔笔直的官道，足可容得下十马并驰。往东南通向函谷关
，往西则直达长安城。
LONG
);
	set("exits",([
		"west"	 : __DIR__"eastgate",
		"southeast" : __DIR__"road3",
	]));
	set("outdoors","changan");

	setup();
	replace_program(ROOM);
}






