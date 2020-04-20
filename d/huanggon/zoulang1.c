// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条走廊。房顶一侧支在西面的高墙上，另一侧则与东侧的清和
殿屋顶相连。彩梁画栋，连顶棚也用彩漆绘满了各种飞天的图形，每幅精
美的雕画似乎都在诉说一个娓娓动人的故事。往西通往后院，南北都有房
间。
LONG
);
	set("exits", ([
		"west" : __DIR__"houyuan",
		"east" : __DIR__"qihedian",
		"south" : __DIR__"fang1",
		"north" : __DIR__"fang2",
	]));
	setup();
	replace_program(ROOM);
}

