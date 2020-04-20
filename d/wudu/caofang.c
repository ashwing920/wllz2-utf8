// Room: /d/wudu/caofang.c

inherit ROOM;

void create()
{
	set("short",  "草房");
	set("long", @LONG
一间十分简陋的草房，四壁光突突的，什么也没有，墙角堆着几只藤
篓(lou)，几把锄头，看上去有点古怪。南边通着一间厢房。
LONG
);
	set("exits", ([
		"east" : __DIR__"xiaolu1",
		"south" :__DIR__"caofang1",
	]));
	set("item_desc", ([
		"lou" : "几只藤篓，堆在墙角，碍手碍脚的，你真想狠狠的踢它一脚。\n",
	]));
	setup();
}
int init()
{ 
	add_action("do_kick", "kick");	
}
int do_kick( string arg)
{
	object me,ob;
	me = this_player();

	if( arg =="" || !arg || arg != "lou") return 0;
	if(query("snake") < 10){
		message_vision("$N刚想去碰那只藤篓，忽然从里面爬出了一尾毒蛇。\n",me);
		ob=new(__DIR__"npc/dushe");
		ob->move(this_object());
		add("snake",1);
	}
	else {
		message_vision("$N飞起一脚，狠狠的往藤篓踢去，发出“啪”的一声声响。\n",me);	
	}
		return 1;
}
void reset()
{
	delete("snake");
}
