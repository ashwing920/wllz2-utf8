// lamaism.c 密宗心法

inherit SKILL;
string type() { return "knowledge"; }
void create() { seteuid(getuid()); }

int max_skill() { return 800;}

int valid_learn(object me)
{
        if((int)me->query_skill("taoism",1)
        ||(int)me->query_skill("buddhism",1) 
        ||(int)me->query_skill("mahayana",1))
                return notify_fail("你不放弃其他学家心法，如何修炼密宗心法？\n");

        if((int)me->query_skill("lamaism",1) > 39 && me->query("gender") == "无性")
                return notify_fail("你无根无性，无法再学习高深的密宗心法了。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("密宗心法只能靠学(learn)来提高。\n");
}
