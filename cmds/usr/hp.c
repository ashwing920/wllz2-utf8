// hp cmds

#include <ansi.h>
inherit F_CLEAN_UP;
string status_color(int current, int max);
int main(object me, string arg)
{
	object ob;
	string msg;
	mapping my;

	seteuid(getuid(me));

	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的状态？\n");
		if(wizardp(ob) && !wizardp(me))
			return notify_fail("你要察看谁的状态？\n");
	}
	else if( ob!= me ) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的状态？\n");
		if(wizardp(ob) && !wizardp(me))
			return notify_fail("你要察看谁的状态？\n");
		if( me->query("marry") != ob->query("id")
		&& ob->query("father_id") != me->query("id")
		&& ob->query("mather_id") != me->query("id"))
			return notify_fail("只有巫师能察看别人的状态。\n");

	} else
		return notify_fail("只有巫师能察看别人的状态。\n");

	my = ob->query_entire_dbase();
	msg = sprintf(HIR"  %s\n"NOR,ob->name(2));
	msg += sprintf(HIC"≡"HIY"───────────────────────────────"HIC"≡\n"NOR);
	msg += sprintf(HIR"【 精 气 】：%s%5d／%5d %s[%3d%%]" HIC "    【 精 力 】：%s%5d／%5d [+%d]\n" NOR,
		status_color(my["jing"], my["eff_jing"]), my["jing"], my["eff_jing"],
		status_color(my["eff_jing"], my["max_jing"]),   my["eff_jing"] * 100 / my["max_jing"],
		status_color(my["jingli"], my["max_jingli"]),   my["jingli"], my["max_jingli"],
		my["jiajing"] );
	msg += sprintf(HIR"【 气 血 】：%s%5d／%5d %s[%3d%%]" HIC "    【 内 力 】：%s%5d／%5d [+%d]\n" NOR,
		status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
		status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"],
		status_color(my["neili"], my["max_neili"]), my["neili"], my["max_neili"],
		my["jiali"] );
	msg += sprintf(HIW"【 食 物 】：%s%5d／%5d      " HIY "     【 潜 能 】：%5d \n" NOR,
		status_color(my["food"], ob->max_food_capacity()),my["food"], ob->max_food_capacity(),
		my["potential"] - my["learned_points"]);
	msg += sprintf(HIW"【 饮 水 】：%s%5d／%5d      " HIY "     【 经 验 】：%5d\n" NOR,
		status_color(my["water"], ob->max_water_capacity()),
		my["water"],ob->max_water_capacity(),my["combat_exp"] );
	msg += HIC"≡"HIY"───────────────────────────────"HIC"≡\n"NOR;
	tell_object(me,msg);
	return 1;
}

string status_color(int current, int max)
{
	int percent;

	if( max>0 ) percent = current * 100 / max;
	else percent = 100;
	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}

int potential_lv(int exp)
{
	int grade;
	grade = 100 + exp / 500;
	return grade;
}
int help(object me)
{
	write(@HELP
指令格式 : hp
	   hp <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。

see also : score
HELP
    );
    return 1;
}


