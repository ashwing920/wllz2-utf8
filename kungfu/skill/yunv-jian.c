// yunv-jian.c 玉女素心剑

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「雁行斜击」，身形斜飞，手中$w轻轻点向$n的$l",
        "force" : 80,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 80,
        "lvl" : 0,
        "skill_name":"雁行斜击",
        "damage_type" : "刺伤"
]),
([      "action" : "$N长跃而起，「白虹经天」，$w猛然下刺",
        "force" : 90,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 90,
        "lvl" : 8,
        "skill_name":"白虹惊天",
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「浪迹天涯」，挥剑直劈，威不可当",
        "force" : 100,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 100,
        "lvl" : 20,
        "skill_name":"浪迹天涯",
        "damage_type" : "内伤"
]),
([      "action" : "$N使「花前月下」一招自上而下搏击，模拟冰轮横空、清光铺地的光景",
        "force" : 120,
        "dodge" : 15,
        "parry" : 10,
        "damage" : 120,
        "lvl" : 40,
        "skill_name":"花前月下",
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w颤动，如鲜花招展来回挥削，只幌得$n眼花撩乱，浑不知从何攻来",
        "force" : 140,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 140,
        "lvl" : 60,
        "skill_name":"来去何从",
        "damage_type" : "内伤"
]),
([      "action" : "$N使出「清饮小酌」剑柄提起，剑尖下指，有如提壶斟酒，直挥$n的$l",
        "force" : 160,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 160,
        "lvl" : 80,
        "skill_name":"清饮小酌",
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w由内自外一刺，左手如斟茶壶，使出「扫雪烹茶」来",
        "force" : 180,
        "dodge" : 10,
        "parry" : 15,
        "damage" : 180,
        "lvl" : 120,
        "skill_name":"扫雪煮茶",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左掌横摆胸前，右手中$w轻轻挥拂，却是一招「抚琴按萧」",
        "force" : 190,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 190,
        "lvl" : 140,
        "skill_name":"抚琴按箫",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「松下对弈」，$w自右向左挥一个大弧，刺向$n的$l",
        "force" : 200,
        "dodge" : 15,
        "parry" : 15,
        "damage" : 200,
        "lvl" : 180,
        "skill_name":"松下对弈",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手如拂五弦，竟以掌为剑攻向$n，却是一招「池边调鹤」",
        "force" : 220,
        "dodge" : 10,
        "parry" : 20,
        "damage" : 220,
        "lvl" : 200,
        "skill_name":"池边调鹤",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「柳絮风飘」，$w轻灵地划出几个圆弧，向$n的$l挥去",
        "force" : 230,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 230,
        "lvl" : 220,
        "skill_name":"柳絮风飘",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「小园艺菊」，手中$w迅疾向$n的下盘连点三点",
        "force" : 240,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 240,
        "lvl" : 130,
        "skill_name":"小园艺菊",
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「西窗夜话」，手中$w中宫直入，攻向$n的$l",
        "force" : 250,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 250,
        "lvl" : 240,
        "skill_name":"西窗夜话",
        "damage_type" : "刺伤"
]),
([      "action" : "$N脚下左高右低，一招「柳荫联句」，$w在空中化成一道光环，急攻$n",
        "force" : 270,
        "dodge" : 5,
        "parry" : 20,
        "damage" : 270,
        "lvl" : 230,
        "skill_name":"柳荫联句",
        "damage_type" : "内伤"
]),
([      "action" : "$N手中$w由下而上卷起，犹如打起竹帘一般，却是「竹帘临池」",
        "force" : 290,
        "dodge" : 15,
        "parry" : 20,
        "damage" : 290,
        "lvl" : 250,
        "skill_name":"竹帘临池",
        "damage_type" : "刺伤"
]),
([      "action" : "$N做搭弓射箭状，一招「木兰射雁」，右手$w直刺$n的$l",
        "force" : 310,
        "dodge" : 20,
        "parry" : 20,
        "damage" : 310,
        "lvl" : 260,
        "skill_name":"木兰射雁",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手剑诀一领，右手$w平平刺向$n的$l，是一招「双蝶迷回」",
        "force" : 315,
        "dodge" : 40,
        "parry" : 20,
        "damage" : 315,
        "lvl" : 280,
        "skill_name":"双蝶迷回",
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中$w合身疾刺，一招「孤云出釉」，直指$n的$l",
        "force" : 320,
        "dodge" : 30,
        "parry" : 20,
        "damage" : 320,
        "lvl" : 290,
        "skill_name":"孤云出釉",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「幽兰空谷」，$w看似随意地一挥，从$n不可思议的角度攻入",
        "force" : 330,
        "dodge" : 20,
        "parry" : 25,
        "damage" : 330,
        "lvl" : 300,
        "skill_name":"幽兰空谷",
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「茶花满路」，一时间空中尽是$w的影子，令$n不知如何抵挡",
        "force" : 340,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 340,
        "lvl" : 310,
        "skill_name":"茶花满路",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「陌路采桑」，$w连点数点，疾刺$n的$l",
        "force" : 345,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 345,
        "lvl" : 320,
        "skill_name":"陌路采桑",
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然盘蹲下来，一招「秋雨萧萧」，$w自下而上刺向$n",
        "force" : 350,
        "dodge" : 25,
        "parry" : 25,
        "damage" : 350,
        "lvl" : 330,
        "skill_name":"秋雨萧萧",
        "damage_type" : "刺伤"
]),
([      "action" : "$N错开脚步，手中$w突然从自己的肋下刺出，却是一招「琴心剑胆」",
        "force" : 355,
        "dodge" : 35,
        "parry" : 25,
        "damage" : 355,
        "lvl" : 340,
        "skill_name":"琴心剑胆",
        "damage_type" : "刺伤"
]),
([      "action" : "$N犹如在水面滑行一般，一招「池塘秋夜」，平平地向$n的$l挥去",
        "force" : 360,
        "dodge" : 40,
        "parry" : 25,
        "damage" : 360,
        "lvl" : 350,
        "skill_name":"池塘秋夜",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「皓腕玉镯」，手中$w刺点$n的手腕",
        "force" : 365,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 365,
        "lvl" : 360,
        "skill_name":"皓腕玉镯",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「牡丹含泪」，$w绕出数个银圈，平平地向$n的$l卷去",
        "force" : 370,
        "dodge" : 45,
        "parry" : 25,
        "damage" : 370,
        "lvl" : 370,
        "skill_name":"牡丹含泪",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左脚轻点地面，身形往前一扑，一招「芍药蕴珠」，$w向$n的$l刺去",
        "force" : 380,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 380,
        "lvl" : 380,
        "skill_name":"芍药蕴珠",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「檐前飞燕」，身形跃起，手中$w扫向$n的$l",
        "force" : 390,
        "dodge" : 45,
        "parry" : 30,
        "damage" : 390,
        "lvl" : 390,
        "skill_name":"檐前飞燕",
        "damage_type" : "刺伤"
]),

([      "action" : "$N脸现黯然之色，随意一招「蒹葭苍苍」，$w刺向$n的$l",
        "force" : 400,
        "dodge" : 35,
        "parry" : 30,
        "damage" : 400,
        "lvl" : 400,
        "skill_name":"蒹葭苍苍",
        "damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }
int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 15)
                return notify_fail("你的基本内功火候不到，无法学习玉女素心剑。\n");
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
        level   = (int) me->query_skill("yunv-jian",1);
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
        if ((int)me->query("qi") < 45)
                return notify_fail("你的体力不够练玉女素心剑。\n");
        if ((int)me->query("neili") < 15)
                return notify_fail("你的内力不足以练玉女素心剑。\n");
        me->receive_damage("qi", 26);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yunv-jian/" + action;
}
