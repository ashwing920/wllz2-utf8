// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
一间宽敞的房间，空荡荡的没有任何摆设，地下铺着坚实的青石板。
中央放着几个铜人，是给日月神教的弟子们练功用的。
LONG
);
	set("exits", ([
		"south" : __DIR__"changlang3",
		"north" : __DIR__"liangongfang2",
	]));
	set("objects", ([
		__DIR__"npc/tong-ren" : 4,
	]));
	setup();
	replace_program(ROOM);
}
