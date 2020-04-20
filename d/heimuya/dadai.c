// Design By Robert 蝴蝶君 email:robert_st@sina.com
inherit ROOM;

void create()
{
	set("short", "打袋室");
	set("long", @LONG
一间宽敞的房间，空荡荡的没有任何摆设，地下铺着不同大小的沙袋
(dai)。
LONG
);
	set("exits", ([
		"west" : __DIR__"liangongfang2",
	]));
	set("item_desc", ([
		"dai" : "这些沙袋由于经常有人在打待练功(da),沙袋异常平滑。\n",
	]));
	setup();
	
}
void init()
{
	add_action("do_da", "da");
}
int do_da(string arg)
{
	int xianzhi;
	object me;

	me = this_player();

	if ( !arg || ( arg != "dai" ) )
		return notify_fail("什么？\n");
	if((int)me->query("combat_exp") >0) xianzhi=10;
	if((int)me->query("combat_exp") >800) xianzhi=20;
	if((int)me->query("combat_exp") >900) xianzhi=30;
	if((int)me->query("combat_exp") >6400) xianzhi=40;
	if((int)me->query("combat_exp") >12500) xianzhi=50;

	if((int)me->query("jing") < 40)
		return notify_fail("你已经很累的了，先休息一下吧。\n");
	me->receive_damage("jing",1*random(40));
	message_vision("$N拼尽全力飞出几拳，打在沙袋上,沙袋左右晃了晃。\n", me);
	if ( (int)me->query_skill("unarmed", 1) < xianzhi){
		me->improve_skill("unarmed", me->query("int"));
		write("你在拼命打袋当中若有所悟，似乎对基本拳脚有点心得。\n");
		me->set_temp("stone_learned",1);
	}
	else
		{
	write("你拼命地打来打去，却感觉不到任何进展，可能是你经验不足或你已经不需要靠这东西来练功了。\n");
	}
	return 1;
}
