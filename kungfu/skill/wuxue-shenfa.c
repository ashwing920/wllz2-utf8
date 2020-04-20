// bugui.c 不归步法

inherit SKILL;

string *dodge_msg = ({
    "$n一个「急转步」，随着$N的攻势飘起，从容躲过这一招。\n",
    "$n使出一招「捕风捉影」，猛然纵起丈余，结果$N扑了个空。\n",
    "$n身形一摇，幻出几个人影，一招「花影重重」躲过了$N的攻势。\n",
    "$n一招「虚无飘渺」纵身跃起，倏忽已落至$N身后。\n",
    "$n左一摇，右一晃，一招「倾灭无常」已轻松闪过。\n",
    "$n双足一点，斜斜飞起，使出「世代相随」已闪到$N身侧。\n",
});

int valid_enable(string usage) 
{ 
    return (usage == "dodge") ;
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30 )
            return notify_fail("你的体力太差了，不能练暗影浮香。\n");
        if (me->query_skill("bugui-bufa", 1) < 30)
                me->receive_damage("qi", 10);
                me->receive_damage("qi", 20);
        return 1;
}
