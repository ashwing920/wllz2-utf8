// dating.c 大厅
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","大厅");
	set("long",@LONG
这里是寺内的大厅，一进门就听到一阵女子笑声，一个老和尚从一女
子怀里抬起头来不高兴的瞪了你一眼，房子高的离谱，仿佛有个洞，看不
清楚，可能你的轻功太差。
LONG
);
	set("exits",([
		"east" : __DIR__"zoulang1",
		"west" : __DIR__"zoulang2",
	]));
	set("objects", ([
		CLASS_D("xuedao")+"/xuedao" :1,
	]));
	setup();
	
}
void init()
{
	object me;
	me=this_player();
	if (me->query_dex() > 35)
		this_object()->set("exits/up","/d/xuedao/mishi1");
	else
		this_object()->delete("exits/up");
	remove_call_out("close");
	call_out("close", 5, this_object());
	return;
}
void close(object room)
{
	this_object()->delete("exits/up");
	return;
}


