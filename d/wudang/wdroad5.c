//Room: wdroad5.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，四周静悄悄的。四周是浓密的树林，阴森森
的十分怕人。西北方就是陕鄂边界了。北边却是一片草地。
LONG
);
	set("outdoors", "wudang");
	set("exits", ([
		"northwest" : __DIR__"wdroad6",
		"north"	 : "/d/xiangyang/caodi6",
		"east"	: __DIR__"wdroad4",
	]));
	setup();
	replace_program(ROOM);
}

