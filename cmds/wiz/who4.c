// who1.c

inherit F_CLEAN_UP;
#include <ansi.h>
#include <combat.h>
int main(object me, string str)
{
	object where, ob, *ob_list,weapon;
	int i;
	int attack_points, dodge_points, parry_points;
	string skill_type;
	seteuid(getuid());

	ob_list = filter_array(children(USER_OB),(: userp :));
	ob_list = sort_array(users(), "sort_user", this_object());

	str = HIG"线上玩家        战斗力          防御力         伤害力   保护力  经验值   \n"NOR;
	str += "─────────────────────────────────────────\n";
	for(i=0; i<sizeof(ob_list); i++)
	{
	ob = ob_list[i];
	where = environment(ob);
		if( objectp(weapon = ob->query_temp("weapon")))
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";
	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
	parry_points = weapon? parry_points: (parry_points/10);

	str += sprintf(WHT"%-14s　",ob->name(1));
	str += sprintf(HIR"%-14d　",attack_points + 1, );
	str += sprintf(HIY"%-14d　",(dodge_points>parry_points?dodge_points:parry_points) + 1);
	str += sprintf(HIG"%-6d　",(int)ob->query_temp("apply/damage"));
	str += sprintf(HIB"%-6d　",(int)ob->query_temp("apply/armor"));
	str += sprintf(HIM"%-12d", (int)ob->query("combat_exp")) + "\n"NOR;
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

