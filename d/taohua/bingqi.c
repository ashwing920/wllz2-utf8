// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long", @LONG
这是一间存放兵器的屋子。刀、枪、剑、戟等各种兵器都按类放在各
自的兵器架上。整个屋子落满灰尘，显然已经好久没人来过。
LONG
);
	set("exits", ([
		"west" : __DIR__"qianyuan",
	]));
	set("objects", ([
		__DIR__"obj/taojian": 5,
	]) );
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
		if (inv[i]->query("id") == "taomu jian") j++;
	}
	if (j > 1)
		return notify_fail("突然有个声音说道：这位" + RANK_D->query_respect(me) + "别那麽贪心，带走一把桃木剑就够啦。\n");
	return ::valid_leave(me, dir);
}
