// who1.c

inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string str)
{
	object *ob;
	int i,ppl;

	seteuid(getuid());
	ob = filter_array(children(USER_OB),(: userp :));
	str = "在线玩家错误列表\n";
	str += "─────────────────────────────────────\n";
	i = sizeof(ob);
	while( i--){
		if(!ob[i]->query_temp("error") || !environment(ob[i])) continue;
		str += ob[i]->name(1) + "("+ ob[i]->query("id")+")\n";
		ppl++;
	}
	str += "─────────────────────────────────────\n";
	str = sprintf("%s共有 %d 位使用者符合条件。\n", str,ppl);
	me->start_more(str);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：who1

玩家信息查询。
HELP
	);
	return 1;
}

