//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: gudelin2.c 古德林

inherit ROOM;

string look_shibei();

void create()
{
	set("short","古德林");
	set("long",@LONG
这是一片密密的楠木林，株株秀挺俊拔，枝叶分披上捧，如两手拥佛
，据说有七万株之多，要是不熟悉地形很容易迷路。林中有一片空地，几
只楠木桩排成梅花模样。
LONG
);
	set("outdoors","emei");
	set("exits",([
		"south"	 : __DIR__"bailongdong",
		"southeast" : __DIR__"gudelin1",
		"southwest" : __DIR__"gudelin1",
		"northeast" : __DIR__"gudelin1",
		"northwest" : __DIR__"gudelin1",
	]));
	setup();
	replace_program(ROOM);
}
