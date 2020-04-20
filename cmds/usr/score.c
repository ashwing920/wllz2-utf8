// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);

int main(object me, string arg)
{
	object ob;
	mapping my,pmap;
	string line, skill_type,str;
	object weapon;
	int attack_points, dodge_points, parry_points;
	seteuid(getuid(me));
	str="";
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
	}
	else
		return notify_fail("只有巫师能察看别人的状态。\n");

	my = ob->query_entire_dbase();
	line = RANK_D->query_rank(ob) + ob->short(1)+"\n\n";
	line += sprintf("┌─────────────────────────┐\n");
	line += sprintf("│姓名：%-8s　年龄：%-10s　性别：%-10s│\n",
		my["name"],chinese_number(my["age"]),my["gender"]);
	line += sprintf("│门派：%-8s　师承：%-10s　辈份：%-10s│\n",
		my["family"]?my["family"]["family_name"]:"",
		my["family"]?my["family"]["master_name"]:"",
		my["family"]?"第" + chinese_number(my["family"]["generation"])+"代":"",);
	line += sprintf("│帮会：%-8s　身份：%-10s　婚姻：%-10s│\n",
		my["clan"]?clean_color(my["clan"]["name"]):"",
		my["clan"]?clean_color(my["clan"]["title"]):"",
		my["marry_name"]?my["marry_name"]:"");
	line += sprintf("│						    │\n");
	line += sprintf("│膂力：[%s]  悟性：[%s]  根骨：[%s]  身法：[%s]│\n",
			display_attr(my["str"], ob->query_str()),
			display_attr(my["int"],ob->query_int()),
			display_attr(my["con"], ob->query_con()),
			display_attr(my["dex"],ob->query_dex()));

	line += sprintf(
			"│魅力：[%s]  运气：[%s]  灵性：[%s]  定力：[%s]│\n",
			display_attr(my["per"],ob->query_per()),
			display_attr(my["kar"],ob->query_kar()),
			display_attr(my["spi"],ob->query_spi()),
			display_attr(my["cor"],ob->query_cor()));
	line += sprintf("│                                                  │\n");
	line += sprintf("│武学修为：%-8s　　　　武学评价：%-8s      │\n",
		"/cmds/std/look"->gettof(me,ob),my["is_zongshi"]?HIW"武林宗师"NOR:CYN"一般侠客"NOR);

	pmap = me->query_skill_prepare();
	if( objectp(weapon = me->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");

	if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
	line += sprintf("│战斗攻击："HIW"%-12d"NOR"    战斗防御："HIW"%-12d"NOR"  │\n",
		attack_points + 1, (dodge_points>parry_points?dodge_points:parry_points) + 1);
	line += sprintf("│战斗伤害："HIW"%-12d"NOR"    战斗防御："HIW"%-12d"NOR"  │\n",
			weapon ? ob->query_temp("apply/damage")
			: ob->query_temp("apply/unarmed_damage"),
			ob->query_temp("apply/armor"));
	line += sprintf("│                                                  │\n");
	line += sprintf("│江湖仇杀：%s%-10d"NOR"　　  杀人次数："HIR"%-10d"NOR"    │\n",
		(my["PKS"]+my["MKS"])>my["combat_exp"]/10?HIR:HIY,my["PKS"]+my["MKS"],my["PKS"]);
	line += sprintf("│被害次数："HIR"%-10d"NOR"      罪魁祸首："HIR"%-14s"NOR"│\n",
		my["VKS"],my["my_pker"]?clean_color(my["my_pker"]):"不详");
	line += sprintf("│                                                  │\n");
	line += sprintf("│善 恶 度：%s%-10d"NOR"      杀 气 值：%s%-10d"NOR"    │\n",
		my["shen"]>=0 ?HIW:HIC,my["shen"],my["bellicosity"] > (my["max_neili"] + my["neili"])?HIM:HIC,
		my["bellicosity"]);
	line += sprintf("│实战经验："HIY"%-10d"NOR"      内在潜能："HIY"%-10d"NOR"    │\n",
		my["combat_exp"],my["potential"] - my["learned_points"]);
	line += sprintf("│江湖阅历："HIC"%-10d"NOR"      江湖威望："HIC"%-10d"NOR"    │\n"NOR,
		my["score"],my["weiwang"]);
	line += sprintf("└─────────────────────────┘\n");
	write(line);
	return 1;
}

string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d" NOR, value );
	else if( value < gift ) return sprintf( YEL "%3d" NOR, value );
	else return sprintf("%3d", value);
}

int help(object me)
{
	write(@HELP
指令格式 : score
	   score <对象名称>                (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的基本资料。
基本资料的设定请参阅 'help setup'。

see also : hp
HELP
	);
	return 1;
}

