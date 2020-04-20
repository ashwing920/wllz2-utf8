// gqlist.c

#include <ansi.h>

inherit F_SKILL;

mapping *quest = ({
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/huru",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/shanlu1",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/shanlu2",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/qzroad1",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/qzroad2",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/hjting",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/kaojiao",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/bangbu",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/gangkou2",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/jishi",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/luanshi",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/guanchaidian",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/dufu",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/luanshi",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/nanhu",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/qzkedian",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/ruixiang",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/tumen",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/shanlu6",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/qianshou",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/qzkedian3",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/wgdamen",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/zhongxin",
		"diff":                 7,
	]),
	([
		"quest_type":           "拿",
		"where":                "泉州",
		"path":                 "/d/quanzhou/yuetai",
		"diff":                 7,
	]),

});
mapping query_quest()
{
	return quest[random(sizeof(quest))];
}
