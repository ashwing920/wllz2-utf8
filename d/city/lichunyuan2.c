// lichunyuan2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "丽春院二楼");
	set("long", @LONG
你站在丽春院二楼。满耳的淫声秽响不绝如缕。布置的绝对精致的床
上地下，突然对你产生莫名的诱惑和冲动。几个可怜兮兮的千娇百媚在点
手儿招你，你想到她们可能就是昔日江湖中的眼高于顶，顿时大为开心。
LONG);
	set("exits", ([
		"down" : __DIR__"lichunyuan",
	]));
	set("objects", ([
		__DIR__"npc/guigong" : 1,
	]));
	set("no_fight",1);
	set("no_steal",1);
	set("no_beg",1);
	setup();
}
int valid_leave(object me, string dir)
{
	me = this_player();
	if (me->query_condition("prostitute"))
	  return notify_fail("龟公一把抱住你：看你往哪里逃！\n");
	else  return 1;
}
