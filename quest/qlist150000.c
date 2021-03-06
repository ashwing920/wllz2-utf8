// qlist100000.c

inherit SKILL;
#include <ansi.h>

mapping *quest = ({
	([      "quest":                "倭寇",
		"quest_type":           "杀",
		"where":		"泉州港口路",
		"diff":			2,
	]),
	([      "quest":                "日本浪人",
		"quest_type":           "杀",
		"where":		"泉州港口路",
		"diff":			2,
	]),
	([      "quest":                "林震南",
		"quest_type":           "杀",
		"where":		"福威镖局",
		"diff":			2,
	]),
	([      "quest":                "郑镖头",
		"quest_type":           "杀",
		"where":		"福威镖局",
		"diff":			2,
	]),
	([      "quest":                "史镖头",
		"quest_type":           "杀",
		"where":		"福威镖局",
		"diff":			2,
	]),
	([      "quest":                "王夫人",
		"quest_type":           "杀",
		"where":		"福威镖局",
		"diff":			2,
	]),
	([      "quest":                "陈七",
		"quest_type":           "杀",
		"where":		"福威镖局",
		"diff":			2,
	]),
	([      "quest":                "白二",
		"quest_type":           "杀",
		"where":		"福威镖局",
		"diff":			2,
	]),
	([      "quest":                "五香茶叶蛋",
		"quest_type":           "寻",
		"where":		"福州南大街",
		"diff":			2,
	]),
	([      "quest":                "崔镖头",
		"quest_type":           "杀",
		"where":		"福州西门大街",
		"diff":			2,
	]),
	([      "quest":                "水壶",
		"quest_type":           "寻",
		"where":		"福州南大街",
		"diff":			2,
	]),
	([      "quest":                "糟老头",
		"quest_type":           "杀",
		"where":		"桃源东街",
		"diff":			2,
	]),
	([      "quest":                "镖头",
		"quest_type":           "杀",
		"where":		"泉州港口路",
		"diff":			2,
	]),
	([      "quest":                "土匪",
		"quest_type":           "杀",
		"where":		"泉州乱石岗",
		"diff":			2,
	]),
	([      "quest":                HIR"陶老人的头颅"NOR,
		"quest_type":           "寻",
		"where":		"泉州淘然茶居",
		"diff":			2,
	]),
	([      "quest":                "回回",
		"quest_type":           "杀",
		"where":		"泉州清净寺",
		"diff":			2,
	]),
	([      "quest":                "回回",
		"quest_type":           "杀",
		"where":		"泉州清净寺",
		"diff":			2,
	]),
	([      "quest":                "阿拉伯商人",
		"quest_type":           "杀",
		"where":		"泉州阿拉伯宅区",
		"diff":			2,
	]),
	([      "quest":                "土匪头",
		"quest_type":           "杀",
		"where":		"泉州乱石岗",
		"diff":			2,
	]),
	([      "quest":                "欧阳詹",
		"quest_type":           "杀",
		"where":		"泉州学堂",
		"diff":			2,
	]),
	([      "quest":                "施琅",
		"quest_type":           "杀",
		"where":		"泉州将军府",
		"diff":			2,
	]),
	([      "quest":                HIR"胡人的头颅"NOR,
		"quest_type":           "寻",
		"where":		"泉州中心广场",
		"diff":			2,
	]),
	([      "quest":                "陈阿婆",
		"quest_type":           "杀",
		"where":		"泉州杂货铺",
		"diff":			2,
	]),
	([      "quest":                "药铺小厮",
		"quest_type":           "杀",
		"where":		"泉州济世堂老店",
		"diff":			2,
	]),
	([      "quest":                "常金鹏",
		"quest_type":           "杀",
		"where":		"泉州刺桐东路",
		"diff":			2,
	]),
	([      "quest":                "冯正东",
		"quest_type":           "杀",
		"where":		"苏州府衙",
		"diff":			2,
	]),
	([      "quest":                "甄有庆",
		"quest_type":           "杀",
		"where":		"苏州府衙",
		"diff":			2,
	]),
	([      "quest":                "石中玉",
		"quest_type":           "杀",
		"where":		"侠客岛",
		"diff":			2,
	]),
	([      "quest":                "贾人达",
		"quest_type":           "杀",
		"where":		"福州的闽中大道",
		"diff":			2,
	]),
	([      "quest":                "观众丁",
		"quest_type":           "杀",
		"where":		"北京的戏楼",
		"diff":			2,
	]),
	([      "quest":                HIR"丫环的头颅"NOR,
		"quest_type":           "寻",
		"where":		"桃源千金楼",
		"diff":			2,
	]),
	([      "quest":                "仆人",
		"quest_type":           "杀",
		"where":		"桃花山庄的小屋",
		"diff":			2,
	]),
	([      "quest":                "船夫",
		"quest_type":           "杀",
		"where":		"码头",
		"diff":			2,
	]),
	([      "quest":                HIY"黄玫瑰"NOR,
		"quest_type":           "寻",
		"where":		"桃源花店",
		"diff":			2,
	]),
	([      "quest":                HIW"白茶花"NOR,
		"quest_type":           "寻",
		"where":		"桃源花店",
		"diff":			2,
	]),
	([      "quest":                HIB"蓝天鹅"NOR,
		"quest_type":           "寻",
		"where":		"桃源花店",
		"diff":			2,
	]),
	([      "quest":                HIR"红玫瑰"NOR,
		"quest_type":           "寻",
		"where":		"桃源花店",
		"diff":			2,
	]),
	([      "quest":                BLU"黑牡丹"NOR,
		"quest_type":           "寻",
		"where":		"桃源花店",
		"diff":			2,
	]),
	([      "quest":                HIM"紫罗兰"NOR,
		"quest_type":           "寻",
		"where":		"桃源花店",
		"diff":			2,
	]),
	([      "quest":                HIC"化尸粉"NOR,
		"quest_type":           "寻",
		"where":		"药店",
		"diff":			2,
	]),
	([      "quest":                "长剑",
		"quest_type":           "寻",
		"where":		"兵器铺",
		"diff":			2,
	]),
	([      "quest":                "珠宝店老板",
		"quest_type":           "杀",
		"where":		"桃源珠宝店",
		"diff":			2,
	]),
	([      "quest":                "姨太太",
		"quest_type":           "杀",
		"where":		"桃源胭脂店",
		"diff":			2,
	]),
	([      "quest":                "教书先生",
		"quest_type":           "杀",
		"where":		"圣贤书屋",
		"diff":			2,
	]),
	([      "quest":                "花店老板",
		"quest_type":           "杀",
		"where":		"桃源花店",
		"diff":			2,
	]),
	([      "quest":                "王掌柜",
		"quest_type":           "杀",
		"where":		"桃源棋社",
		"diff":			2,
	]),
	([      "quest":                "超渡禅师",
		"quest_type":           "杀",
		"where":		"桃源超度法场",
		"diff":			2,
	]),
	([      "quest":                "卖花姑娘",
		"quest_type":           "杀",
		"where":		"北京西长安街头",
		"diff":			2,
	]),
	([      "quest":                "匕首",
		"quest_type":           "寻",
		"where":		"兵器铺",
		"diff":			2,
	]),
	([      "quest":                "杨永福",
		"quest_type":           "杀",
		"where":		"扬州杂货店",
		"diff":			2,
	]),
	([      "quest":                "挑夫",
		"quest_type":           "杀",
		"where":		"扬州以东的大驿道",
		"diff":			2,
	]),
	([      "quest":                "船夫",
		"quest_type":           "杀",
		"where":		"码头",
		"diff":			2,
	]),
});
mapping query_quest()
{
	return quest[random(sizeof(quest))];
}
