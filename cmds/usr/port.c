// port.c
// Created by robert@wllz

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *ob;
	string str;
	int i,I1,I2,I3,I4,I5;
	
	if(!wizardp(me)){
		if((int)me->query("jing") < (int)me->query("eff_jing") / 10)
			return notify_fail("你的精神不好。\n");
		me->receive_damage("jing",(int)me->query("eff_jing")/ 10);
	}

	ob = filter_array(children(USER_OB),(: userp :));
	str = "以下为本游戏各端口使用情况：\n";
	str += WHT"───────────────────────────────────\n"NOR;
	for(i=0;i<sizeof(ob);i++){
		if(!environment(ob[i])) continue;
		if(query_ip_port(ob[i]) == 2000) I1++;
		if(query_ip_port(ob[i]) == 2001) I2++;
		if(query_ip_port(ob[i]) == 2002) I3++;
		if(query_ip_port(ob[i]) == 2003) I4++;
		if(query_ip_port(ob[i]) == 2004) I5++;
	}
	str += sprintf("2000：%d人│2001：%d人│2002：%d人│2003：%d人│2004：%d人│\n",I1,I2,I3,I4,I5);
	str += WHT"───────────────────────────────────\n"NOR;
	str += "为了给您提供一个流畅的网络环境，建议选择使用率较低的端口连线。";
	me->start_more(str);
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
