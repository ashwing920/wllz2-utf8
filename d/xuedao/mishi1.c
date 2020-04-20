// zoulang1.c 密室
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short","密室");
	set("long",@LONG
原来这是间透明晶石的密室，下面看起来象透明的一样。一个水景盒
(hezi)，不知道里面藏了些什么东西。
LONG
);
	set("exits",([
		"down"   : __DIR__"neishi",
	]));
	 set("item_desc", ([
		"hezi" : "一个流艳四射的水景盒,仿佛可以打开。\n",
	]));
	setup();
}
void init()
{
	add_action("do_open", "open");
	
}
int do_open(string arg)
{
	object paper, me=this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="hezi" ){
		if ((me->query("family/master_id") !="xuedao laozu") &&
		objectp(present("xuedao laozu", environment(me)))){
			return notify_fail("血刀老祖传音喝道：你这" + RANK_D->query_respect(me) + "，你想死?\n");
			return 1;
		}
		if (!query("had_yunu")){
			message_vision("$N运功吸开水晶盒，发现里面有一本书...。\n", this_player());
			paper = new("/clone/book/bxuedao");
			paper->move(__FILE__);
		message("channel:rumor", HIM"【武林传奇】某人："+this_player()->query("name")+"拿到碧血刀啦。\n"NOR, users());
			set("had_yunu", 1);
			return 1;
		}
		message_vision("$N运功吸开水晶盒，可是里面啥都没有...。\n", this_player());
		return 1;
	}
	return 0;
}



