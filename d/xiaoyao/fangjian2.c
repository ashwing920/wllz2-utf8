// fangjian2.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "房间");
	set("long", @LONG
这是一间布置成卧室模样的小房间，有张石床，床上摆着个小小的木
头制成的摇篮，墙壁上悬着一个七弦琴，弦线都已经断了。
LONG
);
	   set("exits", ([
		   "south" : __DIR__"shiji2",
	   ]));
	   setup();
}
void init()
{
	add_action("do_han", "han");
}
int do_han(string arg)
{
	object me;
	mapping fam;
	me = this_player();

	if(!arg || arg == "") return 0;


	if( arg != "逍遥自在")
		return notify_fail("你气运丹田，对着墙壁大喝一声：“"+ arg +"！”，结果什么反应都没有。\n");

	if(arg == "逍遥自在") 
	{
		tell_object(me,"你气运丹田，对着墙壁大喝一声：“逍遥自在！”\n");
		if(random(100) > 50 
			|| (mapp(fam = me->query("family")) && fam["master_name"]=="逍遥子"))
		{
			message("vision", "过了一会儿，你只听到一阵轰隆隆的响声，出现了一道暗门。\n",me);
			set("exits/down", __DIR__"shishi4");
			remove_call_out("close");
			call_out("close", 5, this_object());
		}
		else
		{
			message("vision", "房间里到处回荡着你的声音，震得你的耳朵翁翁作响。\n", me);
			me->unconcious();
		}
		return 1;
	}
}
void close(object room)
{
	message("vision","一阵轰隆隆的响声过后，石门又缓缓地关上了。\n", room);
	room->delete("exits/down");
}
