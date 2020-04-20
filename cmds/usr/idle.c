// idle.c 发呆神功

#include <ansi.h>

inherit F_CLEAN_UP;

string *idle_msg = ({
	HIY"\n$N突然从人群中冲了出来，对$n大叫道：不好啦，不好啦～，你家着火啦～\n"NOR,
	HIM"\n$N缓缓的对$n说道：其实我真的不想说，其实我不想骗你，其实你爱人和我有一腿。\n"NOR,
	HIR"\n$N一脸惊惶的对$n说道：不好啦～～你前几天买的股票暴跌啦～～～\n"NOR,
	HIB"\n$N劈头散发，面目狰狞，托着一条长长舌头，轻轻的拍了拍$n的肩膀。\n"NOR,
	HIR"\n天空中突然传来一阵冷冷的阴笑声，霎时间乌云密布，一道"HIW"闪电"HIR"象利刃一般劈向$n！\n"NOR,
	HIW"\n$N突然冲到$n面前，从身后拿出一把 "HIY"50000T"HIW" 的大铁锤往$n头上敲去！\n"NOR,
});

int main(object me,string arg)
{
	int skill,obskill,time;
	object obj;
	string msg;

	skill = (int)me->query_skill("idle-force",1);

	if (me->ban_say(0)) return 0;

	if(!arg)
		return notify_fail("指令格式：idle <sb> \n");

	if(skill < 50)
		return notify_fail("你还是先把发呆神功练好了再说吧！\n");

	if(me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if(me->is_fighting())
		return notify_fail("战斗中不能施展发呆神功。\n");

	if(((int)me->query("potential") - (int)me->query("learned_points")) < skill / 3)
		return notify_fail("你的潜能不够发挥发呆神功。\n");

	if(environment(me)->query("fight_room")
	|| environment(me)->query("fighters_room")
	|| environment(me)->query("force_room")
	|| environment(me)->query("watch_fight_room"))
		return notify_fail("这里不能使用这种技能。\n");

	if( skill < 300){
		if(!objectp(obj = present(arg, environment(me))))
			return notify_fail("这里没有这个人。\n");
	}
	else{
		if (!obj) obj = find_player(arg);
		if (!obj || !interactive(obj) || !me->visible(obj))
			return notify_fail("这个人目前并不在游戏中。\n");
	}

	if(obj==me)
		return notify_fail("让自己发呆？不做任何动作就行了。\n");

	if(!wizardp(me) && wizardp(obj))
		return notify_fail("你不能对"+ obj->name() +"施展发呆神功。\n");

	if(obj->is_fighting())
		return notify_fail(obj->name()+"正在打架，你就别搅和了。\n");

	if((int)me->query("jing") < 100)
		return notify_fail("你的精神不好，无法施展发呆神功。\n");

	if((int)me->query("jingli") < 100)
		return notify_fail("你的精力不足，无法施展发呆神功。\n");

	if(obj->query_temp("idled"))
		return notify_fail("你无法再对"+ obj->name() +"施展发呆神功了。\n");

	message_vision("$N默不出声，突然做了一个莫名其妙的动作 . . 紧接着. . . \n",me);

	msg = idle_msg[random(sizeof(idle_msg))];

	obskill = (int)obj->query_skill("idle-force",1);

	message_vision(msg,me,obj);

	me->add("learned_points",skill / 3);
	me->receive_damage("jing",100);
	me->add("jingli",-100);

	if( random(me->query("combat_exp")) > obj->query("combat_exp") / 4
	&& random( skill) > obskill / 3 ){
		message_vision(HIW"\n$N只觉眼前一阵黑，顿时头晕目眩，漫天金星飞舞，扑闪的 . . .扑闪的. . . \n\n"NOR,obj);
		obj->set_temp("idled",1);
		call_out("remove_status",skill / 3,obj);
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",
			sprintf("%s施展发呆神功，%s不幸惨遭毒手。",me->name(),obj->name()));
	}
	else {
		message_vision(HIC"\n$n安然自若，处变不惊，显然$N的发呆神功一点用都没有！\n\n"NOR,me,obj);
		if(!wizardp(me)){
			call_out("remove_status",skill / 3,me);
			me->set_temp("idled",1);
		}
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",
			sprintf("%s对%s施展发呆神功失手了。",me->name(),obj->name()));
	}
	return 1;
}
void remove_status(object obj)
{
	if(!obj) return;
	obj->delete_temp("idled");
	message_vision("半晌，$N揉了揉疲惫的双眼，使劲的摇了摇头，终于从发呆中清醒了过来。\n",obj);
}
int help(object me)
{
	write(@HELP

指令格式 : idle <目标>

这个指令是让你施展发呆神功，让你的目标进入发呆状态。施展发呆神功
的命中率是和两者之间的经验、发呆神功等级有关。当发呆神功达到三百
级的时候，还可以远程让目标进入发呆状态。施展发呆神功时需要花费一
些精力和潜能。

HELP
	);
	return 1;
}
