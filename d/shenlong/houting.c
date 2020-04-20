// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com
// houting.c

inherit ROOM;
void create()
{
	set("short", "神龙教后厅");
	set("long", @LONG
这是神龙教的议事场所--潜龙厅。此厅较小，前面有两张大竹椅，两
边摆着五个小凳(chair)。
LONG
);
	set("exits", ([
		"south" : __DIR__"dating",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/yin": 1,
	]));
	setup();
}
void init()
{
	add_action("do_move","move");
}
int do_move(string arg)
{
	object me;
	me = this_player();
	
	if(!arg || arg == "" || arg != "chair") return 0;
	if((string)me->query("family/family_name") != "神龙教"){
		message_vision("$N试着把凳子移开，可移了半天，凳子象长了根似的，一点用都没有。\n",me);
		return 1;
	}
	if(query("exits/down"))
		return notify_fail("凳子已经被搬开了。\n");

	message_vision("$N把凳子移了移，凳子下露出了一个黑漆漆的入口。\n",me);
	set("exits/down",__DIR__"biguanshi");
	call_out("close_exits",5);
	return 1;
}
void close_exits()
{
	write("凳子发出“咯吱咯吱”的声响又回到了原位，把入口封闭了。\n");
	delete("exits/down");
}

