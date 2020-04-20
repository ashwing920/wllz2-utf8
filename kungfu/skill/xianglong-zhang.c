// xianglong-zhang.c 降龙十八掌

#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action": "$N双腿微曲，双掌平平提到胸前，右臂划个圆圈，呼的一声，一招「亢龙有悔」拍向$n",
        "dodge": 10,
        "force": 600,
        "lvl" : 0,
        "skill_name": "亢龙有悔",
        "damage_type": "瘀伤"
]),
([      "action": "$N突然飞起半空，身形旋转，双掌居高临下一招「飞龙在天」直向身下的$n压去",
        "dodge": -5,
        "force": 400,
        "lvl" : 10,
        "skill_name": "飞龙在天",
        "damage_type": "瘀伤"
]),
([      "action": "$N一招未完，一招又起，左掌回收，右掌向右一招「见龙在田」，迅捷无比地劈向$n的$l",
        "dodge": -10,
        "force": 450,
        "lvl" : 20,
        "skill_name": "见龙在田",
        "damage_type": "瘀伤"
]),
([      "action": "$N凝神闭气，双掌齐胸平推，施出这招「鸿渐于陆」，掌力夹带着隐隐风声推向$n",
        "dodge": -5,
        "force": 420,
        "lvl" : 30,
        "skill_name": "鸿渐于陆",
        "damage_type": "瘀伤"
]),
([      "action": "$N右掌聚成拳状，格开$n手臂，接着左掌向前推一招「潜龙勿用」，掌力缓缓压向$n",
        "dodge": -10,
        "force": 450,
        "lvl" : 40,
        "skill_name": "潜龙勿用",
        "damage_type": "内伤"
]),
([      "action": "爆喝声中$N飞身上前，单掌劈出一招「利涉大川」，降龙掌掌风如刀，划向$n的$l",
        "dodge": 5,
        "force": 500,
        "damage" : 15,
        "weapon" : "降龙掌掌风",
        "lvl" : 50,
        "damage_type": "割伤"
]),
([      "action": "$N双掌相并，身体突然前跃，使出「突如其来」这招，掌力排山倒海般向$n正面推出",
        "dodge": 10,
        "force": 420,
        "lvl" : 60,
        "damage_type": "瘀伤"
]),
([      "action": "$N大吼一声，空门大开，双掌一上一下使出「震惊百里」，不顾一切地斩击$n",
        "dodge": -25,
        "force": 500,
        "lvl" : 70,
        "damage_type": "瘀伤"
]),
([      "action": "$N跨前一步，一招「或跃在渊」，左右双掌向$n连连拍出，掌风更带起地上无数沙石",
        "dodge": -10,
        "force": 500,
        "lvl" : 80,
        "damage_type": "瘀伤"
]),
([      "action": "$N身形向前移动，双掌分使两式「双龙取水」，凌厉的掌风一左一右同时压向$n$l",
        "dodge": -10,
        "force": 470,
        "lvl" : 90,
        "damage_type": "瘀伤"
]),
([      "action": "$N左脚微曲，身形飞起，于半空中拍出「鱼跃于渊」，双掌立砍，齐向$n的$l劈下",
        "dodge": -5,
        "force": 440,
        "weapon" : "手掌",
        "lvl" : 100,
        "damage_type": "割伤"
]),
([      "action": "$N扎个马部，使出招「时乘六龙」，双掌一正一反向$n周身连连续续猛烈砍了十数下",
        "dodge": -10,
        "force": 500,
        "lvl" : 110,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出一招「密云不雨」，左掌掌力拍出，封住$n的退路，右掌斜斜地劈向他的$l",
        "dodge": -10,
        "damage" : 15,
        "weapon" : "降龙掌掌力",
        "force": 430,
        "lvl" : 120,
        "damage_type": "割伤"
]),
([      "action": "$N弓步向前，一招「损则有孚」，双掌看似软绵绵地拍向$n，但地上的沙石却连连飞起",
        "dodge": -15,
        "force": 500,
        "lvl" : 130,
        "damage_type": "内伤"
]),
([      "action": "$N脚下一转，突然欺身到$n身前，右掌护身，左掌一招「龙战于野」，猛然砍向$n的$l",
        "dodge": -5,
        "damage" : 20,
        "weapon" : "掌缘",
        "force": 430,
        "lvl" : 140,
        "damage_type": "割伤"
]),
([      "action": "$N一声爆喝，胸前门户大开，双掌相并，齐向$n猛地推去，正是一招「履霜冰至」",
        "dodge": -25,
        "force": 420,
        "lvl" : 150,
        "damage_type": "瘀伤"
]),
([      "action": "$N左掌低垂，右掌抬高，使出一招「羝羊触蕃」，两股雄浑的掌力同时向中间的$n挤压下去",
        "dodge": 5,
        "force": 400,
        "lvl" : 160,
        "damage_type": "瘀伤"
]),
([      "action": "但见$N左掌护胸，身体后转，右掌紧跟着一摆，一招「神龙摆尾」拍向身后的$n",
        "dodge": 15,
        "force": 370,
        "lvl" : 170,
        "damage_type": "瘀伤"
]),
});
int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry" || usage=="strike"; }
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练降龙十八掌必须空手。\n");
        if ((int)me->query_skill("huntian-qigong", 1) < 20)
                return notify_fail("你的混天气功火候不够，无法练降龙十八掌。\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("你的内力太弱，无法练降龙十八掌。\n");
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
        return action[random(sizeof(action))];
}
mixed hit_ob(object me, object victim)
{
        int skill_level;
        skill_level = me->query_skill("xianglong-zhang",1);
        
        if(!me->query_temp("weapon") 
        && !me->query_temp("secondary_weapon")
        && me->is_fighting(victim) && victim->is_fighting(me)
        && living(victim) && victim->query("qi") > 0)
        if(random(skill_level)>200 && me->query("neili")>2000){
                me->add("neili",-random(500)-500);
                message_vision(HIY+"\n$N深深吸了口气，大吼一声，把降龙十七掌的精华融于双掌之中，\n"
                +"刹那间只看到狂风大作，飞沙走石，天地为之变色....\n"+NOR,me);
                COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
        }
        return 1;
}
int practice_skill(object me)
{
        if ((int)me->query("qi") < 40)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("你的内力不够练降龙十八掌。\n");
        me->receive_damage("qi", 30);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"xianglong-zhang/" + action;
}
