// jingzuo.c

void wakeup(object me, object where);

int main(object me, string arg)
{
	object where;
	int lvl,busy_time;
	
	where = environment(me);
	lvl = (int)me->query_skill("linji-zhuang",1);

	seteuid(getuid());

	if( where->query("restrict_action"))
		return notify_fail("这里不能做这件事情。\n");        

	if( me->query("family/family_name") != "峨嵋派" )
		return notify_fail("只有峨嵋派弟子才能通过静坐修行！\n");

	if( where->query("no_sleep_room"))
		return notify_fail("这里太纷杂，你没法静心静坐。\n");

	if( !where->query("sleep_room"))
		return notify_fail("这里太纷杂，你没法静心静坐。\n");

	if( me->query("eff_jing")<50)
		return notify_fail("你受伤太重，没法静坐。\n");

	if((int)me->query("jing") < lvl / 5)
		return notify_fail("你的精力不足，无法进行静坐。\n");

	if( me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if( me->is_fighting())
		return notify_fail("战斗中想静坐？你不要命啦！\n");
	
	if((int)me->query_skill("mahayana",1) < 60)
		return notify_fail("你的大乘般涅磐功还太浅薄了，没法静心静坐。\n");

	if((int)me->query_skill("linji-zhuang",1) < 60)
		return notify_fail("你的临济十二庄功还太浅薄了，没法静心静坐。\n");

	if((int)me->query_temp("is_jingzuo"))
		return notify_fail("你已经在静坐中了。\n");

	if( where->query("sleep_room")){
		write("你往床上盘膝一坐，开始静坐，不一会儿，你神游天外，物我两忘。\n");
		me->set_temp("block_msg/all",1);
		message_vision("$N一躬身，坐在床上，闭目端念，静心打坐。\n",me);
		me->set_temp("is_jingzuo",1);
		me->disable_player("<静坐中>");
		busy_time = (lvl / 10) + random(30);
		me->start_busy(busy_time);
		call_out("wakeup",busy_time,me,where);
		return 1;
	} else return notify_fail("这里太纷杂，你没法静心静坐。\n");
}

void wakeup(object me,object where)
{
	int lvl,exp,pot,intpot;

	me->start_busy(1);
	lvl = (int)me->query_skill("linji-zhuang",1);
	intpot = (int)me->query_int()/2;
	pot = intpot + (lvl / 10);
	exp = pot / 2 + random(20);
	me->receive_damage("jing",lvl / 5);
	me->receive_would("jing",lvl / 10);
	me->add("potential",pot);
	me->add("combat_exp",exp);
	me->delete_temp("block_msg/all");
	me->delete_temp("is_jingzuo");
	message_vision("$N静坐完毕，缓缓睁眼，长长吐了一口气。\n",me);
	me->enable_player();
	me->set("jingzuo_time",(int)me->query("mud_age"));
	write("你静坐完毕，好累的感觉。\n");
	return;
}

int help(object me)
{
	write(@HELP
指令格式 : jingzuo <精点数>

这个指令是峨嵋派弟子用以静坐修道的命令，但必须在休息室里才能够使用。

HELP
	);
	return 1;
}
