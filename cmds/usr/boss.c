// TIE@FY3

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;
	write(CLR);
	if(arg){
		msg = read_file("/doc/story/news");
		write(msg);
	}
	me->set_temp("block_msg/all",1);
	return 1;
}

int help(object me)
{
	 write(@HELP
指令格式: boss <arg>

这个指令让你(玩家)在老板出现前一秒钟时将屏幕上所有的中文消除，如
果 <arg> 不是零的话，系统会在你的屏幕上显示出一些文章。与此同时，
你将受不到任何来自游戏的讯息，直到你输入bossgone指令。

有关指令：bossgone
HELP
	);
	return 1;
}
