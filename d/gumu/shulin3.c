// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
这里是树林的边缘，参天古树已经很稀少了。东面有一座高山，隐约
看见山间云雾缭绕中，似乎有什么廊檐的建筑。山势缓和，但山上郁郁葱
葱地栽满了树木。
LONG
);
	set("outdoors", "gumu");
	set("exits", ([
		"south" : __DIR__"caodi",
		"northeast" : __DIR__"shulin2",
	]));

	setup();

}
