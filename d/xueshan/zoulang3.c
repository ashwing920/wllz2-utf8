// zoulang3.c 走廊
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long",@LONG
这里是雪山寺内的走廊。这里有点幽暗，天花板上有一些不知道确切
含义的雕刻，墙壁上则是很通俗的佛经故事壁画了。壁上点着几碗大海灯
照明。
LONG
);
	set("exits",([
		"north"	: __DIR__"neidian",
		"eastdown" : __DIR__"zoulang1",
		"westdown" : __DIR__"zoulang2",
	]));
	setup();
	replace_program(ROOM);
}

void init()
{
	add_action("do_watch", "watch");
	add_action("do_watch", "kan");
	add_action("do_watch", "mianbi");
	add_action("do_watch", "face");
}

int do_watch()
{
	object ob = this_player();
	int lvl = this_player()->query_skill("shenkong-xing",1);

	if ((int)ob->query_skill("xiaowuxiang", 1) < 10)
	{
		message_vision("$N的小无相功不够，看不懂上面刻的是什么。\n",ob);
		return 1;
	}
	if ((int)ob->query_skill("shenkong-xing", 1) > 40)
	{
		message_vision("$N的身空行早就超越壁上所刻了。\n",ob);
		return 1;
	}
	if((lvl * lvl * lvl) > (int)ob->query("combat_exp"))
	{
		message_vision("$N的实战经验不足，无法领悟壁上内容。\n",ob);
		return 1;
	}
	if (ob->query("jing")<20)
	{
		 message_vision("$N太累了，现在无法领悟壁上内容。\n",ob);
		 return 1;
	}
	message_vision("$N面对着壁上图案揣摩良久，似有所悟。\n",ob);
	ob->improve_skill("shenkong-xing", random(ob->query("int")));
	ob->receive_damage("jing", 20);
	return 1;
}

