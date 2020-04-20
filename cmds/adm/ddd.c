// port.c
// Created by robert@wllz

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string skill;

	if(sscanf(arg,"%s %s",arg,skill) == 2){
		NPC_D->add_set_skill(arg,skill);
	}

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
