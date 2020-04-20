//sanyin-wugongzhao.c 三阴蜈蚣抓

#include <ansi.h>

inherit SKILL;
mapping *action = ({
([      "action": "$N一式「蜈蚣盘步」，右手虚晃，左手化爪，连晃几下，突然向$n的背后二穴抓去",
        "dodge": 5,
        "force": 120,
        "lvl" : 0,
        "damage_type": "抓伤"
]),

([      "action": "$N侧身一晃，十指飞舞，挟带一股从指尖冒出的阴气向$n的$l连连插去",
        "dodge": 15,
        "force": 150,
        "lvl" : 10,
        "weapon" : "指风",
        "damage_type": "刺伤"
]),

([      "action": "$N一式「毒蚣盘身」，右手爪指交错，手臂一挥，出手就扣向$n的咽喉要害",
        "dodge": 5,
        "force": 280,
        "lvl" : 20,
        "limb" : "咽喉",
        "damage_type": "抓伤"
]),

([      "action": "$N错步飘出，迷幻$n，接着右手斜斜探出，阴狠的抓向$n的$l",
        "weapon" : "利爪",
        "dodge": 10,
        "force": 180,
        "damage" : 40,
        "lvl" : 40,
        "damage_type": "抓伤"
]),

([      "action": "$N一式「蜈蚣摆尾」，十指伸缩，泛起森森蓝光，虚虚实实地袭向$n的全身要穴",
        "dodge": -7,
        "force": 270,
        "lvl" : 60,
        "damage_type": "内伤"
]),

([      "action": "$N面显阴笑，腾身飞出，十指若隐若现，若有若无，急急地抓向$n的$l",
        "dodge": -5,
        "force": 280,
        "lvl" : 80,
        "damage_type": "抓伤"
]),

([      "action": "$N惨笑一声，人如中风发狂一般，双臂连连舞动，卷起满天爪影直袭$n的$l",
        "weapon" : "手爪",
        "damage" : 30,
        "dodge": -10,
        "force": 340,
        "lvl" : 100,
        "damage_type": "抓伤"
]),
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="chousui-zhang"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练三阴蜈蚣爪必须空手。\n");
        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力太弱，无法练三阴蜈蚣爪。\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action); i > 0; i--)
                if(level >= action[i-1]["lvl"])
                        return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("sanyin-wugongzhao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
        int skill;

        skill = me->query_skill("jiuyin-baiguzhao",1);
        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练三阴蜈蚣爪。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -20);
        return 1;
}
