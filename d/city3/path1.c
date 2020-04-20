// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: path1.c

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "溪岸小路");
	set("long", @LONG
你走在浣花溪岸的小路上，浣花溪水晶莹剔透，岸草如茵，远远就能
闻到水气的清香。许多睡莲散布在溪岸附近，水面飘著数不尽的浮萍，浮
萍下有不少艳红锦鲤穿梭来去。溪岸小路随溪流曲折盘绕，芳草没足，花
飘似海，使人不饮自醉。古人所谓 "如行春郊" ，诚不我欺。
LONG
);
	set("outdoors", "chengdu");
	set("exits", ([
		"north"  : __DIR__"path2",
		"east"   : __DIR__"nanheqiaow",
	]));
	
	setup();
	replace_program(ROOM);
}
