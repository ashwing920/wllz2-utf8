// alias.c

inherit F_CLEAN_UP;

#include <ansi.h>;

int main(object me, string arg)
{
	int i;
	mapping alias;
	string verb, replace,*vrbs,*no_alias;
	no_alias = ({"exert","perform","exercise","enforce","alias","enable",
	"respirate","abandon","apprentice","learn","prepare","research","study","yong","yun","tuna","dazuo","xue","du"
	"lian","yanjiu","fangqi","jifa","bai","bei","cha","jiali","enforce","get","give","run",});
	if( !arg ) {
		alias = me->query_all_alias();
		if( !sizeof(alias) ) {
			write("你目前并没有设定任何 alias。\n");
			return 1;
		} else  {
			write("你目前设定的 alias 有：\n");
			vrbs = keys(alias);
			for(i=0; i<sizeof(vrbs); i++)
				write(sprintf("%-15s = %s\n", vrbs[i], alias[vrbs[i]]));
			return 1;
		}
	}

	if( sscanf(arg, "%s %s", verb, replace)!=2 )
	{
		me->set_alias(arg, 0);
		write("你取消了 "HIR+arg+NOR" 这个替代命令。\n");
	}
	else if( member_array(verb,no_alias) != -1)
		return notify_fail("为了防止你的指令出错，系统不允许你将 "HIG + verb + NOR" 指令设定成为 alias 。\n");
	else if( verb=="" )
		return notify_fail("你要设什么 alias？\n");
	else
	{
		me->set_alias(verb, replace);
		write("今后你用 "HIR+verb+NOR" 来替代 "HIG+replace+NOR" 命令。\n");
	}
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : alias <欲设定之指令> <系统提供之指令>

有时系统所提供之指令需要输入很长的字串, 在使用时(尤其是经常用到的)
或许会感觉不方便, 此时你(你)即可用此一指令设定并替代原有之指令。

范例:
	'alias sc score' 会以 sc 取代 score 指令。
	'alias' 后不加参数则列出你所有的替代指令。
	'alias sc' 会消除 sc 这个替代指令。 (如果你有设的话)

其中可以用 $1, $2, $3 .... 来取代第一、第二、第三个参数，或是 $* 取代
所有的参数，如：
	'alias pb put $1 in $2'

则每当你(你)打：
	pb bandage bag

就会取代成：
	put bandage in bag

HELP
);
	return 1;
}
