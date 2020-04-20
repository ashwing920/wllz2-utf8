// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "海滩");
	set("long", @LONG
这是桃花岛前的海滩。往北是一望无际的大海；往南则是一片桃花林
。蓝蓝的海蓝蓝的天，金黄色的沙滩，粉红的桃花，这一切都是那么美。
海边泊着一艘大船(chuan)。
LONG
);
	set("item_desc", ([
		"chuan" : "这是桃花岛对外联系的大船。岛上的客人或弟子只要\n"
		  "上船(enter)就可以回中原。\n",
	]));
	set("objects",([
		__DIR__"npc/yiren":1,
	]));
	set("exits",([
		"south" :__DIR__"thmz/entry",
	]));
	set("outdoors", "taohua");
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object ob ;
	if( !arg || arg !="chuan" )
		return notify_fail("你要 enter 哪儿？\n" ) ;

	ob = this_player();
	message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
	message_vision("船夫升起帆，船就向西方航行。\n", ob);
	ob ->move("/d/taohua/dahai") ;
	tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
	call_out("rtaohua", 10 , ob );
	return 1 ;
}
void rtaohua( object ob )
{
       if(!ob) return; 
       tell_object(ob , "大船终于抵达了中原的一个繁华城市。你走下船来。\n" ) ;
       ob->move("/d/quanzhou/anhai.c");
}
