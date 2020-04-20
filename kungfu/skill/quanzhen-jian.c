// quanzhen-jian.c 全真剑法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":"$N使一式「探海屠龙」，手中$w由左至右横扫向向$n的$l",
        "force" : 120,
        "dodge" : 0,
        "damage": 30,
        "lvl" : 0,
        "skill_name" : "探海屠龙",
        "damage_type":  "割伤"
]),
([      "action":"$N踏上一步，「罡风扫叶」，手中$w盘旋飞舞出一道剑光劈向$n的$l",
        "force" : 140,
        "dodge" : 10,
        "damage": 40,
        "lvl" : 9,
        "skill_name" : "罡风扫叶",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w一抖，一招「顺水推舟」，斜斜一剑反腕撩出，攻向$n的$l",
        "force" : 160,
        "dodge" : 5,
        "damage": 50,
        "lvl" : 18,
        "skill_name" : "顺水推舟",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w连绕数个大圈，一式「星弛电闪」，一道剑光飞向$n的$l",
        "force" : 180,
        "dodge" : 10,
        "damage": 65,
        "lvl" : 27,
        "skill_name" : "星弛电闪",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式「白鹤亮翅」，左手伸展，右手$w挥向$n的$l",
        "force" : 220,
        "dodge" : 15,
        "damage": 80,
        "lvl" : 36,
        "skill_name" : "白鹤亮翅",
        "damage_type":  "割伤"
]),
([      "action":"$N手中$w斜指苍天，一式「横行漠北」，对准$n的$l斜斜击出",
        "force" : 260,
        "dodge" : 5,
        "damage": 100,
        "lvl" : 44,
        "skill_name" : "横行漠北",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式「马蹴落花」，手腕急抖，挥洒出万点金光，刺向$n的$l",
        "force" : 320,
        "dodge" : 5,
        "damage": 105,
        "lvl" : 52,
        "skill_name" : "马蹴落花",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式「九品莲台」，$w飞斩盘旋，如疾电般射向$n的胸口",
        "force" : 380,
        "dodge" : 5,
        "damage": 125,
        "lvl" : 60,
        "skill_name" : "九品莲台",
        "damage_type":  "刺伤"
]),
([      "action":"$N使一式「荆轲刺秦」，手中$w合身疾刺$n的胸口，威不可当",
        "force" : 380,
        "dodge" : 5,
        "damage": 125,
        "lvl" : 70,
        "skill_name" : "荆轲刺秦",
        "damage_type":  "刺伤"
]),
([      "action":"$N手中$w划出一道长长的弧线，刺向$n的$l，却是一招「箫史乘龙」",
        "force" : 380,
        "dodge" : 5,
        "damage": 140,
        "lvl" : 80,
        "skill_name" : "箫史乘龙",
        "damage_type":  "刺伤"
]),
([      "action":"$N回剑自守，使一式「深藏若虚」，蓦地手中$w向$n击出",
        "force" : 380,
        "dodge" : 5,
        "damage": 140,
        "lvl" : 90,
        "skill_name" : "深藏若虚",
        "damage_type":  "刺伤"
]),
([      "action":"$N左足踢起，一式「魁星踢斗」，$w从不可思议的角度刺向$n",
        "force" : 380,
        "dodge" : 5,
        "damage": 140,
        "lvl" : 114,
        "skill_name" : "魁星踢斗",
        "damage_type":  "刺伤"
]),
([      "action":"$N一式「紫电穿云」，$w突然从天而降，一片金光围掠$n全身",
        "force" : 380,
        "dodge" : 5,
        "damage": 155,
        "lvl" : 129,
        "skill_name" : "紫电穿云",
        "damage_type":  "刺伤"
])
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }
int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 10 )
                return notify_fail("你的内功心法火候不到，无法学习全真剑法。\n");
        if((int)me->query_skill("jinyan-gong",1) < 10
        && me->query("family/family_name") != "古墓新派")
                return notify_fail("你的金雁功还不够火候，无法学习全真剑法！\n");
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
        level   = (int) me->query_skill("quanzhen-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练全真剑法。\n");
        me->receive_damage("qi", 25);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"quanzhen-jian/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;
        if((int)me->query_skill("quanzhen-jian",1)> 200 && (int)me->query("neili") > 200)
        if( random(me->query("neili")) > victim->query("max_neili")
        && me->query("family/family_name") == "全真教") {
                victim->receive_damage("qi",(damage_bonus - 100) / 2 ,me);
                message_vision(WHT"只听见“哧”的一声响，一道白光泛起，$N的剑气在$n胸口划开了一道"HIR"血口！\n",me,victim);
                me->add("neili",-100);
                return 1;
        }       
}
