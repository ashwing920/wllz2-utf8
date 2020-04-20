// work.c

inherit ROOM;
int cot;
void create()
{
	set("short", "谷物加工厂");
	set("long", @LONG
这是一间谷物加工厂，这里是谷子脱壳成米的地方。米厂老板是一个
一看就知道是十分精明的干瘦的中年人，老是带着一脸奸笑。你可以看到
许多人正在忙忙碌碌的工作着，门口挂著一块牌子(sign)。
LONG
);
	set("no_sleep_room",1);
	set("exits", ([
		"north" : __DIR__"roade3",
	]));
	set("item_desc", ([
		"sign": @TEXT
现在正紧缺人手，急需雇佣一批短工来干活。每次25两白银。
work     开始工作。
TEXT
	]));
	setup();
}

void init()
{
	add_action("do_work", "work");
}
int do_work(string arg)
{
	object me;
	me = this_player();
	if ((int)me->query("jing")<30 || (int)me->query("qi")<30) 
		return notify_fail("你快累死了，要钱不要命了吗？\n");
	if (me->query_temp("working")) 
		return notify_fail("加油呀！谁叫你穷呀！\n");
	if (cot > 5)   
		return notify_fail("老板嘿嘿一笑：我这里人手已经够了，做义工可没工钱的哟！\n");
	message_vision("$N开始辛苦地工作......\n", me);
	cot++;
	me->set_temp("working",1);
	me->start_busy(4);
	call_out("working",4,me);
	return 1;
}
int working(object me)
{
	object ob;
	if (!me) return 1;
	message_vision("$N辛苦的工作终于结束了，可人也累的半死。\n", me);
	me->add("jing",-30);
	me->add("qi",-30);
	ob = new("/clone/money/silver");
	ob->set_amount(25);
	ob->move(me);
	message_vision("老板冷冷地对$N说：这是你的工钱。\n", me);
	me->set_temp("working",0);
	me->start_busy(0);
	cot--;
	return 1;
}
void reset()
{
	cot=0;
	::reset();
}

