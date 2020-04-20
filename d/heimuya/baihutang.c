// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "白虎堂");
	set("long", @LONG
这里是日月教的百虎堂，也是平日教中弟子演练武功的地方，大堂内
摆放着各种各样的武器，还有不同大小的沙袋、石锁、石盘等器具，中央
还竖立着几十根高低不等的木桩(zhuang)。
LONG
);
	set("exits",([
		"east" : __DIR__"zhuquetang",
		"south" : __DIR__"changlang",
	]));
	set("objects",([
		CLASS_D("riyue") + "/sang" : 1,
	]));
	set("item_desc", ([
		"zhuang" : "这些木桩由于经常有人在上面跳跃(jump),顶端异常光滑。\n",
	]));
	setup();
}
void init()
{
	add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	int xianzhi;
	object me;

	me = this_player();

	if ( !arg || ( arg != "zhuang" ) )
		return notify_fail("什么？\n");
	if ( (int)me->query("combat_exp") >0) xianzhi=10;
	if ( (int)me->query("combat_exp") >800) xianzhi=20;
	if ( (int)me->query("combat_exp") >900) xianzhi=30;
	if ( (int)me->query("combat_exp") >6400) xianzhi=40;
	if ( (int)me->query("combat_exp") >12500) xianzhi=50;

	if ( (int)me->query("jing") < 40)
		return notify_fail("你已经很累的了，先休息一下吧。\n");

	me->receive_damage("jing", 1*random(40));
	message_vision("$N纵身跃上了木桩，在木桩间高低来回地跳跃着。\n", me);

	if ( (int)me->query_skill("dodge", 1) < xianzhi){
		me->improve_skill("dodge", me->query("int"));
		write("你在纵身跳跃之间若有所悟，似乎对基本轻功有点心得。\n");
		me->set_temp("stone_learned",1);
	}
		else {
		write("你拼命地跳来跳去，却感觉不到任何进展，可能是你经验不足或基本轻功已经大于五十级了。\n");
	}
	return 1;
}

