// yuanzi
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com


inherit ROOM;

void create()
{
	set("short", "大门");
	set("long",@LONG
这就是闻名天下的『白驼山庄』的大门。大门梁上雕龙刻凤，美奂美
仑，不知凝聚着多少能工巧匠的心血。更显出庄主的富有与显贵。门前左
右各蹲着一只威武庄严的石狮子。
LONG
);
	set("outdoors", "baituo");
	set("exits", ([
		"north" : __DIR__"yuanzi",
		"southdown" : __DIR__"shijie",
	]));
	set("objects",([
		__DIR__"npc/menwei" : 2,
	]));
	setup();
}

int valid_leave(object me, string dir)
{

	if((dir == "north")
		&& ((int)me->query("shen") > 3000)
		&& objectp(present("men wei", environment(me)))
		&& living(present("men wei", environment(me))))
	return notify_fail("门卫把手一拦：你这种正派人物，老子一看就恶心，快滚！\n");
	return ::valid_leave(me, dir);
}
