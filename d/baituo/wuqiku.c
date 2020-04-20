//wuqiku.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long",@LONG
这里是白驼山弟子的武器库，白驼山弟子可以到此拿取练功用的各种
武器。不过别派弟子是不允许进来的。
LONG
);
	set("exits", ([
		"east" : __DIR__"yuanzi",
	]));
	set("objects",([
		 __DIR__"npc/shiwei" : 1,
		 __DIR__"obj/shezhang" : 1,
		 "/clone/weapon/gangzhang" : 2,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	int i, j;
	object *inv;
	inv = all_inventory(me);
	i = sizeof(inv);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (inv[i]->query("id") == "gangzhang") j++;
	}
	if (j > 1)
		return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，带走一条钢杖就够啦。\n");
	return ::valid_leave(me, dir);
}

