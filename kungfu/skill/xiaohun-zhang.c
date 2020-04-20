// xiaohun-zhang.c - 黯然销魂掌
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「杞人忧天」抬头向天，浑若不见，呼的一掌向自己头顶空空拍出，手掌斜下，\n掌力化成弧形，四散落下拍向$n的$l。",
	"force"         : 160,
	"dodge"         : 10,
	"parry"         : 10,
	"lvl"           : 0,
	"skill_name"    : "杞人忧天",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「无中生有」手臂下垂，绝无半点防御姿式，突然间手足齐动，左掌右袖、\n双足头锤、连得胸背腰腹尽皆有招式发出撞向$n.",
	"force"         : 180,
	"dodge"         : 20,
	"parry"         : 20,
	"lvl"           : 10,
	"skill_name"    : "无中生有",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「拖泥带水」右手云袖飘动，宛若流水，左掌却重滞之极，\n便似带着几千斤泥沙一般，左右齐攻$n。",
	"force"         : 200,
	"dodge"         : 30,
	"parry"         : 30,
	"lvl"           : 20,
	"skill_name"    : "拖泥带水",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「力不从心」含胸收腹，头缓缓低下，脚步沉重的迈向$n，右掌软绵绵的拍向$n的$l。",
	"force"         : 220,
	"dodge"         : 40,
	"parry"         : 40,
	"lvl"           : 30,
	"skill_name"    : "力不从心",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「行尸走肉」踢出一脚。这一脚发出时恍恍惚惚，隐隐约约，若有若无的踢向$n",
	"force"         : 240,
	"dodge"         : 50,
	"parry"         : 50,
	"lvl"           : 40,
	"skill_name"    : "行尸走肉",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N双掌平托，一招「庸人自扰」没精打采的拍向$n的$l.",
	"force"         : 260,
	"dodge"         : 60,
	"parry"         : 60,
	"lvl"           : 50,
	"skill_name"    : "庸人自扰",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「倒行逆施」突然纵起丈余，头下脚上，倒过身子，一掌拍向$n的$l",
	"force"         : 280,
	"dodge"         : 70,
	"parry"         : 70,
	"lvl"           : 60,
	"skill_name"    : "倒行逆施",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「心惊肉跳」凝目远眺，脚下虚浮，胸前门户洞开，全身姿式与武学中各项大忌无不吻合。",
	"force"         : 300,
	"dodge"         : 80,
	"parry"         : 80,
	"lvl"           : 70,
	"skill_name"    : "心惊肉跳",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「废寝忘食」脚下虚浮，有如几天不吃不睡后的脚步朗舱的袭到$n的身旁，左掌右拳攻向$n的$l。",
	"force"         : 350,
	"dodge"         : 90,
	"parry"         : 90,
	"lvl"           : 80,
	"skill_name"    : "废寝忘食",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「徘徊空谷」左攻右打，虚虚实实的攻向$n的$l。",
	"force"         : 400,
	"dodge"         : 100,
	"parry"         : 120,
	"lvl"           : 100,
	"skill_name"    : "徘徊空谷",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「饮恨吞声」左手做饮酒状，右掌斜斜劈向$n的$l。",
	"force"         : 420,
	"dodge"         : 110,
	"parry"         : 130,
	"lvl"           : 140,
	"skill_name"    : "饮恨吞声",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「六神不安」身如陀螺急转，展开轻功围着$n快速游走，忽然飞身而起，拍向$n的$l。",
	"force"         : 430,
	"dodge"         : 120,
	"parry"         : 130,
	"lvl"           : 180,
	"skill_name"    : "六神不安",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「穷途末路」闪身到$n身旁，左掌举到胸前平推而出，接着右掌斜斜劈向$n的$l。",
	"force"         : 450,
	"dodge"         : 130,
	"parry"         : 140,
	"lvl"           : 240,
	"skill_name"    : "穷途末路",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「呆若木鸡」双目直直的盯着$n，身体动也不动一下的飞向$n",
	"force"         : 470,
	"dodge"         : 140,
	"parry"         : 150,
	"lvl"           : 280,
	"skill_name"    : "呆若木鸡",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N低头冥想，一招「若有所失」右掌向外平平推向$n的$l。",
	"force"         : 490,
	"dodge"         : 160,
	"parry"         : 180,
	"lvl"           : 300,
	"skill_name"    : "若有所失",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N一招「四通八达」双掌晃出千万掌影将$n笼罩在掌力之下。",
	"force"         : 500,
	"dodge"         : 170,
	"parry"         : 190,
	"lvl"           : 320,
	"skill_name"    : "四通八达",
	"damage_type"   : "瘀伤"
]),
([      "action" : "$N错步上前，一招「鹿死谁手」招招抢先，以快打慢，一个转身已经转到了$n的身后，\n运指如风点向$n的大椎穴。",
	"force"         : 550,
	"dodge"         : 190,
	"parry"         : 200,
	"lvl"           : 350,
	"skill_name"    : "鹿死谁手",
	"damage_type"   : "瘀伤"
]),
});

int valid_enable(string usage) { return (usage  == "unarmed") || (usage == "parry") || (usage == "strike") ; }

int valid_learn(object me)
{
	if (me->query("gender") != "男性")
		return notify_fail("只有男性才可以学习这种武功。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然销魂掌必须空手。\n");
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
	int i, j, level;

	level = (int) me->query_skill("xiaohun-zhang",1);
	for(i = sizeof(action); i > 0; i--) {
	if(level > action[i-1]["lvl"]) {
		j = NewRandom(i, 20, level/5);
		if (me->query_temp("anran") && me->query("jiali") >= 50 ) {
			return ([
				"action" : HIY+action[j]["action"]+NOR,
				"force" : level*3,
				"dodge":action[j]["dodge"]+5,
				"damage": level*4,
				"lvl" : action[j]["lvl"],
				"weapon" : random(2)?"黯然掌掌风":"黯然掌掌力",
				"damage_type" : random(2)?"瘀伤":"割伤",
			]);
		}
		if (level >= 130 && random(6) > 4 && me->query("jiali") >= 50 ) {
			return ([
				"action" : action[j]["action"],
				"force" : level*2,
				"dodge":action[j]["dodge"],
				"damage": level*2,
				"lvl" : action[j]["lvl"],
				"weapon" : random(2)?"掌风":"黯然掌力",
				"damage_type" : "割伤",
			]);
		}
			return action[j];
		}
	}
}

int practice_skill(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然销魂掌必须空手。\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("你的体力不够练黯然销魂掌。\n");
	me->receive_damage("qi", 35);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"xiaohun-zhang/" + action;
}
