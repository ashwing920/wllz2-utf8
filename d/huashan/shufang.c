//shufang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

#include <ansi.h>

void create()
{
	set("short","华山书房");
	set("long",@LONG
这里是华山剑派的书房，靠墙是一排书架，里面堆着乱七八糟的一大
堆书，最近老有人上山寻事，都很久没人整理书房了，要找啥书都很麻烦
。右侧有张书桌，桌上四宝俱备。
LONG
);
	set("exits",([
		"north" : __DIR__"garden",
	]));
	if (random(5) > 3)
	set("objects",([
		"/clone/book/zhengqi_book" : 1,
	]));
	set("book_count", 1);
	setup();
}
void init()
{
	add_action("do_zhengli", "zhengli");
}
int do_zhengli()
{
	object ob, me=this_player();
	me->add("qi", -5);
	if ((query("book_count") > 0) && (random(5) == 3))
	{
		message_vision(HIY"$N辛辛苦苦整理了好半天，居然在破杂物堆里发现了一本书。\n"NOR,me);
		ob=new("/clone/book/sword_book2");
		ob->move(me);
		message("channel:rumor", HIM"【武林传奇】某人："+this_player()->query("name")+"发现了华山剑谱啦。\n"NOR, users());
		add("book_count", -1);
	}
	else message_vision(HIY"$N辛辛苦苦整理了好半天，啥都没找到，真是白忙了。\n"NOR,me);
	return 1;
}
