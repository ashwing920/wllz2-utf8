// toptenadd.c
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
int main(object me, string arg)
{
	string str;

	seteuid(geteuid(me));
	if (!arg||arg=="")
		return help(me);
	str=TOPTEN_D->topten_query(arg);
	write(str+"\n");
	return 1;
}

int help(object me)
{
	write("指令格式 : topten <类型> \n\n"NOR+TOPTEN_D->query_type()+NOR);
	return 1;
}
