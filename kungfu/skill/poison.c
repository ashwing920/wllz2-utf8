// poison.c 基本毒技

inherit SKILL;

void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int max_skill() { return 800;}

int valid_learn(object me)
{
	mapping myfam;
	myfam = (mapping)me->query("family");
	if (!myfam || (myfam["family_name"] != "星宿派"
	&& myfam["family_name"] != "五毒神教"
	&& myfam["family_name"] != "白驼山派"
	&& myfam["family_name"] != "唐门"
	&& myfam["family_name"] != "神龙教"))
	       return notify_fail("你想要学习基本毒技，可是总是觉得缺了点什么，对用毒的技巧总是难以理解。\n");

	if(((int)me->query_skill("taoism",1) > 1) 
	|| ((int)me->query_skill("mahayana",1) > 1) 
	|| ((int)me->query_skill("buddhism",1) > 1))
		return notify_fail("哈哈！"+RANK_D->query_respect(me)+"已经学了名门正派的心法，怎么却来学你们不耻的毒技？\n");

	return 1;
}
int practice_skill(object me)
{
	return notify_fail("基本毒技只能靠学(learn)来提高。\n");
}
