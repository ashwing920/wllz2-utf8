//wudang-jian.c 武当剑法

inherit SKILL;

mapping *action = ({
([      "action": "$N剑法迅捷，$w「云横秦岭」，画了个圈子，一剑栏腰削去。$w如影随形，直刺$n$l",
	"force" : 100,
	"dodge" : 10,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "云横秦岭",
	"damage_type": "刺伤"
]),
([      "action": "$N当下剑交左手，一路左手剑向$n逼去，$w「白虹贯日」向$l刺去，剑势凌厉",
	"force" : 120,
	"dodge" : -10,
	"damage": 30,
	"lvl" : 10,
	"skill_name" : "白虹贯日",
	"damage_type": "刺伤"
]),
([      "action": "$N「春云乍展」，挺剑疾刺$n$l，一柄$w施展开来，有如飞絮游丝，长河流水，轻灵连绵",
	"force" : 140,
	"dodge" : 10,
	"damage": 25,
	"lvl" : 20,
	"skill_name" : "春云乍展",
	"damage_type": "刺伤"
]),
([      "action": "$N突然跃起，回手就是一剑「天坤倒悬」，这一剑又快又准，寒光闪处，剑锋已及$n$l",
	"force" : 170,
	"dodge" : 5,
	"damage": 35,
	"lvl" : 30,
	"skill_name" : "天坤倒悬",
	"damage_type": "刺伤"
]),
([      "action": "$N当下抢到$n左首，$w「天外来云」，$w寒光起处，嗤嗤嗤一阵破空之声，向$n左右连刺",
	"force" : 190,
	"dodge" : -10,
	"damage": 40,
	"lvl" : 40,
	"skill_name" : "天外来云",
	"damage_type": "刺伤"
]),
([      "action": "倏地$N一招「耿耿银河」，$w一剑横削，随即千头�绪般乱点下来，真如天上繁星一般",
	"force" : 210,
	"dodge" : 20,
	"damage": 45,
	"lvl" : 50,
	"skill_name" : "耿耿银河",
	"damage_type": "刺伤"
]),
([      "action": "$N向$n刷刷两剑，「满天花雨」四下圈挥，$w出手，连绵不断，俱是进手招数，攻势凌厉之极",
	"force" : 230,
	"dodge" : 0,
	"damage": 55,
	"lvl" : 60,
	"skill_name" : "满天花雨",
	"damage_type": "刺伤"
]),
([      "action": "$N$w横架头顶，一个「凤凰展翅」，$w一圈，但见$P剑走轻灵，光闪如虹，吞吐开阖之际，又飘逸，又凝重",
	"force" : 250,
	"dodge" : 10,
	"damage": 45,
	"lvl" : 70,
	"skill_name" : "凤凰展翅",
	"damage_type": "刺伤"
]),
([      "action": "蓦地里青光一闪，一柄$w从$N手中掷出，急飞向$n，如风驰电掣般射向$p$l，却是一招「银河横空」",
	"force" : 280,
	"dodge" : 0,
	"damage": 50,
	"lvl" : 80,
	"skill_name" : "银河横空",
	"damage_type": "刺伤"
]),
([      "action": "呛啷啷一声，剑光闪闪，$w递出，$N目视剑尖，心无旁鹜，含胸拔背、沉肩坠肘，摆了一招「万岳朝宗」的姿式",
	"force" : 300,
	"dodge" : -5,
	"damage": 50,
	"lvl" : 90,
	"skill_name" : "万岳朝宗",
	"damage_type": "刺伤"
]),
([      "action": "$N手舞$w，剑光闪烁，$w越使越快，突然间转身过来，一声呼喝，刷的一剑，刺向$n$l。这一招「顺水推舟」，正是武当剑法的绝招",
	"force" : 320,
	"dodge" : 0,
	"damage": 55,
	"lvl" : 100,
	"skill_name" : "顺水推舟",
	"damage_type": "刺伤"
]),
([      "action": "$N一声清啸，$w递出，指向$n。一招「手挥五弦」，剑尖嗡嗡连响，自右至左、由上而下的连晃五下，快得异乎寻常",
	"force" : 350,
	"dodge" : 0,
	"damage": 65,
	"lvl" : 110,
	"skill_name" : "手挥五弦",
	"damage_type": "刺伤"
]),
([      "action": "$N$w一起，使一招「百鸟朝凰」，但见剑尖乱颤，霎时间便如化为数十个剑尖，罩住$n中盘，这一招虽然厉害，但仍是彬彬有礼的剑法",
	"force" : 380,
	"dodge" : 10,
	"damage": 75,
	"lvl" : 120,
	"skill_name" : "百鸟朝凰",
	"damage_type": "刺伤"
]),

});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry");}
int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 10)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("force", 1) < 20)
		return notify_fail("你的内功火候太浅。\n");
	if ((int)me->query_skill("unarmed", 1) < 20)
		return notify_fail("你的基本拳脚火候太浅。\n");
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
	level = (int) me->query_skill("wudang-jian",1);
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
	if ((int)me->query("qi") < 20)
		return notify_fail("你的体力不够练武当剑法。\n");
	me->receive_damage("qi", 10);
	return 1;
}

