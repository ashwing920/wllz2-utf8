// time.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object link_ob;
	string skill,*c_skill;
	int i;
	
	c_skill = me->query("close_skill");

	if(!arg) return help(me);
	if(sscanf(arg,"add %s",skill) == 1){
		if(!me->query_skill(skill,1))
			return notify_fail("你对这门武功路数毫无认识，无法自行修炼。\n");

		if(me->query_skill(skill,1) < 400)
			return notify_fail("你的"+ to_chinese(skill)+"火候不足，不能进行闭关自炼。\n");

		if(pointerp(c_skill) && sizeof(c_skill) > 4)
			return notify_fail("你定制的练功计划已经有五项武功了。\n");

		if( !SKILL_D(skill)->valid_learn(me) ) return 0;

		if(!pointerp(c_skill))
			me->set("close_skill",({ skill }));
		else if( member_array(skill,c_skill)== -1)
		me->set("close_skill",c_skill + ({ skill }));
		write("你将「"+ to_chinese(skill) +"」列入闭关修炼计划。\n");
		return 1;
	}
	if(sscanf(arg,"del %s",skill) == 1){
		if(!me->query_skill(skill,1))
			return notify_fail("你对这门武功路数毫无认识，更别说自行修炼了。\n");
		
		if(member_array(skill,c_skill) == -1)
			return notify_fail("你的闭关计划中并没有这门武功。\n");
		if(pointerp(c_skill) && sizeof(c_skill) > 1)
			me->set("close_skill",c_skill -= ({ skill }));
		else
			me->delete("close_skill");
		
		write("你将「"+ to_chinese(skill) +"」从闭关修炼计划中移除。\n");
		return 1;
	}
	if(arg == "check"){
		if(!pointerp(c_skill) || !sizeof(c_skill))
			return notify_fail("你并没有定制闭关修炼计划。\n");
		write("你定制的闭关修炼计划中有：");
		for(i=0;i<sizeof(c_skill);i++){
				write(to_chinese(c_skill[i]) +"，");
		}
		write("共"+ chinese_number(sizeof(c_skill)) +"项武功。\n");
		return 1;
	}
	if(arg == "finish"){
		if(!pointerp(c_skill) || !sizeof(c_skill))
			return notify_fail("你还没有定制闭关修炼计划。\n");

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	
	if(!environment(me)->query("biguan_room"))
		return notify_fail("这里不适合闭关修炼。\n");
	
	if((int)me->query("combat_exp") < 6000000)
		return notify_fail("你的武学修为不足，无法闭关修炼武功。\n");

	if((int)me->query("jing") < (int)me->query("max_jing")
	|| (int)me->query("qi") < (int)me->query("max_qi")
	|| (int)me->query("neili") < (int)me->query("max_neili")
	|| (int)me->query("food") < me->max_food_capacity()
	|| (int)me->query("water") < me->max_water_capacity())
		return notify_fail("你现在状态不好，不适合闭关修炼。\n");

	if(((int)me->query("potential") - (int)me->query("learned_points")) < 20000)
		return notify_fail("你的潜能太少了，现在闭关修炼也是徒劳的。\n");

		message_vision("$N深深的吸了一口气，双拳紧握，盘膝坐了下来，渐渐的陷入一阵沉思当中。\n",me);
		if(objectp(link_ob = me->query_temp("link_ob"))){
			link_ob->save();
			destruct(link_ob);
		}
		me->set_temp("biguan",1);
		me->set_temp("closed",1);
		if(me->query("env/idle")) me->delete("env/idle");
		remove_interactive(me);
		return 1;
	}
}

int help(object me)
{
     write(@HELP

这个指令是让你进入闭关修炼状态，让你可以在闭关中研究你预订计划的
武功。

指令格式：

closed add <武功>		将学会的武功加入到修炼计划。
closed delete <武功>		将计划中的武功删除。
closed check			查询已经列入计划的武功。
closed finish			计划完成，开始闭关修炼。

HELP
);
	return 1;
}
