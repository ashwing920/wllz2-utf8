// chousui-duzhang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit SKILL;

mapping *action = ({
([      "action": "$N催动内力，衣袖挥动，双掌挟着一股腥臭之气一前一后拍向$n的$l",
        "dodge": 5,
        "force": 130,
        "lvl" : 0,
        "damage_type": "瘀伤"
]),
([      "action": "$N双脚一曲一弯，身体旋转起来, 突然间双掌飞舞着拍向$n的$l",
        "dodge": 15,
        "force": 140,
        "lvl" : 0,
        "damage_type": "瘀伤"
]),
([      "action": "$N身形飘动，围着$n一圈圈游走，同时双掌连拍，激起阵阵劲风吹向$n",
        "dodge": 5,
        "force": 170,
        "lvl" : 30,
        "damage_type": "内伤"
]),
([      "action": "$N突然厉声大喝，跃于半空，立掌如斧，上上下下向$n连连劈出数掌",
        "weapon" : "掌风",
        "dodge": 10,
        "force": 320,
        "damage" : 20,
        "lvl" : 50,
        "damage_type": "割伤"
]),
([      "action": "$N身形微晁抢前一步，运起十成功力，大喝一声，须发戟张，呼的一掌又向$n推去",
        "dodge": -7,
        "force": 260,
        "lvl" : 70,
        "damage_type": "内伤"
]),
([      "action": "$N面露诡异的笑容，猛地向前冲出，对准$n的$l就是一招阴毒无比的「抽髓掌」",
        "dodge": -5,
        "force": 220,
        "lvl" : 95,
        "damage_type": "瘀伤"
]),
([      "action": "$N心念一转，计上心来，一招「三阴蜈蚣爪」，招招连环，连珠般抓向$n的$l",
        "weapon" : "手爪",
        "damage" : 30,
        "dodge": -10,
        "force": 290,
        "lvl" : 120,
        "damage_type": "抓伤"
]),
});
int valid_enable(string usage) { return usage=="strike" || usage=="unarmed" || usage=="parry"; }

int valid_combine(string combo) { return combo=="sanyin-wugongzhao"; }

mapping query_action(object me)
{
        if (random(me->query_skill("unarmed",1)) > 60 &&
        me->query_skill("force",1) > 50 &&
        me->query("neili") > 100 ) {
                 me->add("neili", -100);
                 return ([
                  "action": "$N咬破舌尖，口中喷血，聚集全身的力量击向$n",
                  "force": 300,
                  "damage_type": "瘀伤"]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
           return notify_fail("练抽髓掌必须空手。\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
           return notify_fail("你的化功大法火候不够，无法练抽髓掌。\n");
        if ((int)me->query("max_neili") < 60)
           return notify_fail("你的内力太弱，无法练抽髓掌。");
        return 1;
}


int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 8)
        return notify_fail("你的内力不够练抽髓掌。\n");
        if (me->query_skill("chousui-zhang", 1) < 50)
        me->receive_damage("qi", 20);
        else
        me->receive_damage("qi", 30);
         me->add("neili", -5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("huagong-dafa",1)) > 5) {
        victim->apply_condition("xx_poison", random(2) + 1 +
        victim->query_condition("xx_poison"));
        }
}
string perform_action_file(string action)
{
        return __DIR__"chousui-zhang/" + action;
}
