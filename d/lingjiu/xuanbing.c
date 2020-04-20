// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","玄冰室");
	set("long",@LONG
这是修练内功的地方。 屋子正中有一块千年玄冰(ice)，冰上冒出丝
丝寒气， 屋里因此寒气逼人，你不由得打了一个寒颤。
LONG
);
	set("exits", ([
		"east" : __DIR__"changl13",
	]));
	set("item_desc", ([
		"ice" : "这是一块采自天山之巅的千年玄冰，据说在那上面打坐事半功倍。\n",
	]));
	set("force_room",1);
	set("no_sleep_room",1);
	set("no_fight",1);
	set("no_steal",1);
	setup();
}
void init()
{
	object ob;
	if( interactive(ob = this_player())) {
		add_action("do_exe", "exercise");
		add_action("do_exe", "dazuo");
	}
	remove_call_out("check_status");
	call_out("check_status",10);
}
int do_exe (string arg)
{
	object me;
	int qi_cost, neili_gain;
	me=this_player();

	if( me->is_fighting()){
		write("战斗中不能练内功，会走火入魔。\n");
		return 1;
	}

	if( me->is_busy() ){
		write("你正忙着呢！\n");
		return 1;
	}
	if( !stringp(me->query_skill_mapped("force")) ) {
		write("你必须先用 enable 选择你要用的内功心法。\n");
		return 1;
	}
	if( me->query_temp("weapon")){
		write("你必须先放下兵器，才可以修炼内功心法。\n");
		return 1;
	}
	if( !arg ) qi_cost = 30;
	else if( !sscanf(arg, "%d", qi_cost) ) qi_cost = 30;

	if( qi_cost < 10 ){
		write("你最少要花 10 点「气」才能练功。\n");
		return 1;
	}
	if((int)me->query("qi") < qi_cost ){
		write("你现在的气太少了，无法产生内息运行全身经脉。\n");
		return 1;
	}
	if((int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 ){
		write("你现在精神状况太差了，无法凝神专一！\n");
		return 1;
	}
	write(HIC"你盘膝缓缓坐于玄冰之上，顿觉阵阵寒流刺骨。你强运内力，深深的吸了一口气。\n"NOR);
	me->set_temp("pending/exercise", 1);
	me->receive_damage("qi", qi_cost);
	me->start_busy(1);

	// This function ranged from 1 to 15 when qi_cost = 30
	if(present("jingang zhao", me))
		neili_gain = qi_cost * ((int)me->query_skill("force", 1)
		+ (int)me->query("con") ) / 30;                 // 练功加倍
	else
		neili_gain = qi_cost * ((int)me->query_skill("force", 1)
			+ (int)me->query("con") ) / 60;         // 原来是300

	if( neili_gain < 1 ) {
		write("但是当你行功完毕，只觉得全身酸麻。\n");
		me->set_temp("pending/exercise",0);
		return 1;
	}

	// 修改：效果随机
	me->add("neili", (random(2)+1)*(neili_gain + random( neili_gain / 4 + 1 )) );
	if( (int)me->query("neili") > (int)me->query("max_neili") * 2) {
		if( (int)me->query("max_neili") >= (int)me->max_neili()) {
			write("当你的内息遍布全身经脉时却没有功力提升的迹象，似乎内力修为已经遇到了瓶薄。\n");
			me->set_temp("pending/exercise",0);
		} else {
			write(HIW"你的内力有所提高了！\n"NOR);
			me->set_temp("pending/exercise",0);
			me->add("max_neili",3);
		}
		me->set("neili", me->query("max_neili"));
		me->set_temp("pending/exercise",0);
	}
	me->set_temp("pending/exercise",0);
	return 1;
}
void check_status(object ob)
{
	object *inv;
	int n,i;
	inv = all_inventory(this_object());
	n = sizeof(inv);
	if(inv){
		for(i=0;i<n;i++)
		{
			if(!inv[i]->is_character() || inv[i]->is_corpse()) continue;
			if(environment(inv[i]) != this_object()) continue;
			if(inv[i]->query_temp("pending/exercise")) continue;
			tell_object(inv[i],HIB"一阵寒流袭上心头，你只觉得全身的骨头阵阵刺痛！\n"NOR);
			inv[i]->receive_damage("jing",50);
			inv[i]->set_temp("die_for","寒气袭骨，冻死在玄冰室内！");
			inv[i]->delete_temp("last_damage_from");
		}
		remove_call_out("check_status");
		call_out("check_status",10);
	}
}
