//cave1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","岩洞内");
	set("long",@LONG
这里是岩洞内部，洞顶上悬挂着洁白的钟乳石。洞里静悄悄的，洞顶
上的钟乳石尖偶尔滴下一滴水珠，轻轻的发出叮咚的声响。这里虽然光线
昏暗，凉风阵阵，但却绝对是闭关修炼的好地方。
LONG
);
	set("exits",([
		"south" : __DIR__"cave",
	]));
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
