// who1.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
	object where, ob, *ob_list;
	int i;

	seteuid(getuid());

	ob_list = filter_array(children(USER_OB),(: userp :));
	ob_list = sort_array(users(), "sort_user", this_object());
	str = HIG"线上玩家      精         气           神        内力           经验值    潜能\n"NOR;
	str += "─────────────────────────────────────────\n";
	for(i=0; i<sizeof(ob_list); i++)
	{
	ob = ob_list[i];
	where = environment(ob);
	str += sprintf(WHT"%-12s　",ob->name(1));
	str += sprintf(HIR"%-4d/%-4d　",(int)ob->query("jing"),(int)ob->query("max_jing"));
	str += sprintf(HIY"%-5d/%-5d　",(int)ob->query("qi"),(int)ob->query("max_qi"));
	str += sprintf(HIG"%-8d　",(int)ob->query("shen"));
	str += sprintf(HIB"%-6d/%-6d　",(int)ob->query("neili"),(int)ob->query("max_neili"));
	str += sprintf(HIM"%-8d　",(int)ob->query("combat_exp"));
	str += sprintf(HIC"%-6d\n"NOR, (int)ob->query("potential")-(int)ob->query("learned_points"));
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

	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");

}
int help(object me)
{
	write(@HELP
指令格式：who1

玩家信息查询。
HELP
	);
	return 1;
}

