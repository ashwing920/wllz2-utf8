// news.c

#include <ansi.h>

int main(object me, string arg)
{
	object newob;

	newob = find_object("/clone/board/news_b");
	if(!newob) newob = load_object("/clone/board/news_b");
	newob->do_news(arg);
	return 1;
}
int help(object me)
{
write(@TEXT

这个指令是让你查阅本游戏的最新更新消息。

指令格式：news <all>  查阅所有更新消息
	  news <next> 查阅当前更新消息读取状态。
　　　　　news <num>  读取单独一条消息。
TEXT
);
	return 1;
}
