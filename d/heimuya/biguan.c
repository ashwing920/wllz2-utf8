// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "闭关室");
	set("long", @LONG
这里是任我行在地下练功的密室。密室虽小，却也五脏俱全，当时任
我行把日月大权交给东方不败后，就是在这苦练吸星大法。
LONG
);
	set("exits", ([
		"up" : __DIR__"xiaosiwu",
	]));

	set("objects",([
		__DIR__"npc/obj/book4" : 1,
	]));

	set("item_desc", ([
		"石壁" : "这是一整块用内力雕成的石壁，上面刻了些奇怪的图形。\n",
	]));

	setup();
}
void init()
{
	add_action("do_canwu","canwu");
}
int do_canwu(string arg)
{
	object me;
	int ski;
	me = this_player();
	ski = (int)me->query_skill("blade", 1);
	if( !arg || arg == "" || arg != "石壁") return 0;
	
	if((int)me->query_skill("literate", 1) < 60)
		return notify_fail("你的学识太少，无法领悟图形上的高深的刀法。\n");
	if((int)me->query_skill("blade",1) < 20 )
		return notify_fail("你的刀法火候太浅，无法领悟图形上的高深的刀法。\n");
	if((int)me->query("jing") < 40)
		return notify_fail("你太累了，无法领会石壁上的图形。\n");
	if((ski * ski * ski) / 10 > (int)me->query("combat_exp"))
		return notify_fail("可能是实战经验不足，你对石壁上的图形总是无法领会。\n");
	if(ski > 100)
		return notify_fail("你对着石壁上的图形琢磨了一回儿，觉得没什么意思，可能对于你来说太浅了。\n");

	message_vision("$N正专心研读石桌上的古怪图形。\n", me);
	me->receive_damage("jing",10);
	me->improve_skill("blade", me->query_int() + ski);
	write("你对着石壁上的图形琢磨了一回儿，似乎对刀法有点心得。\n");

	return 1;
}
