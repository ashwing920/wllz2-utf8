// /d/kunming/jinrilou

inherit ROOM;

void create()
{
        set("short","王府大门");
	set("long", @LONG
这里便是平西王府的大门，两边个有一个威武的大石狮子，高大的朱
漆大门紧紧的闭着，几个亲兵严密的注视着来往的人，没什么事，最好别
在这里溜达。
LONG
);
	set("outdoors", "kunming");
	set("exits", ([
		"south"    :__DIR__"beidajie",
		"north"   :__DIR__"wangfu1",
	]));
	set("objects",([
		__DIR__"npc/qinbing":4,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if ( dir == "north" && objectp(present("qin bing", environment(me))))
		return notify_fail("亲兵拦住你说道：王府大院，闲杂人等一律回避。\n");
	return ::valid_leave(me, dir);
}

			
