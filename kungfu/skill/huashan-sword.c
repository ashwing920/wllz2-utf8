
// huashan-sword.c 华山剑法

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      
        "skill_name":   "有凤来仪",
        "action":       "$N使一招「"HIG"有凤来仪"NOR"」，手中$w剑光暴长，向$n的$l刺去",
        "dodge":        50,
        "damage":       170,
        "lvl"   :       20,
        "damage_type":  "刺伤"
]),
([
        "skill_name":   "无边落木",
        "action":       "$N剑随身转，一招「"HIG"无边落木"NOR"」罩向$n的$l",
        "dodge":        70,
        "damage":       20,
        "lvl"   :       40,
        "damage_type":  "刺伤"
]),
([
        "skill_name":   "鸿飞冥冥",
        "action":       "$N舞动$w，一招「"HIG"鸿飞冥冥"NOR"」挟著无数剑光刺向$n的$l",
        "dodge":        40,
        "damage":       90,
        "lvl"   :       60,
        "damage_type":  "刺伤"
]),
([        
        "skill_name":   "平沙落雁",
        "action":       "$N手中$w龙吟一声，祭出「"HIG"平沙落雁"NOR"」往$n的$l刺出数剑",
        "dodge":        40,
        "damage":       40,
        "lvl"   :       80,
        "damage_type":  "刺伤"
]),
([      
        "skill_name":   "金玉满堂",
        "action":       "$N手中$w剑光暴长，一招「"HIG"金玉满堂"NOR"」往$n$l刺去",
        "dodge":        60,
        "damage":       120,
        "lvl"   :       160,
        "damage_type":  "刺伤"
]),
([
        "skill_name":   "白虹贯日",
        "action":       "$N手中$w化成一道光弧，直指$n$l，一招「"HIG"白虹贯日"NOR"」发出虎哮龙吟刺去",
        "dodge":        60,
        "damage":       150,
        "lvl"   :       200,
        "damage_type":  "刺伤"
]),
});

int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_neili") < 50 )
                return notify_fail("你的内力不够，没有办法练华山剑法。\n");
        if( (string)me->query_skill_mapped("force")!= "zixia-shengong")
                return notify_fail("华山剑法必须配合紫霞神功才能练。\n");
        if( !(ob = me->query_temp("weapon"))
        ||        (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
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
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("qi") < 30
        ||        (int)me->query("neili") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习华山剑法。\n")
;
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
        return __DIR__"huashan-sword/" + action;
}
