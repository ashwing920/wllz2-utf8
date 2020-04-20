#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object env;
	env = environment(me);

	if(me->ban_say()) return 0;

	if(!wizardp(me) && me->query_condition("no_speak"))
		return notify_fail("你支支吾吾的，半天也说不出句话来。\n");

	if (!arg) {
		write("你自言自语不知道在说些什么。\n");
		message("sound", me->name() + "自言自语不知道在说些什么。\n",env,me);
		return 1;
	}
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	write(CYN"你说道：" + arg + "\n"NOR);
	message("sound", CYN + me->name() + "说道："+ arg + "\n" NOR,env,me);
	all_inventory(env)->relay_say(me, arg);
	return 1;
}
int help (object me)
{
	write(@HELP
指令格式: say <讯息>

说话，所有跟你在同一个房间的人都会听到你说的话。

注: 本指令可用 ' 取代.

HELP
	);
	return 1;
}
