// halt.c

#include <ansi.h>

int main(object me, string arg)
{
	string force;
	mapping msg;
	object ob;

	if( arg && wizardp(me) ) {
		ob = present(arg, environment(me));
		if( !ob ) return notify_fail("没有这个生物。\n");
		if( !ob->is_fighting() ) return notify_fail(ob->name()+"现在不忙。\n");
		ob->remove_all_killer();
		message_vision("\n$N用巫师的神力停止了$n的战斗。\n", me, ob);
		return 1;
	}
	if((int)me->query_temp("suicide_countdown")){
		if((int)me->query_temp("to_suicide") > 3)
			return notify_fail("你把生死当作了儿戏，何必呢？永别吧。:( \n");
		else
			write(HIY"\n你回头看看泥潭，过去的风风雨雨犹如电影片段在你眼前泛起。喜、怒、哀、乐 . . . \n你心一软，眼圈一红，终于打消了自杀的念头。\n\n"NOR);
			me->delete_temp("suicide_countdown");
			me->start_busy(0);
			me->interrupt_me();
			CHANNEL_D->do_channel(this_object(),"rumor",sprintf("%s[%s]终于想清楚，放弃自杀了！！",me->name(1),me->query("id")));
		return 1;
	}
	if(!me->is_busy() && me->is_fighting()){

		if(environment(me)->query("fight_room")
		|| environment(me)->query("no_halt"))
			return notify_fail("挑战中点到即止，无需终止战斗的。\n");

		if(objectp(ob = me->query_temp("last_opponent"))
		&& me->is_fighting(ob) && ob->is_fighting(me)
		&& (member_array(ob->query("id"),me->query_killer()) != -1
		|| member_array(me->query("id"),ob->query_killer()) != -1))
			return notify_fail("仇杀中你死我活，不死不休，怎能停止战斗呢？\n");

		me->remove_all_enemy();
		message_vision("\n$N身行向后一跃，跳出战圈不打了。\n", me);
	}
	else if(!me->is_busy())
		return notify_fail("你现在不忙。\n");
	else if((int)me->query_temp("pending/exercise")) {
		force = (string)me->query_skill_mapped("force");
		if(force)msg = SKILL_D(force)->exercise_msg(me);
			if (!msg || undefinedp(msg["halt_msg"])){
				message_vision("$N把正在运行的真气强行压回丹田，站了起来。\n", me);
			}
			else{
				message_vision(msg["halt_msg"], me);
			}
		me->interrupt_me();
	}
	else if ((int)me->query_temp("pending/respirate")){
		message_vision("$N猛吸几口大气，站了起来。\n", me);
		me->interrupt_me();
	}
	if(me->is_busy()) write("你现在很忙，停不下来。\n");
	return 1;
}

int help(object me)
{
	write(@TEXT

指令格式 : halt

中止你目前正在做的事情，比如打坐、吐纳或者是某些工作。如果你和别
人正在动手，则这条命令会让你停手，当然前提是对方并不想杀死你，否
则使用这条命令没有效果。

TEXT);
	return 1;
}