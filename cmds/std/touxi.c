// touxi.c 偷袭

#include <ansi.h>

int main(object me, string arg)
{
	object obj,env;
	int count;

	env = environment(me);

	if( env->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

	if( env->query("fight_room") )
		return notify_fail("这里不能偷袭。\n");

	if(!arg || !objectp(obj = present(arg, env)))
		return notify_fail("你想偷袭谁？\n");

	if( !obj->is_character())
		return notify_fail("看清楚一点，那并不是生物。\n");

	if( obj->is_fighting(me))
		return notify_fail("你已经在战斗中了，还想偷袭？\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "都已经这样了，你还用得着偷袭吗？\n");

	if((int)obj->query("age") <= 18 && userp(obj))
		return notify_fail("为了世界更美好，放过小孩子吧！\n");

	if( userp(obj) && (int)me->query("age") <= 18)
		return notify_fail("唉！你不要命了吗？\n");

	if(obj->query("no_kill"))
		return notify_fail("你不能对这个人动手！\n");

	if(obj==me)
		return notify_fail("偷袭自己？别这么想不开。\n");

	if( me->is_busy())
		return notify_fail("你的动作还没有完成，不能偷袭。\n");

	tell_object(me, "你飞身纵起，扑向" + obj->name() +"！\n");
	tell_object(obj, CYN"\n" + me->name() + "忽然向你扑来！\n\n"NOR);
	message("vision", CYN"\n" + me->name() + "忽然向" + obj->name() +"扑去！\n\n"NOR, env, ({me, obj}) );

	switch (obj->accept_touxi(me))
	{
	case 0:
		return 0;
	case -1:
		return 1;
	}

	count = me->query_str();

	if( random((int)me->query("combat_exp")) < (int)obj->query("combat_exp")/2 ){
		me->add_temp("str", count*4);
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		me->add_temp("str", - count*4);
	}
	else
	{
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
	}
	if(userp(obj))
		write_file("/log/static/ATTEMP_TOUXI",sprintf("[%s]%s[%s]试图偷袭%s[%s]\n",
			ctime(time()),me->name(1),me->query("id"),obj->name(1),obj->query("id")));

	if(!me->is_busy()) me->start_busy(3);
	me->kill_ob(obj);
	obj->fight_ob(me);
	return 1;
}
int help(object me)
{
	write(@HELP

指令格式 : touxi <人物>

这个指令用来向敌人偷袭。偷袭不成时，则会招至反击。特别适合于经验
低的玩家向经验高的玩家拚命。:)

而在对玩家使用 touxi 指令的时候，有着一定的区别。不可以对小于16岁
的玩家使用 touxi 指令，小于16岁的玩家也不可以对其他玩家使用 touxi
指令。因为新玩家始终是受保护的！

其他相关指令: fight, kill, hit

HELP
	);
	return 1;
}
