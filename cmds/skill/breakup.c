// time.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;
	
	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");
	
	if(!environment(me)->query("biguan_room"))
		return notify_fail("这里不适合闭关修炼。\n");
	
	if((int)me->query("combat_exp") < 3000000)
		return notify_fail("你的武学修为不足，冲破任督二脉为时甚早。\n");
		
	if((int)me->query_skill("force",1) < 300)
		return notify_fail("你的内功修为不足，恐怕难以冲破自身的任都二脉。\n");
	
	if(!(string)me->query_skill_mapped("force"))
		return notify_fail("你的内功还没有激发，怎么能够冲破任督二脉？\n");

	if((int)me->query("jing") < (int)me->query("max_jing")
	|| (int)me->query("qi") < (int)me->query("max_qi")
	|| (int)me->query("neili") < (int)me->query("max_neili")
	|| (int)me->query("food") < me->max_food_capacity()
	|| (int)me->query("water") < me->max_water_capacity())
		return notify_fail("你现在状态不好，不适合闭关修炼。\n");
	
	if(((int)me->query("potential") - (int)me->query("learned_points")) < 20000)
		return notify_fail("你的潜能太少了，现在闭关修炼也是徒劳的。\n");

	if((int)me->query("breakup"))
		return notify_fail("你的任督二脉已经打通，再闭关沉思也毫无进展。\n");

	message_vision("$N深深的吸了一口气，双拳紧握，盘膝坐下，渐渐的陷入一阵沉思当中。\n",me);
	if(objectp(link_ob = me->query_temp("link_ob"))){
		link_ob->save();
		destruct(link_ob);
	}
	me->set("breakuproom", base_name(environment(me)));
	me->set("biguan",1);
	me->set_temp("breakup",1);
	if(me->query("env/idle")) me->delete("env/idle");
	remove_interactive(me);
	return 1;
}

int help(object me)
{
     write(@HELP

指令格式：breakup

这个指令是让你进入闭关修炼状态，你可以通过闭关来打破自己的任督二
脉，冲破自身的内力、精力界限，让你的精神、气血有进一步的提高。

HELP
);
	return 1;
}
