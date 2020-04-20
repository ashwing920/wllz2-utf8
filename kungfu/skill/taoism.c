// taoism.c

inherit SKILL;
string type() { return "knowledge"; }
void create() { seteuid(getuid()); }

int max_skill() { return 800;}

int valid_learn(object me)
{
        int lvl;

        lvl = (int)me->query_skill("taoism", 1);

        if( (int)me->query("shen") < 0 )
                return notify_fail("你的邪气太重，无法修炼道学心法。\n");

        if((int)me->query_skill("buddhism",1)
        || (int)me->query_skill("lamaism",1)
        || (int)me->query_skill("mahayana",1))
                return notify_fail("你不放弃其他学家心法，如何学习道家心法？\n");

        if(me->query("gender") == "无性" && lvl > 39)
                return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之气，无法领会里面的阴阳变化之道。\n");

        if(me->query("class") == "bonze")
                return notify_fail("哈哈！"+RANK_D->query_respect(me)+"即入佛门，怎么却来学道家心法？\n");


        return 1;
}

void skill_improved(object me)
{}
