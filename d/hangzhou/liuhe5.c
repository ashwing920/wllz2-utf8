// liuhe5.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "六和塔");
	set("long", @LONG
这里是六和塔的五层。窗(window)外是浓妆淡抹的西子湖，塔中玲珑
八角，青砖砌地，雕栏飞檐间粘连了些许蛛网。
LONG
);
	set("exits", ([
		"down"  : __DIR__"liuhe4",
		"up"	: __DIR__"liuhe6",
	]));
	set("objects", ([
		__DIR__"honghua/wei" :1,
	]));
	set("item_desc", ([
		"window": "从窗口望出去，钱江东去。近处农田中，有一农夫正荷锄耕耘。\n",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "up" &&
		objectp(present("wei chunhua", environment(me))))
		return notify_fail("卫春华大吼一声：我有九条命，你有几条？放马过来！\n");
	return ::valid_leave(me, dir);
}
