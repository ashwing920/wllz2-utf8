// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short","绝崖");
	set("long", @LONG
你来到了黑木崖上的悬崖边，脚下是万丈深渊，站在此间，稍一不慎
，便会粉身碎骨，葬身于此。山涧之中的风呼啸的向你袭来，吹得你阵阵
发抖。
LONG
);
	set("exits",([
		"north" : __DIR__"houhuayen",
	]));
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	set("outdoors","riyue");
	setup();
}
void init()
{
	  add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	object ob;
	int new_jing;
	ob = this_player();
	new_jing = random( ob->query("max_jing")*3 );
	if ( new_jing > ob->query("jing") ) new_jing = ob->query("jing") + 1;
	if( !arg || arg=="" ) return 0;
	if( arg != "down" )
		return notify_fail("你要跳下去？想自杀？用suicide -f 快一点：P！\n");
	if( (ob->query("dex") < 20) && ((int)ob->query_skill("dodge")<30) )
		return notify_fail("以你现在的身手，跳下去只有死路一条！\n");
	message_vision("$N毫不考虑，一个纵身，跳了下去。\n", ob);
	environment(ob), ({ob});
	message_vision("$N空中变换身形，一个空翻，轻飘飘地落在地上！\n", ob);
	environment(ob), ob;  
	ob->receive_damage("jing", new_jing);
	ob->move(__DIR__"dashikuai");
	return 1;
}
