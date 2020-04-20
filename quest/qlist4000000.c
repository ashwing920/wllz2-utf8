// gqlist.c

#include <ansi.h>

inherit F_SKILL;

mapping *quest = ({
	([
		"where":                "成都",
		"path":                 "/d/city3/bingqidian",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/caotang",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/eastroad1",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/liubeidian",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/nanheqiaow",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/northroad2",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/path1",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/qingyanggong",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/shuduroad1",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/shuduroad2",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/southroad1",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/southroad3",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/wangjianglou",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/westgate",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/jiudian",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/wuguan",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/wuguanchen",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/wuguanlong",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/wuhoucigate",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/fuheqiaoe",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/guangchang",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/northroad1",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/qingyanggong",
		"diff":                 6,
	]),
	([
		"where":                "成都",
		"path":                 "/d/city3/tidufu",
		"diff":                 6,
	]),

});
mapping query_quest()
{
	return quest[random(sizeof(quest))];
}
