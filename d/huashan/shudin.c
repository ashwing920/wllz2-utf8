// jiashan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","松树树顶");
	set("long",@LONG
这是紫气台的松树顶上，你站在树上，四周的山还有云，都在你的脚
下，苍山如黛，若隐若现，顿时感到心旷神怡，据说这曾经也是金蛇郎君
来过的地方，当年他就是在此突然绝迹江湖的。
LONG
);
	set("exits",([
		"down"  :  __DIR__"ziqitai",
	]));
	setup();
}
void init()
{
	object me;
	me=this_player();
	if (me->query_dex() < 40){
	this_object()->delete("exits/enter");
	message_vision("可惜啊！$N好不容易上来，却什么也没有发现！\n",me);
	this_player()->delete_temp("jinshe");
	remove_call_out("close");
	call_out("close", 1, this_object());
	}
	else
	call_out("loadroom",1,me);
	return;
}
void loadroom()
{
	object me;
	me=this_player();
	if (me->query_dex() > 40)       
		message_vision("突然在$N的眼前出现了一条路！\n",this_player());   
		this_player()->delete_temp("jinshe");  
		this_object()->set("exits/enter", "/d/jinshe/shanbi");
		call_out("close",10,this_object());
	}

void close(object room)
{
	this_object()->delete("exits/enter");        
	return;
}
