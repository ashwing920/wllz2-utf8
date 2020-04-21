
inherit ROOM;

int do_pai(string arg);

void create()
{
	set("short","水池");
	set ("long",@LONG
这是一大水池。一阵微风吹过，水中菏叶随风在水面上轻轻漂浮，水
面(mian)碧波涌起，妙不可言。水池中央有一座假山，其中的石洞是很多
的，使人忍不住想探个究竟。
LONG);
	set("outdoors","yanziwu");
	set("item_desc",([
		"mian" : "水面泛着涟漪，闪烁着点点光亮，几只蜻蜓落在荷花上。\n"
	]));
	set("exits", ([
		"west" : __DIR__"xiaojing7",
	]));
	setup();
}
void init()
{
	add_action("do_jump", "jump");
	add_action("do_clean","clean");
}

int do_jump(string arg)
{

	object me;
	me = this_player();

	if (arg !="chi")
		return notify_fail("你要跳到哪去？\n");
	 
	if (me->query_dex()<17) 
		write("你试图跳过水池，无奈身法不够敏捷，只好做罢。\n");
	else {
		write("你纵身跳过了水池,落到了假山上。\n");
		message("vision",me->name() + "一纵身越过了水池。\n",environment(me), ({me}) );
		me->move(__DIR__"jiashan");
		message("vision",me->name() + "从水池边跃了上来。\n",environment(me), ({me}) );
		return 1;
	}
}
int do_clean(string arg)
{
	object me = this_player();
	object ob;			  
	if (! (ob = present("paper", me)) || userp(ob))
	return notify_fail("你要干什么？\n");
	if (arg != "paper" && arg != "纸卷") 
	return notify_fail("你要干什么？\n");
	write("你不经意的把纸卷丢到水池中。\n",me);
	write("纸卷渐渐干净了，显出了一行行小字。\n", me);
	destruct(ob);
	ob = new(__DIR__"npc/obj/paper1.c");
	ob->move(me);
	return 1;
}