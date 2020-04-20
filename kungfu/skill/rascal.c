                                      // rascal.c - 混混之技

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" :      "只见$N突然从怀里掏出一包石灰，向$n撒了过去",
        "force"         : 50,
        "dodge"         : -10,
        "parry"         : -10,
        "damage"        : 5,
        "lvl"           : 0,
        "damage_type"   : "瘀伤"
]),
([      "action" :      "只见$N突然从桌子底下伸出手来，拿着一把匕首向$n的$l戮了下去",
        "force"         : 80,
        "dodge"         : -5,
        "parry"         : -5,
        "damage"        : 10,
        "lvl"           : 10,
        "damage_type"   : "瘀伤"
]),
([      "action" :      "$N纵身前跃，一把拉住$n的$l，张开大嘴，猛的咬了下去",
        "force"         : 100,
        "dodge"         : 1,
        "parry"         : 1,
        "damage"        : 20,
        "lvl"           : 20,
        "damage_type"   : "瘀伤"
]),
([      "action" :      "只见$N丢给$n一叠"HIW"一千两银票"NOR"，$n看得一时怔住了",
        "force"         : 120,
        "dodge"         : 10,
        "parry"         : 10,
        "damage"        : 30,
        "lvl"           : 30,
        "damage_type"   : "瘀伤"
]),
([      "action" :      "$N迅速的从怀里取出一支迷香，向$n吹了过来",
        "force"         : 140,
        "dodge"         : 20,
        "parry"         : 20,
        "damage"        : 40,
        "lvl"           : 40,
        "damage_type"   : "瘀伤"
]),
([      "action" :      "$N向$n跪将下来，$n正待扶起，突然一把暗器从$N的脑后射了出来，直飞$n的$l而去",
        "force"         : 160,
        "dodge"         : 30,
        "parry"         : 30,
        "damage"        : 50,
        "lvl"           : 50,
        "damage_type"   : "瘀伤"
]),
([      "action" :      "$N施展油嘴滑舌功，对$n一个劲的拍马擦鞋，$n一时听到入了迷，顿觉天昏地暗，头昏脑账",
        "force"         : 180,
        "dodge"         : 40,
        "parry"         : 40,
        "damage"        : 60,
        "lvl"           : 60,
        "damage_type"   : "瘀伤"
]),
([      "action" :      "$N施展英雄三招，却是无招无式，错乱百出，一个劲的向$n攻了过来",
        "force"         : 200,
        "dodge"         : 50,
        "parry"         : 50,
        "damage"        : 70,
        "lvl"           : 70,
        "damage_type"   : "瘀伤"
]),
([      "action" :      "$N施展美女三招，顿时婀娜多姿，娇媚万分，看得$n一个劲的恶心，直打哆嗦",
        "force"         : 220,
        "dodge"         : 60,
        "parry"         : 60,
        "damage"        : 80,
        "lvl"           : 80,
        "damage_type"   : "瘀伤"
]),
([      "action" :      "$N突然坐在地上撒娇，时而放声大哭，$n看得一时之间不知所措，整个人怔住了",
        "force"         : 240,
        "dodge"         : 70,
        "parry"         : 70,
        "damage"        : 100,
        "lvl"           : 100,
        "damage_type"   : "瘀伤"
]),
});

int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力不够。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"]) return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i,level;
        level = (int) me->query_skill("rascal",1);
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"]) return action[random(i)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力不够练小宝绝活。\n");
        me->receive_damage("qi", 35);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"xiaobao-juehuo/" + action;
}
