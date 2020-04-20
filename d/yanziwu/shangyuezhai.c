
inherit ROOM;

void create()
{
	set("short","赏月斋");
	set("long",@LONG
赏月斋是为慕容家每到中秋之夜而建造的。里面富丽堂皇，瓜果应有
尽有，旁边有丫鬟伺候着，每到赏月之时，一家老小都在这里赏月，在赏
月的同时，也念念不忘复兴大燕的使命。西面是内堂，东面和南面是一条
长廊。
LONG);
	set("exits",([
		"west" : __DIR__"neitang",
		"east" : __DIR__"c15-2",
		"south" : __DIR__"c15-5",
	]));
	setup();
}

void init()
{
	add_action("do_wudao", "wudao");  
}
int do_wudao(string arg)
{
	int skill;
	object me=this_player();
	object weapon = me->query_temp("weapon");

	if(!weapon || weapon->query("skill_type") != "blade" )
		return notify_fail("你手中无刀，怎么练？\n");

	skill = (int)me->query_skill("blade", 1);
	if(skill >100 )
		return notify_fail("你已经竭尽全力去体会基本刀法的精要，但是无法再增长你的基本刀法了！\n");
	if((skill * skill * skill / 10) > me->query("combat_exp"))
		return notify_fail("可能是你经验不足，就算你怎么挥舞，也无法领会刀法的奥妙。\n");

	me->receive_damage("jing", random(40));
	write("你挥舞着一柄刀，渐渐地你悟出了一些有关基本刀法的精要之所在。\n");
	me->improve_skill("blade", me->query("int"));	
	return 1;
}				 
