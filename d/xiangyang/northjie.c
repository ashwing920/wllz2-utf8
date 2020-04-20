// Room: /d/xiangyang/northjie.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北面是玄武内门，南边
显得很繁忙。东边是一茶馆，一面上书“茶”的招幡在风中轻轻地摇曳着
，一股股茶香扑面而来。西面是襄阳城的北兵营，隐隐能听见里面传来的
操练声。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"east"  : __DIR__"chaguan",
		"south" : __DIR__"dingzi",
		"west"  : __DIR__"bingying1",
		"north" : __DIR__"northgate1",
	]));
	setup();
	replace_program(ROOM);
}

