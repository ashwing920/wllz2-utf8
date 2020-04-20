// time.c

#include <localtime.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *t;
	t = localtime( time() );
	write("现在是公历" +  chinese_number(t[LT_MON] + 1) + "月" + chinese_number(t[LT_MDAY])
		+ "日" + chinese_number(t[LT_HOUR]) + "时" + chinese_number(t[LT_MIN])
		+ "分" + chinese_number(t[LT_SEC]) + "秒（"+ NATURE_D->ture_time(time()) + "）。\n");
	write("游戏时间为：" + NATURE_D->game_time() + "。\n");
	if(wizardp(me))
	write(sprintf("系统时间戳：%d\n",time()));
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式：time          显示现在的时辰

HELP
	);

	return 1;
}
