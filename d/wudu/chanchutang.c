// Room: /d/wudu/caofang1.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","蟾蜍堂");
	set("long", @LONG
这里是五毒神教的蟾蜍堂，墙上画着一些蝎子的图腾，正中一张香桌
，上面放着一只铁盒子(hezi)，顶上垂下一盏大油灯，将这里照得明亮如
昼。
LONG
);
	set("exits", ([
		"east" : __DIR__"zoulang5",
	]));
	set("objects", ([
		__DIR__"npc/nandizi4" : 1,
		__DIR__"npc/nvdizi4" : 1,
	]));
	set("item_desc", ([
		"hezi" : "一只黑乎乎的盒子，不知道里面装的是什么。\n",
	]));
	set("geted",1);
	setup();
}
void init()
{
	add_action("do_open","open");
}
int do_open(string arg)
{
	object me,book;
	me = this_player();

	if(!arg || arg == "" || arg != "hezi") return 0;
	if(!query("geted"))
		message_vision("$N打开铁盒子，发现里面空空如也，什么也没有。\n",me);
	else {
		message_vision("$N打开铁盒子，找到了一本钩法精要。\n",me);
		book = new("/d/wudu/obj/hook-book4");
		set("geted",0);
		book->move(me);
		CHANNEL_D->do_channel(find_object(SEC_OB),"rumor",sprintf("听说%s拿到了%s了！",me->name(1),book->name(1)));
	}
	return 1;
}
void reset()
{
	set("geted",1);
}