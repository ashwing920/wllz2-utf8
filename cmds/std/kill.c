// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj,env;
	string callname;
	string family1,family2;

	env = environment(me);

	if(!arg)
		return notify_fail("你想杀谁？\n");

	if((env->query("no_fight") ||  env->query("restrict_action"))
	&& (string)me->query("type") != "killer" )
		return notify_fail("这里不准战斗。\n");

	if(!objectp(obj = present(arg, env)))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj==me)
		return notify_fail("用 suicide 指令会比较快:P。\n");

	if(obj->query_temp("sleeping"))
		return notify_fail("趁人家睡觉的时候下手，你怎么那么卑鄙啊？\n");

	if( userp(obj) && (int)obj->query("age") <= 18 
		&& !env->query("fight_room") && !env->query("pk_room"))
			return notify_fail("唉！你什么时候才可以改掉以强凌弱的恶习？\n");

	if( userp(obj) && (int)me->query("age") <= 18 
		&& !env->query("fight_room") && !env->query("pk_room"))
			return notify_fail("唉！你不要命了吗？\n");

	if (arrayp(me->query_team()) &&
	member_array(obj, me->query_team()) != -1)
		return notify_fail("连你自己队伍中的人也要杀吗？\n");

	if(obj->is_fighting(me) && me->is_fighting(obj))
		return notify_fail("你正在和"+ obj->name()+"生死相搏呢！\n");

	if(env->query("fight_room")){
		family1 = (string)me->query("family/family_name");
		family2 = (string)obj->query("family/family_name");
		if( !family1 ) family1 = "无门无派";
		if( !family2 ) family2 = "无门无派";
		other_message(HIY,"紫禁之颠",NATURE_D->game_time()+"，"+ family1 +"的"+ me->name()+"大战"+ family2 +"的"+ obj->name() + "！");
		me->add("fight_times",1);
		obj->add("fight_times",1);
	}

	callname = RANK_D->query_rude(obj);
	if (obj->query("can_speak"))
	{
		if (random(3) > 1) 
			message_vision("\n$N对著$n喝道：「" + 
				callname + "！今日不是你死就是我活！」\n\n", me, obj);
		else
			message_vision("\n$N对著$n喝道：「" + 
				callname + "！明年今日就是你的忌日！」\n\n", me, obj);
	}
/*
	switch(obj->accept_kill(me))
	{
	case 0:
		return (! objectp(obj));
	case -1:
		return 1;
	default:
	}
*/
	if(obj->accept_kill(me) == -1) return -1;
	
	me->kill_ob(obj);

	if(living(obj) && !userp(obj))
		obj->kill_ob(me);
	else
		obj->fight_ob(me);

	if(userp(obj))
		tell_object(obj, HIR "如果你要和" + me->name() + "[" + me->query("id")+"]性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);
	
	if(!env->query("fight_room") && userp(me) && userp(obj))
		write_file("/log/static/ATTEMP_KILL",sprintf("[%s]%s[%s]试图杀死%s[%s]\n",
		ctime(time()),me->name(1),me->query("id"),obj->name(1),obj->query("id")));

	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : kill <人物>

这个指令让你主动开始攻击一个人物，并且试图杀死对方，kill 和 fight 最大的
不同在於双方将会真刀实枪地打斗，也就是说，会真的受伤。由於 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对於一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。

而在对玩家使用 kill 指令的时候，有着一定的区别。不可以对小于18岁的玩家使
用 kill 指令，小于18岁的玩家也不可以对其他玩家使用 kill 指令。因为新玩家
始终是受保护的！

其他相关指令: hit, fight

有关 fight 跟 kill 的区分请看 'help combat'.
HELP
	);
	return 1;
}
