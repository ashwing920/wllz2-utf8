//d/kunlun/huapu.c

#include <ansi.h>
inherit ROOM;

int do_pull(string arg);

void create()
{
	set("short", "花圃");
	set("long", @LONG
这里是一个美丽而幽静的花园，园子里面种满了鲜艳且古怪的鲜花，
白雪红花、绿叶，构成一幅鲜艳且鬼魅的图画。
LONG
);
	set("outdoors","kunlun");
	set("exits", ([
		"south" : __DIR__"wgws",
	]));
	set("flower",1);
	set("item_desc", ([
		"鲜花" : @TEXT
这花开放时有檀香之气，花朵的颜色又极娇艳。其茎如球，颜色火红。极
象是从西域传来的灵脂兰。
TEXT,
		"flower":@TEXT
这花开放时有檀香之气，花朵的颜色又极娇艳。其茎如球，颜色火红。极
象是从西域传来的灵脂兰。
TEXT,
	]));
	setup();
}
void init()
{
	add_action("do_pull", "pull");
}
int do_pull(string arg)
{
	object me,ob;
	me = this_player();

	if(!arg ) 
		return notify_fail("你要拔什么？\n");

	if( arg != "鲜花" && arg != "flower" )
		return notify_fail("你要拔什么？\n");

	if((int)query("flower") ){
		ob=new(__DIR__"obj/lingzhiflower");
		message_vision("$N拔出"+ob->query("unit")+ob->query("name")+"。\n",me);
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s从花圃里拔出了一株%s！",
			me->name(),ob->name()+HIM));
		ob->move(me,1);
		delete("flower");
		delete("item_desc");
		return 1;
	}
		return notify_fail("这里的鲜花已经被采光了。\n");
}
void reset()
{
	set("flower",1);
}