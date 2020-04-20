
// abandon.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int skill_lvl, lvl=0;
	string skill;

	if(!arg || arg == "" || sscanf(arg, "%s %d", skill, lvl)!=2 &&
	sscanf(arg, "%s", skill)!=1)
		return notify_fail("你要放弃哪一项技能？\n");
	skill_lvl = me->query_skill(skill,1);

	if( skill == me->query_skill_mapped("sword")
	||  skill == me->query_skill_mapped("unarmed")
	||  skill == me->query_skill_mapped("blade")
	||  skill == me->query_skill_mapped("staff")
	||  skill == me->query_skill_mapped("dodge")
	||  skill == me->query_skill_mapped("parry")
	||  skill == me->query_skill_mapped("force")
	||  skill == me->query_skill_mapped("club")
	||  skill == me->query_skill_mapped("whip")
	||  skill == me->query_skill_mapped("hand")
	||  skill == me->query_skill_mapped("cuff")
	||  skill == me->query_skill_mapped("claw")
	||  skill == me->query_skill_mapped("strike")
	||  skill == me->query_skill_mapped("dagger")
	||  skill == me->query_skill_mapped("finger"))
		return notify_fail("你必须取消这种特殊技能的装备才能够取消。\n");

	if(!skill_lvl)
		return notify_fail("你没有学过这种技能！\n");
	if( lvl <0 )
		return notify_fail("技能级别不能为负。\n");
	if( lvl == skill_lvl && lvl>0)
		return notify_fail("你有问题啊。你不就是这级别麽。\n");
	if( lvl > skill_lvl || lvl > 400)
		return notify_fail("你这项技能并没有学到这个级别。\n");
	if( !me->delete_skill(skill) )
		return notify_fail("你并没有学过这项技能。\n");
	if( lvl > 0)
	write("你把" + to_chinese(skill) + "降低为"+ chinese_number(lvl) +"级。\n");
	else
	write("你决定放弃继续学习" + to_chinese(skill) + "。\n");
	if( lvl > 0 ) me->set_skill(skill, lvl);
	me->delete("shen_learn");
	return 1;
}

int help()
{
	write(@TEXT
指令格式：abandon|fangqi <技能名称> [级别]

放弃一项你所学过的技能，注意这里所说的「放弃」是指将这项技能从你人物
的资料中删除，如果你以后还要练，必须从０开始重练，请务必考虑清楚。

但如果你在放弃命令时有输入级别，将只放弃到指定级别。

这个指令使用的场合通常是用来删除一些「不小心」练出来的技能，由于每个
人有着不同的天赋，所修习的武功也不会相同。如果样样都学，到头来只会样
样不精。
TEXT
	);
	return 1;
}
