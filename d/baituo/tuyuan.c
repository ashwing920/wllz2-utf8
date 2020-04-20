//room: tuyuan.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","兔苑");
	set("long", @LONG
这是个好玩的兔苑，几只大白兔静静地蹲在绿草地上吃草。往北
是后门，西南方是竹园。西面传来阵阵猛兽的嚎叫，东面有一个蛇园。
LONG
);
	set("exits",([
		"north" : __DIR__"houmen",
		"east"  : __DIR__"sheyuan",
		"west"  : __DIR__"shoushe",
		"southwest" : __DIR__"zhuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/baitu" : 2,
		__DIR__"npc/menwei":2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	me = this_player();

	if( (myfam = me->query("family"))
	&& myfam["family_name"] != "白驼山派"
	&& dir == "west"
	&& objectp(present("men wei", environment(me))))
		return notify_fail("门卫一把拦住：你不是白驼山弟子，不能进兽舍。\n");

	if( (myfam = me->query("family"))
	&& myfam["family_name"] != "白驼山派"
	&& dir == "east"
	&& objectp(present("men wei", environment(me))))
		return notify_fail("门卫一把拦住：你不是白驼山弟子，不能进蛇园。\n");

	return ::valid_leave(me, dir);
}
