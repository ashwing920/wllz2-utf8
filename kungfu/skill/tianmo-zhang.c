#include <ansi.h>

inherit SKILL;
mapping *action = ({

        ([
                "action": "$N睹准空隙，暴喝一声，一掌印向$n的胸膛心坎穴。",
                "dodge": 30,
                "force": 160,
                "damage_type": "瘀伤"
        ]),

        ([
                "action": "$N运劲于双掌之上，有如千斤巨斧，狂劈$n顶门。",
                "dodge": 10,
                "force": 160,
                "damage_type": "瘀伤"
        ]),

        ([
                "action": "$N施展身法，幻成两个身形，四道掌力劲度万钧，飞劈向$n的$l",
                "dodge": 20,
                "force": 150,
                "damage_type": "瘀伤"
        ]),
        ([
                "action": "$N身影一动，幻化成四个身形，八掌带动连串气劲攻向$n全身。",
                "dodge": 30,
                "force": 200,
                "damage_type": "瘀伤"
        ]),

        ([
                "action": "$N猛地腾空而起，于半空幻化成八道身形，掌劲铺天盖地般的朝$n盖顶而下。",
                "dodge": 40,
                "force": 300,
                "damage_type": "瘀伤"
        ]),

});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry" || usage == "strike"; }
mapping query_action(object me)
{

        if (random(me->query_skill("unarmed")) > 60 && me->query_skill("force") > 50 &&
                me->query("neili") > 100) {
                me->add("neili", -100);
                return ([
                        "action": HIY"只见$N拚尽全力，全身急疾飞旋，双掌豪光暴现，一股骇人的掌力攻向$n的胸前"NOR,
                        "force": 600,
                        "damage": 400,
                        "damage_type": "瘀伤"
                        ]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练天魔掌必须空手。\n");
        if ((int)me->query_skill("tianmo-dafa", 1) < 10)
                return notify_fail("你的天魔大法火候不够，无法练天魔掌。\n");
        if ((int)me->query("max_neili") < 60)
                return notify_fail("你的内力太弱，无法练天魔掌");
        return 1;

}
int practice_skill(object me)
{

        if ((int)me->query("qi") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练天魔掌。\n");
        if (me->query_skill("tianmo-zhang", 1) < 50)
                me->receive_damage("qi", 20);
        else
                me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;

}
