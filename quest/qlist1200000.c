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
	([      "quest":                "密宗心经",
		"quest_type":           "找",
		"where":                "雪山寺",
		"diff":                 6,
	]),
	([      "quest":                "风云手手法",
		"quest_type":           "找",
		"where":                "少林寺",
		"diff":                 6,
	]),
	([      "quest":                "鹰爪功法",
		"quest_type":           "找",
		"where":                "少林寺",
		"diff":                 6,
	]),
	([      "quest":                "韦陀棍法",
		"quest_type":           "找",
		"where":                "少林寺",
		"diff":                 6,
	]),
	([      "quest":                "醉棍棍法",
		"quest_type":           "找",
		"where":                "少林寺",
		"diff":                 6,
	]),
	([      "quest":                "普渡杖法",
		"quest_type":           "找",
		"where":                "少林寺",
		"diff":                 6,
	]),
	([      "quest":                "一指禅功",
		"quest_type":           "找",
		"where":                "少林寺",
		"diff":                 6,
	]),
	([      "quest":                "龙爪功法",
		"quest_type":           "找",
		"where":                "少林寺",
		"diff":                 6,
	]),
	([      "quest":                "如来千叶手手法",
		"quest_type":           "找",
		"where":                "少林寺",
		"diff":                 6,
	]),
	([      "quest":                "罗汉拳法",
		"quest_type":           "找",
		"where":                "少林寺",
		"diff":                 6,
	]),
	([      "quest":                HIC"六脉神剑谱"NOR,
		"quest_type":           "找",
		"where":                "天龙寺",
		"diff":                 6,
	]),
	([      "quest":                "金雁图谱",
		"quest_type":           "找",
		"where":                "全真教",
		"diff":                 6,
	]),
	([      "quest":                "十八木偶",
		"quest_type":           "找",
		"where":                "扬州郊外的树林",
		"diff":                 6,
	]),
	([      "quest":                "十八泥偶",
		"quest_type":           "找",
		"where":                "扬州郊外的树林",
		"diff":                 6,
	]),
	([      "quest":                "碧血刀",
		"quest_type":           "找",
		"where":                "血刀门",
		"diff":                 6,
	]),
	([      "quest":                HIB"眼"HIW"儿媚"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIY"落第秀才"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIR"红妆"HIW"素裹"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIW"抓破"HIG"美"NOR"人"HIR"脸"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIW"倚"HIG"栏"HIR"娇"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIR"十八学士"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIG"十三太保"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIB"八仙过海"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIR"七仙女"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                MAG"风"WHT"尘三"HIR"侠"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIR"二"WHT"乔"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIG"八宝妆"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIW"满月"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                HIR"山茶花"NOR,
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
	([      "quest":                "大理雪梨",
		"quest_type":           "找",
		"where":                "大理茶花苑",
		"diff":                 6,
	]),
});
mapping query_quest()
{
	return quest[random(sizeof(quest))];
}
