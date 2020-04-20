//riyue-bian.c
//日月鞭法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([     "action": "$N端坐不动，一式「阿那律刺」，手腕力抬，$w滚动飞舞，宛如灵蛇乱颤，前缠后绕，其力沾粘不散",
       "dodge": 5,
       "damage": 70,
       "force": 150,
       "lvl" : 0,
       "skill_name" : "阿那律刺",
       "damage_type":  "拉伤"
]),
([     "action": "$N一式「目捷连刺」，将手$w中抖得笔直，“呲呲”声中向$n疾刺而至，所挟劲风已令$n一阵气窒",
       "dodge": 10,
       "damage": 60,
       "force": 200,
       "lvl" : 30,
       "skill_name" : "目捷连刺",
       "damage_type":  "刺伤"
]),
([     "action": "$N内劲到处，将$w抖动转成两个圆圈，一式「舍利佛刺」，跃起从半空中往$n$l缠下",
       "dodge": -20,
       "damage": 150,
       "force":  300,
       "lvl" : 60,
       "skill_name" : "舍利佛刺",
       "damage_type":  "拉伤"
]),
([     "action": "$N劲走螺旋，一式「富楼那刺」，$w在$n眼前上圈下钩，左旋右转，连变了数种招式，忽然从$n$l处倒卷上来",
       "dodge": 10,
       "damage": 180,
       "force": 200,
       "lvl" : 90,
       "skill_name" : "富楼那刺",
       "damage_type":  "拉伤"
]),
([     "action": "$N一声高喝，吸气催力，一式「迦旋延刺」，$w急速转动，鞭影纵横，直中有圆，圆中有直，似真似幻，绞向$n",
       "dodge": 15,
       "damage": 150,
       "force": 300,
       "lvl" : 120,
       "skill_name" : "迦旋延刺",
       "damage_type":  "拉伤"
]),
([     "action": "$N含胸拔背、沉肩坠肘，一式「弘忍能刺」，力道灵动威猛，虚实分明，劲力从四面八方向$n挤压出去",
       "dodge": 25,
       "damage": 220,
       "force": 350,
       "lvl" : 150,
       "skill_name" : "弘忍能刺",
       "damage_type":  "拉伤"
]),
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }
int valid_learn(object me)
{

        object weapon;
        if( (int)me->query("max_neili") < 200 )
                return notify_fail("你的内力不足，没有办法练天魔日月鞭法, 多练些内力再来吧。\n");
        if((int)me->query_skill("tianmo-dafa", 1) < 50
        && me->query("family/family_name") != "少林派")
                return notify_fail("你的天魔大法火候太浅。\n");
        if( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("你必须先找一条鞭子才能练鞭法。\n");
        return 1;
}
string query_skill_name(int level)
{

        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{

        int i, level;
        level   = (int) me->query_skill("riyue-bian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        object weapon;
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练天魔日月鞭法。\n");
        me->receive_damage("qi", 5);
        return 1;

}
string perform_action_file(string action)
{
        return __DIR__"riyue-bian/" + action;
}
