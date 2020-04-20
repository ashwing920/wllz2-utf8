// buddhism.c

inherit SKILL;
string type() { return "knowledge"; }
void create() { seteuid(getuid()); }

int max_skill() { return 800;}

int valid_learn(object me)
{
        if( (int)me->query("guilty") > 0 )
                return notify_fail("你屡犯僧家数戒，尘俗之心太重，无法修炼禅宗心法。\n");

        if((int)me->query_skill("taoism",1)
        || (int)me->query_skill("lamaism",1)
        || (int)me->query_skill("mahayana",1))
                return notify_fail("你不放弃其他学家心法，如何学习禅宗心法？\n");

        if(me->query("gender") != "男性")
               return notify_fail("你没有阳刚之气，无法领会里面的阴阳变化之道。\n");
        if(me->query("class") == "taoist")
                return notify_fail("你已是道士，怎么却来学禅宗心法呢？\n");
        return 1;

}
int practice_skill(object me)
{
        return notify_fail("禅宗心法只能靠学(learn)来提高。\n");
}
