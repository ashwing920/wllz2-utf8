// qlist1200000.c

inherit SKILL;
#include <ansi.h>

mapping *quest = ({
	([      "quest":                "郭靖",
		"quest_type":           "杀",
		"where":                "扬州",
		"diff":                 4,
	]),
	([      "quest":                "独臂神尼",
		"quest_type":           "杀",
		"where":                "客店",
		"diff":                 4,
	]),
	([      "quest":                "赵半山",
		"quest_type":           "杀",
		"where":                "杭州",
		"diff":                 4,
	]),
	([      "quest":                "陆大有",
		"quest_type":           "杀",
		"where":                "华山派",
		"diff":                 4,
	]),
	([      "quest":                "高根明",
		"quest_type":           "杀",
		"where":                "华山派",
		"diff":                 4,
	]),
	([      "quest":                "劳德诺",
		"quest_type":           "杀",
		"where":                "华山派",
		"diff":                 4,
	]),
	([      "quest":                "梁发",
		"quest_type":           "杀",
		"where":                "华山派",
		"diff":                 4,
	]),
	([      "quest":                "令狐冲",
		"quest_type":           "杀",
		"where":                "华山派",
		"diff":                 4,
	]),
	([      "quest":                HIY"巨蟒"NOR,
		"quest_type":           "杀",
		"where":                "树林",
		"diff":                 4,
	]),
	([      "quest":                "陆柏",
		"quest_type":           "杀",
		"where":                "嵩山派",
		"diff":                 4,
	]),
	([      "quest":                "玉玑子",
		"quest_type":           "杀",
		"where":                "泰山派",
		"diff":                 4,
	]),
	([      "quest":                "玉磬子",
		"quest_type":           "杀",
		"where":                "泰山派",
		"diff":                 4,
	]),
	([      "quest":                "玉音子",
		"quest_type":           "杀",
		"where":                "泰山派",
		"diff":                 4,
	]),
	([      "quest":                "郭靖",
		"quest_type":           "杀",
		"where":                "襄阳城",
		"diff":                 4,
	]),
	([      "quest":                "刘承风",
		"quest_type":           "杀",
		"where":                "血刀门附近",
		"diff":                 4,
	]),
	([      "quest":                "陆天抒",
		"quest_type":           "杀",
		"where":                "血刀门附近",
		"diff":                 4,
	]),
	([      "quest":                "水岱",
		"quest_type":           "杀",
		"where":                "血刀门附近",
		"diff":                 4,
	]),
	([      "quest":                "唐方",
		"quest_type":           "杀",
		"where":                "唐门",
		"diff":                 4,
	]),
	([      "quest":                "唐无火",
		"quest_type":           "杀",
		"where":                "唐门",
		"diff":                 4,
	]),
	([      "quest":                "唐无情",
		"quest_type":           "杀",
		"where":                "唐门",
		"diff":                 4,
	]),
	([      "quest":                "余沧海",
		"quest_type":           "杀",
		"where":                "青城派",
		"diff":                 4,
	]),
	([      "quest":                "玄贞道长",
		"quest_type":           "杀",
		"where":                "云龙门",
		"diff":                 4,
	]),
	([      "quest":                "贡唐仓国师",
		"quest_type":           "杀",
		"where":                "雪山派",
		"diff":                 4,
	]),
	([      "quest":                "灵智上人",
		"quest_type":           "杀",
		"where":                "雪山派",
		"diff":                 4,
	]),
	([      "quest":                "胜谛",
		"quest_type":           "杀",
		"where":                "血刀门",
		"diff":                 4,
	]),
	([      "quest":                "天狼子",
		"quest_type":           "杀",
		"where":                "星宿派",
		"diff":                 4,
	]),
	([      "quest":                "宋青书",
		"quest_type":           "杀",
		"where":                "武当派",
		"diff":                 4,
	]),
	([      "quest":                "黄蓉",
		"quest_type":           "杀",
		"where":                "桃花岛",
		"diff":                 4,
	]),
	([      "quest":                "张淡月",
		"quest_type":           "杀",
		"where":                "神龙教",
		"diff":                 4,
	]),
	([      "quest":                "殷锦",
		"quest_type":           "杀",
		"where":                "神龙教",
		"diff":                 4,
	]),
	([      "quest":                "许雪亭",
		"quest_type":           "杀",
		"where":                "神龙教",
		"diff":                 4,
	]),
	([      "quest":                "无根道长",
		"quest_type":           "杀",
		"where":                "神龙教",
		"diff":                 4,
	]),
});

mapping query_quest()
{
	return quest[random(sizeof(quest))];
}
