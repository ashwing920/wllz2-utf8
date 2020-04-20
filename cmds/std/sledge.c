// port.c
// Created by robert@wllz

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int time,i;
	object obj,bingqi;
	mapping weapon;
	mapping msg;
	string name;
	int t = time();
	
	if(me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if(!arg || sscanf(arg,"%s %d",arg,time) != 2)
		return notify_fail("指令格式：steelify 武器 <次数> \n");
	
	if( environment(me)->query("chat_room")
	 || environment(me)->query("fight_room")
	 || environment(me)->query("no_fight")
	 || environment(me)->query("no_sleep_room")
	 || environment(me)->query("force_room"))
		return notify_fail("这个地方不能炼造武器！\n");

	if( t == me->query_temp("time/sledge"))
		return notify_fail("你刚进行炼造，还是休息一下再说吧。\n");

	if( time < 0 || time > 10)
		return notify_fail("炼造次数最多为 10 次，最少为 1 次。\n");

	if(!objectp(obj = present(arg,me)))
		return notify_fail("你要炼造什么东西？\n");
	
	if(!obj->query("ownermake"))
		return notify_fail("你只能炼造自造的武器。\n");

	name = clean_color(obj->name()) +NOR;

	if(obj->query("weapon_master")!= geteuid(me))
		return notify_fail(name +"又不是你的，你炼来做什么？\n");
	
	if(!mapp(weapon = me->query("weapon")))
		return notify_fail("你没有自造兵器，先去造一柄适手的兵器吧。\n");
	
	me->set_temp("time/sledge",t);

	if(mapp(msg = obj->query_sledge_msg(obj)))
		write(msg["start"]);
	else 
		write("你开始冶炼"+ clean_color(obj->name())+"。\n"NOR);

	for(i=0;i<time;i++){
		if((int)me->query("neili") < 100 || (int)me->query("max_neili") < 10 ){
			write("你的内力不足以锻炼"+ name +"。\n");
			break;
		}
		if((int)me->query("jing") < 50 || (int)me->query("qi") < 50 ){
			write("你的状态不好，还是休息一下再说吧。\n");
			break;
		}
		if(((int)me->query("potential") - (int)me->query("learned_points")) < 2){
			write("你的潜能不足以炼造那么多次。\n");
			break;
		}
		me->add("max_neili",-10);
		me->add("neili",-100);
		me->add("learned_points",2);
		me->receive_damage("qi",50);
		me->receive_damage("jing",30);
		weapon["value"] += 1;

		if( weapon["value"] >= ( (weapon["lv"] +1) * (weapon["lv"] +1))){
			weapon["lv"] += 1;
			if(msg["update"])
				write(msg["update"]);
			else 
				write("经过冶炼，你的"+ obj->name()+"等级有所提高了。\n");
			bingqi = new(base_name(obj));
			bingqi->move(me,1);
			write("你的"+ name +"等级提高了。\n");
			weapon["value"] = 0;
			me->save();
			destruct(obj);
			break;
		}
	}
		
	return 1;
}

int help(object me)
{
	write(@HELP

指令格式：port

这个指令是让你了解目前游戏中各端口的使用程度。为了给您提供一个流
畅的网络环境，建议选择使用率较低的端口连线。

HELP
	);
	return 1;
}
