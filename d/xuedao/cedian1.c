// cedian1.c 侧殿
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","侧殿");
	set("long",@LONG
这里是血刀门的东侧殿。殿内有神色狞历的罗汉塑像，光线暗淡，很
是恐怖。
LONG
);
	set("exits",([
		"north": __DIR__"zoulang1",
		"west" : __DIR__"dadian",
	]));
	set("objects",([
		CLASS_D("xuedao")+"/baoxiang" : 1,
	]));
	setup();

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
	int lvl = this_player()->query_skill("miexian-zhang",1);

	if ((int)ob->query_skill("xuehai-mogong", 1) < 10)
	{
		message_vision("$N的血海魔功不够，看不懂上面刻的是什么。\n",ob);
		return 1;
	}
	if ((int)ob->query_skill("miexian-zhang", 1) > 40)
	{
		message_vision("$N的灭仙掌早就超越壁上所刻了。\n",ob);
		return 1;
	}
	if((lvl * lvl * lvl/10) > (int)ob->query("combat_exp"))
	{
		message_vision("$N的实战经验不足，无法领悟壁上内容。\n",ob);
		return 1;
	}
	if (ob->query("jing")<20)
	{
		 message_vision("$N太累了，现在无法领悟壁上内容。\n",ob);
		 return 1;
	}
	message_vision("$N面对着壁上图案揣摩良久，有点感觉。\n",ob);
	ob->improve_skill("miexian-zhang", random(ob->query("int")));
	ob->receive_damage("jing", 15);
	return 1;
}
int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam=(mapping)me->query("family");
	if( (!myfam || myfam["family_name"] !="血刀门") && dir=="up"
	&& objectp(present ("jiamu huofo", environment(me))))
		return notify_fail("宝象说道: 你非血刀门弟子, 不能入内。\n");
	return ::valid_leave(me,dir);
}


