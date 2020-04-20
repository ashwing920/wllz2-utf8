// dagou-bang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action": HIG"$N使出一招「棒打双犬」，手中$w化作两道青光砸向$n的$l"NOR,
        "force" : 50,
        "dodge": -10,
        "damage": 30,
        "lvl" : 1,
        "skill_name":HIG"棒打双犬"NOR,
        "damage_type": "挫伤"
]),
([      "action": HIG"$N手中$w左右晃动，一招「拨草寻蛇」向$n的$l攻去"NOR,
        "dodge": -20,
        "force" : 100,
        "damage": 55,
        "lvl" : 33,
        "skill_name":HIG"拔草寻蛇"NOR,
        "damage_type": "挫伤"
]),
([      "action": HIG"$N举起$w，居高临下使一招「打草惊蛇」敲向$n的$l"NOR,
        "dodge": -30,
        "force" : 180,
        "damage": 80,
        "lvl" : 66,
        "skill_name":HIG"打草惊蛇"NOR,
        "damage_type": "挫伤"
]),
([      "action": HIG"$N施出「拨狗朝天」，$w由下往上向$n撩去"NOR,
        "dodge": -20,
        "force" : 250,
        "damage": 100,
        "lvl" : 100,
        "skill_name":HIG"拨狗朝天"NOR,
        "damage_type": "挫伤"
]),
([      "action" : "$N倏地伸出$w，使出一招「压扁狗背」，棒头搭向$n的$l，轻轻向下按落",
        "force"         : 260,
        "dodge"         : 20,
        "damage"        : 100,
        "lvl"           : 120,
        "skill_name"    : HIB"压扁狗背"NOR,
        "damage_type"   : "挫伤"
]),
([      "action" : "$N手中$w从旁递出，一招「恶狗拦路」，$w侧抖旁缠，向外斜甩，攻向$n",
        "force"         : 280,
        "dodge"         : 40,
        "damage"        : 120,
        "lvl"           : 150,
        "skill_name"    : HIR"恶狗拦路"NOR,
        "damage_type"   : "挫伤"
]),
([      "action" : "$N提起$w，一招「棒打狗头」，击向$n的头顶，出手狠辣，正是「打狗棒法」中的高招",
        "force"         : 300,
        "dodge"         : 60,
        "damage"        : 130,
        "lvl"           : 200,
        "skill_name"    : HIC"棒打狗头"NOR,
        "damage_type"   : "挫伤"
]),
([      "action" : "$N倒提$w，扭身反背，顺势一招「反戳狗臀」，$w从胯底穿出，戳向$n$l",
        "force"         : 340,
        "dodge"         : 70,
        "damage"        : 150,
        "lvl"           : 250,
        "skill_name"    : HIM"反戳狗臀"NOR,
        "damage_type"   : "挫伤"
]),
([      "action" : "只见$N将身一幌，手中$w一招「关门打狗」对着$n的$l一连打出七棒",
        "force"         : 360,
        "dodge"         : 80,
        "damage"        : 200,
        "lvl"           : 270,
        "skill_name"    : HIG"关门打狗"NOR,
        "damage_type"   : "挫伤"
]),
([      "action" : "$N将身一幌，，手中$w一招「天下无狗」，$n只觉得全身被笼罩在一团棒影之中。",
        "force"         : 360,
        "dodge"         : 90,
        "damage"        : 250,
        "lvl"           : 300,
        "skill_name"    : YEL"天下无狗"NOR,
        "damage_type"   : "挫伤"
]),
([      "action" : "$N腾空而起，手中$w一抖，使出一招「天下无狗」，如山棍影，疾疾压向$n",
        "force"         : 500,
        "dodge"         : 150,
        "damage"        : 300,
        "lvl"           : 350,
        "skill_name"    : HIW"天下无狗"NOR,
        "damage_type"   : "挫伤"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry") || (usage == "club"); }

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
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i,level;
        level =(int)me->query_skill("dagou-bang",1);

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你的体力不够练打狗棒法。\n");
        me->receive_damage("qi", 40);
        return 1;
}

string perform_action_file(string action)
{
          return __DIR__"dagou-bang/" + action;
}
