// /d/gumu/cool-bed.c

#include <ansi.h>

inherit ROOM;

void check_status(object ob);
void create()
{
	set("short","寒玉床");
	set("long", @LONG
这床是用上古寒玉制成，当年林朝英花了七年心血，到极北苦寒之地
，在数百丈坚冰之下挖出寒玉。据说在寒冰床上打坐练功，可以达到事半
功倍的效果。
LONG
);
	set("exits",([
		"west"      :__DIR__"zhengting",
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
	if( (int)me->query("qi") < qi_cost ){
		write("你现在的气太少了，无法产生内息运行全身经脉。\n");
		return 1;
	}
	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 ){
		write("你现在精神状况太差了，无法凝神专一！\n");
		return 1;
	}

	write(HIB"你盘膝而坐，顿觉寒流刺骨头，你丹田逆转，强运内力！！\n"NOR);
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
		if((int)me->query("max_neili") >= (int)me->max_neili()) {
			write("当你的内息遍布全身经脉时却没有功力提升的迹象，似乎内力修为已经遇到了瓶薄。\n");
			me->set_temp("pending/exercise",0);
		} else {
			write(HIW"你的内力增强了！\n"NOR);
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
			if(inv[i]->query_temp("pending/exercise")) continue;
			if(environment(inv[i]) != this_object()) continue;
			tell_object(inv[i],HIB"一阵寒流袭上心头，你只觉得全身的骨头阵阵刺痛！\n"NOR);
			inv[i]->receive_damage("jing",50);
			inv[i]->delete_temp("last_damage_from");
			inv[i]->set_temp("die_for","寒气袭骨，活活冻死在寒冰床上！");
		}
		remove_call_out("check_status");
		call_out("check_status",10);
	}
}
