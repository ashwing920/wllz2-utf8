// to.c
#include <ansi.h>

int main(object me, string arg)
{
	me->edit( (: call_other, this_object(), ({ "do_to", me, arg }) :) );
	return 1;
}

void do_to(object me, string arg, string str)
{
	seteuid(getuid());
	if(arg) me->force_me(arg + " " + str);
	else me->force_me(str);
}

int help(object me)
{
write(@TEXT

指令格式 : to <指令>

可以一次输出多行以上的文字, <指令>通常是输出讯息的指令如
say , tell , describe , chat , reple ........等。

范例 : 
to say

结束离开用 '.'，取消输入用 '~q'，使用内建列编辑器用 '~e'。
—————————————————————————————
武林列传之南海站
169IP：172.19.133.188 2000
163IP：202.104.16.44 2000
支持大五码和国标码。


输出到萤幕上的结果则是 :

你说道：武林列传之南海站
169IP：172.19.133.188 2000
163IP：202.104.16.44 2000
支持大五码和国标码。

TEXT
);
	return 1;
}
