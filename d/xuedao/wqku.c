// wqku.c 武器房
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "武器房");
	set("long", @LONG
这里是血刀门的武器房，四周放这几个兵器架，上面有血刀门各弟子
平时用的小血刀。
LONG
);
	set("exits", ([
		"east" : __DIR__"lwchang",
	]));
	set("objects", ([ 
		"/d/xuedao/obj/xuedao" : 4
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	int i, j;
	object *inv;
	inv = all_inventory(me);
	i = sizeof(inv);
	for (i = 0; i < sizeof(inv); i++){
		if (inv[i]->query("id") == "xue blade") j++;
}
	if (j > 1)
		return notify_fail("这位" + RANK_D->query_respect(me) + "别那麽贪心，给别的师兄弟留一把吧!\n");
	return ::valid_leave(me, dir);
}

