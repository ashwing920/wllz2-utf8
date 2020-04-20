// qlist300000.c
#include <ansi.h>
inherit SKILL;

mapping *quest = ({
	([      "quest":                "马夫人",
		"quest_type":           "杀",
		"where":                "桃源城",
		"diff":                 3,
	]),
	([      "quest":                "艳艳",
		"quest_type":           "杀",
		"where":                "千金楼",
		"diff":                 3,
	]),
	([      "quest":                "宋承琳",
		"quest_type":           "杀",
		"where":                "千金楼",
		"diff":                 3,
	]),
	([      "quest":                "龟奴",
		"quest_type":           "杀",
		"where":                "千金楼",
		"diff":                 3,
	]),
	([      "quest":                "春红",
		"quest_type":           "杀",
		"where":                "千金楼",
		"diff":                 3,
	]),
	([      "quest":                "夏红",
		"quest_type":           "杀",
		"where":                "千金楼",
		"diff":                 3,
	]),
	([      "quest":                "冬红",
		"quest_type":           "杀",
		"where":                "千金楼",
		"diff":                 3,
	]),
	([      "quest":                "妓女",
		"quest_type":           "杀",
		"where":                "千金楼",
		"diff":                 3,
	]),
	([      "quest":                "陪酒女郎",
		"quest_type":           "杀",
		"where":                "千金楼",
		"diff":                 3,
	]),
	([      "quest":                "刀僧",
		"quest_type":           "杀",
		"where":		"侠客岛",
		"diff":			3,
	]),
	([      "quest":                "文音小师太",
		"quest_type":           "杀",
		"where":		"峨嵋山",
		"diff":			3,
	]),
	([      "quest":                "冯默风",
		"quest_type":           "杀",
		"where":		"桃花岛",
		"diff":			3,
	]),
	([      "quest":                "陆乘风",
		"quest_type":           "杀",
		"where":		"归云山庄",
		"diff":			3,
	]),
	([      "quest":                "梁发",
		"quest_type":           "杀",
		"where":		"华山",
		"diff":			3,
	]),
	([      "quest":                "施戴子",
		"quest_type":           "杀",
		"where":		"华山",
		"diff":			3,
	]),
	([      "quest":                "高根明",
		"quest_type":           "杀",
		"where":		"华山",
		"diff":			3,
	]),
	([      "quest":                "岳灵珊",
		"quest_type":           "杀",
		"where":		"华山",
		"diff":			3,
	]),
	([      "quest":                "谷虚道长",
		"quest_type":           "杀",
		"where":		"武当山",
		"diff":			3,
	]),
	([      "quest":                "护院",
		"quest_type":           "杀",
		"where":		"梅庄",
		"diff":			3,
	]),
	([      "quest":                "韩宝驹",
		"quest_type":           "杀",
		"where":		"襄阳城",
		"diff":			3,
	]),
	([      "quest":                "南希仁",
		"quest_type":           "杀",
		"where":		"归云山庄",
		"diff":			3,
	]),
	([      "quest":                "杨成协",
		"quest_type":           "杀",
		"where":		"杭州",
		"diff":			3,
	]),
	([      "quest":                "龙骏",
		"quest_type":           "杀",
		"where":		"杭州",
		"diff":			3,
	]),
	([      "quest":                "米为义",
		"quest_type":           "杀",
		"where":		"恒山",
		"diff":			3,
	]),
	([      "quest":                "田伯光",
		"quest_type":           "杀",
		"where":		"华山云台",
		"diff":			3,
	]),
	([      "quest":                "向大年",
		"quest_type":           "杀",
		"where":		"恒山",
		"diff":			3,
	]),
	([      "quest":                "叶二娘",
		"quest_type":           "杀",
		"where":		"灵州",
		"diff":			3,
	]),
	([      "quest":                "万大平",
		"quest_type":           "杀",
		"where":		"嵩山",
		"diff":			3,
	]),
	([      "quest":                "丹青生",
		"quest_type":           "杀",
		"where":		"梅庄",
		"diff":			3,
	]),
	([      "quest":                "仪和",
		"quest_type":           "杀",
		"where":		"恒山",
		"diff":			3,
	]),
	([      "quest":                "施令威",
		"quest_type":           "杀",
		"where":		"梅庄",
		"diff":			3,
	]),
	([      "quest":                "仪质",
		"quest_type":           "杀",
		"where":		"恒山",
		"diff":			3,
	]),
	([      "quest":                "仪文",
		"quest_type":           "杀",
		"where":		"恒山",
		"diff":			3,
	]),
	([      "quest":                "黄真",
		"quest_type":           "杀",
		"where":		"襄阳",
		"diff":			3,
	]),
	([      "quest":                "陈有德",
		"quest_type":           "杀",
		"where":		"扬州武馆",
		"diff":			3,
	]),
	([      "quest":                "花铁干",
		"quest_type":           "杀",
		"where":		"血刀门",
		"diff":			3,
	]),
	([      "quest":                "顾炎武",
		"quest_type":           "杀",
		"where":		"北京城内",
		"diff":			3,
	]),
	([      "quest":                "水岱",
		"quest_type":           "杀",
		"where":		"血刀门",
		"diff":			3,
	]),
	([      "quest":                "刘虹瑛",
		"quest_type":           "杀",
		"where":		"成都",
		"diff":			3,
	]),
	([      "quest":                "龙铨",
		"quest_type":           "杀",
		"where":		"成都",
		"diff":			3,
	]),
	([      "quest":                "马五德",
		"quest_type":           "杀",
		"where":		"金牛武馆",
		"diff":			3,
	]),
	([      "quest":                "玉萧",
		"quest_type":           "寻",
		"where":		"桃花山庄",
		"diff":			3,
	]),
});

mapping query_quest()
{
	return quest[random(sizeof(quest))];
}
