// gqlist.c

#include <ansi.h>

inherit F_SKILL;

mapping *quest = ({
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/baiti",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/baoshishan",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/chashi",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/dalu1",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/fajingsi",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/fangheting",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/huagang",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/jingci",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/kedian",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/duanqiao",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/longhongdong",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/qiantang",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/road1",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/road2",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/road10",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/shanlu5",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/shuiledong",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/tianwangdian",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/tiejiangpu",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/xilingqiao",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/yaodian",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/yuefen",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/yuelang",
		"diff":                 7,
	]),
	([
		"where":                "杭州",
		"path":                 "/d/hangzhou/suti1",
		"diff":                 7,
	]),

});
mapping query_quest()
{
	return quest[random(sizeof(quest))];
}
