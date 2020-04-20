// uptime.c
// Design By Robert 蝴蝶君 email:robert_st@sina.com

#include <ansi.h>

inherit F_CLEAN_UP;

int main()
{
	mixed *t;
	t = EVENT_D->query_event_list("/event/reboot");

	if(t[2] > 30){ 
		t[2] -= 30;
		t[1]+=1;
	}

	write(sprintf("%s已经执行了%s。\n",code_name(),CHINESE_D->chinese_time(uptime())));
	write(sprintf("下次重新启动时间为："WHT" %d"NOR"年"WHT" %d"NOR"月"WHT" %d"NOR"日"WHT" 上午 %d"NOR"时正。\n",t[0],t[1],t[2],t[3]));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : uptime

这个指令告诉您本游戏已经连续执行了多长时间和下次重新启动的时间。

HELP
	);
	return 1;
}
