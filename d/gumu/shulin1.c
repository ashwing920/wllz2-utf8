// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
这是一片小树林，周围的树木都很高。间杂着一些叫不出名字的鲜花
，五彩缤纷。你隐隐地有些担心起来：不会迷路了吧，转头间却看见东南
边似乎有一条小路，隐藏在树丛之中。
LONG
);
	set("outdoors", "gumu");
	set("exits", ([
		"northdown" : __DIR__"shulin0",
		"southwest" : __DIR__"shulin2",
	]));

	setup();

}
