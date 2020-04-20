//mahayana.c  大乘涅磐功

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (!myfam || (myfam["family_name"] != "峨嵋派"))
                return notify_fail("你不是峨嵋弟子，不能修炼大乘涅磐功。\n");

        if ((int)me->query("shen") < 0 )
                return notify_fail("你的邪气太重，无法修炼大乘涅磐功。\n");

        if((int)me->query_skill("poison",1) > 1 )
                return notify_fail("你学了邪门毒技，无法修炼大乘涅磐功。\n");

        return 1;
}
void skill_improved(object me)
{}
