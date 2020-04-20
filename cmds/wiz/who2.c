// who2.c

inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string str)
{
	object where, ob, *ob_list;
	int i;
	seteuid(getuid());

	ob_list = filter_array(children(USER_OB),(: userp :));
	ob_list = sort_array(users(), "sort_user", this_object());
	str = HIG"玩家      年龄  存款        IP地址          所在地点      所在程序\n"NOR;
	str += "─────────────────────────────────────────\n";
	for(i=0; i<sizeof(ob_list); i++)
	{
	ob = ob_list[i];
	where = environment(ob);
	if( wizardp(ob) && ob->query("env/invisibility") > 20) continue;
	str += sprintf(WHT"%-8s　",ob->name(1));
	str += sprintf(HIR"%-3d　", ob->query("age"));
	str += sprintf(HIG"%-10d　", ob->query("balance"));
	str += sprintf(HIY"%-15s　", query_ip_number(ob));
	if (where) str += sprintf(HIM"%-14s ", where->query("short"));
	if (!where) str += sprintf("\n"NOR);
	   else str += sprintf(HIC"%s\n"NOR, file_name(where));
	}
	str += "─────────────────────────────────────────\n";
	str = sprintf("%s共有 %d 位使用者连线中。\n", str, sizeof(ob_list));
	me->start_more(str);
	return 1;
}
int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2)
			- (int)SECURITY_D->get_wiz_level(ob1);

	return (int)ob2->query("balance") - (int)ob1->query("balance");
}
int help(object me)
{
	write(@HELP
指令格式：who2

玩家信息查询。
HELP
	);
	return 1;
}

