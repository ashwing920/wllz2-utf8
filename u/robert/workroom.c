// workroom.c

#include <ansi.h>
#include <login.h>

inherit ROOM;

void create()
{
	set("short", "大树顶端");
	set("long", @LONG
密密麻麻的枝叶，仿佛一把大伞，把树顶遮掩住了。站在树顶，可以
看见武林列传的每一个角落。然而这里，却是蝴蝶和小鸟经常拍拖的地方
。每天晚上，小鸟和蝴蝶都会在这里通宵达旦的聊天、看星星，情话绵绵
真是“$HIW$只羡鸳鸯不羡仙$NOR$”，好一对神仙情侣呀。
LONG
);
	set("exits",([
		"south":"/u/sbird/workroom",
		"down":"/d/wizard/wizard_room",
		"gc":  "/d/center/guangchang",
		"tonews": "/d/wizard/news_room",
		"start":START_ROOM,
	]));
	set("locked","开启");
	set("valid_startroom",1);     
	call_other("/clone/board/ymh","??");
	setup();
}
void init()
{
	object ob;
	ob = this_player();
	
	if( interactive(ob) && userp(ob) && !ob->id("robert")
	&& query("locked") == "关闭") {
		remove_call_out("kickout");
		call_out("kickout",1,ob);
	}
	add_action("do_save","save");
	add_action("do_lock","lock");
}
int do_save(string arg)
{
	object ob;
	ob = this_player();
	if(ob->query("id") != "robert" && ob->query("id") != "sbird") {
	ob->move(START_ROOM);
	ob->set("startroom","/d/center/guangchang");
	return 1;
	}

	return 0;

}
int do_lock(string arg)
{
	object me;
	me = this_player();

	if(!me->id("robert")) 
		return notify_fail("你没有权利对该房间进行操作。\n");

	if(arg == "?") {
		write(sprintf("房间模式：%s\n",query("locked")));
		return 1;
	}
	else if(arg == "close"){
		set("locked","关闭");
		write("这里已经被你锁住了。\n");
		return 1;
	}
	else if(arg == "open"){
		set("locked","开启");
		write("这里已经被你开启了。\n");
		return 1;
	}
	else return 0;
}
void kickout(object ob)
{
	if(!ob || environment(ob) != this_object()) return;
	ob->move("/d/center/guangchang");
	tell_room(environment(ob),sprintf("%s(%s)被人一脚从蝴蝶居踢了出来，模样十分狼狈。\n",ob->name(1),ob->query("id")));
}