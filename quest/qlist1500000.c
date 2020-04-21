// qlist1200000.c

inherit SKILL;
#include <ansi.h>

mapping *quest = ({
	([      "quest":                "胡庆余",
		"quest_type":           "杀",
		"where":                "杭州药店",
		"diff":                 6,
	]),
	([      "quest":                HIB"狼王"NOR,
		"quest_type":           "杀",
		"where":                "黑木崖",
		"diff":                 6,
	]),
	([      "quest":                "定静师太",
		"quest_type":           "杀",
		"where":                "恒山派",
		"diff":                 6,
	]),
	([      "quest":                "定逸师太",
		"quest_type":           "杀",
		"where":                "恒山派",
		"diff":                 6,
	]),
	([      "quest":                "刘正风",
		"quest_type":           "杀",
		"where":                "衡山派",
		"diff":                 6,
	]),
	([      "quest":                "陈玄风",
		"quest_type":           "杀",
		"where":                "黄河",
		"diff":                 6,
	]),
	([      "quest":                "梅超风",
		"quest_type":           "杀",
		"where":                "桃花岛",
		"diff":                 6,
	]),
	([      "quest":                "乌老大",
		"quest_type":           "杀",
		"where":                "灵鹫宫",
		"diff":                 6,
	]),
	([      "quest":                "余婆婆",
		"quest_type":           "杀",
		"where":                "灵鹫宫",
		"diff":                 6,
	]),
	([      "quest":                "黑白子",
		"quest_type":           "杀",
		"where":                "梅庄",
		"diff":                 6,
	]),
	([      "quest":                "秃笔翁",
		"quest_type":           "杀",
		"where":                "梅庄",
		"diff":                 6,
	]),
	([      "quest":                "噬人鱼",
		"quest_type":           "杀",
		"where":                "河底",
		"diff":                 6,
	]),
	([      "quest":                "老船夫",
		"quest_type":           "杀",
		"where":                "神龙教",
		"diff":                 6,
	]),
	([      "quest":                "周伯通",
		"quest_type":           "杀",
		"where":                "桃花岛",
		"diff":                 6,
	]),
	([      "quest":                "黄眉大师",
		"quest_type":           "杀",
		"where":                "万劫谷",
		"diff":                 6,
	]),
	([      "quest":                RED"赤冠巨蟒"NOR,
		"quest_type":           "杀",
		"where":                "武当山",
		"diff":                 6,
	]),
	([      "quest":                "石破天",
		"quest_type":           "杀",
		"where":                "侠客岛",
		"diff":                 6,
	]),
});
mapping query_quest()
{
	return quest[random(sizeof(quest))];
}