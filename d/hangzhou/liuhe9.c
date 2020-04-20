// liuhe9.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "六和塔");
	set("long", @LONG
这里是六和塔的九层。窗(window)外是浓妆淡抹的西子湖，塔中玲珑
八角，青砖砌地，雕栏飞檐间粘连了些许蛛网。
LONG
);
	set("exits", ([
		"down"  : __DIR__"liuhe8",
		"up"	: __DIR__"liuhea",
	]));
	set("objects", ([
		__DIR__"honghua/zhao" :1,
	]));
	set("item_desc", ([
		"window": "从窗口望出去，钱江东去。近处农田中，有一农夫正荷锄耕耘。\n",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "up" &&
		objectp(present("zhao banshan", environment(me))))
		return notify_fail("赵半山笑嘻嘻地挡住你的去路：再玩玩才走啦。气得你半死！\n");
	return ::valid_leave(me, dir);
}
