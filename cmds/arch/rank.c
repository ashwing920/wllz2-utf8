// rank.c

#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
 
int main(object me, string arg)
{
	object ob;
	string obj,msg,color;
	
	if(!arg || arg == "") {
		write(sprintf("你现在的头衔是：%s\n", RANK_D->query_rank(me)));
		return 1;
	}

	if(sscanf(arg, "%s %s",obj,msg)==2) {
	ob = find_player(obj);
	if( !ob ) ob = find_living(obj);
	if( !ob ) ob = present(obj, environment(me));
	if( !ob ) return notify_fail("找不到这个人。\n");
		if( msg == "none") {
		ob->delete("rank_info/name");
		write(ob->name()+"的RANK已经被删除了。");
		write(sprintf("当前的头衔是：%s\n"NOR, RANK_D->query_rank(ob)));
		return 1;
		}
	}
	if(sscanf(arg, "%s %s %s",obj,color,msg)==3) {
	ob = find_player(obj);
	if( !ob ) ob = find_living(obj);
	if( !ob ) ob = present(obj, environment(me));
	if( !ob ) return notify_fail("找不到这个人。\n");

	ob->set("rank_info/name",convert_color(color)+"【"+ convert_color(msg) + convert_color(color)+"】"NOR);
	write(sprintf("你把%s的RANK设置为：%s\n"NOR,ob->name(), RANK_D->query_rank(ob)));
	tell_object(ob,me->name()+"将你的RANK设置为"+  RANK_D->query_rank(ob)+"\n");
	return 1;
	}
}

int help(object me)
{
	write(@HELP


指令格式：rank <某人> <方框色彩> <内容>

rank [new rank | none ]  大巫师可设置或删除自己的阶级和头衔。

HELP );
	return 1;
}

