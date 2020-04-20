
inherit ROOM;

void create()
{
	set("short","还施水阁");
	set("long",@LONG
这就是举世闻名的姑苏慕容的还施水阁，这里据说有很多武林人事向
往以久的武功。只见墙上有一个书架子(shujia)，上面摆满了各种武籍。
LONG
);
	set("exits",([
		"south" : __DIR__"jiabi",
	]));
	set("item_desc", ([
		"shujia" : "书架上各个门派的武功秘籍(miji)，你忍不住想拿起一本就翻看起来。\n",
	]));
}

int init()
{
	add_action("do_kan","kan");
	add_action("do_kan","du");
	add_action("do_kan","yandu");
	add_action("do_kan","lingwu");
	add_action("do_kan","study");
}

int do_kan(string arg)
{
	object me;
	int skill;
	me = this_player();
	skill = (int)me->query_skill("douzhuanxingyi",1);

	if(!living(this_player()) || arg != "miji" ) return 0;

	if(me->query("family/master_name")!="慕容复") return 0;

	if((int)me->query_skill("literate", 1) < 1)
		return notify_fail("你是个文盲，先学点文化(literate)再领悟斗转星移吧。\n");
	if((int)me->query_skill("parry", 1) < 160 )
		return notify_fail("凭你现在的招架功夫，无法领悟斗转星移这么高深的武功。\n");

	if(skill < 200)
		return notify_fail("你看了半天书架上的武功秘籍，结果对你来说太深奥了！\n");

	if(skill > 300)
		return notify_fail("恭喜恭喜！你已经融会贯通了斗转星移的绝妙之处！\n");

	if((int)me->query("jing")<30) {
		me->receive_damage("jing", 10);
		write("你太累了，已经没有力气来领悟斗转星移了！\n");
		return 1;
	}

	if( (skill * skill * skill) / 10 > (int)me->query("combat_exp"))
		return notify_fail("也许是缺乏实战经验，你对秘籍上的武功总难以理解。\n");

	me->receive_damage("jing", random(50));
	message_vision("$N正在低头沉思有关斗转星移的种种疑难。\n", me);
	write("你静静地钻研各家门派的武功秘籍，冥冥之中你的斗转星移又进了一步。\n");
	me->improve_skill("douzhuanxingyi", me->query_skill("parry"));
	return 1;
}
