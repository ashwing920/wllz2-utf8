

inherit F_SKILL;

mapping *quest = ({
	([
		"where":                "武当山下小吃店",
		"path":                 "/d/wudang/shop",
	]),
	([
		"where":                "少林山下山坡",
		"path":                 "/d/shaolin/xiaojing1",
	]),
	([
		"where":                "泰山升仙坊",
		"path":                 "/d/taishan/shengxian",
	]),
	([
		"where":                "华山金锁关",
		"path":                 "/d/huashan/jinsuo",
	]),
	([
		"where":                "昆明近日古楼",
		"path":                 "/d/kunming/jinrilou",
	]),
	([
		"where":                "大理茶花山",
		"path":                 "/d/dali/chahuashan1",
	]),
	([
		"where":                "苏州春在楼",
		"path":                 "/d/suzhou/jiudian",
	]),
	([
		"where":                "蜀都广场",
		"path":                 "/d/city3/guangchang",
	]),
	([
		"where":                "泉州茶亭",
		"path":                 "/d/quanzhou/chating",
	]),
	([
		"where":                "相记钱庄",
		"path":                 "/d/city4/bank",
	]),
	([
		"where":                "杭州聚景园",
		"path":                 "/d/hangzhou/jujingyuan",
	]),
	([
		"where":                "北京西门外",
		"path":                 "/d/city2/ximenwai",
	]),
	([
		"where":                "天山脚下",
		"path":                 "/d/xingxiu/shanjiao",
	]),
	([
		"where":                "灵州大将军府",
		"path":                 "/d/lingzhou/jiangjungate",
	]),
	([
		"where":                "襄阳大校场",
		"path":                 "/d/xiangyang/dajiaochang",
	]),
	([
		"where":                "华山苍龙岭",
		"path":                 "/d/huashan/canglong",
	]),
	([
		"where":		"嘉峪关",
		"path":			"/d/xingxiu/jiayuguan",
	]),
	([
		"where":		"佛山英雄楼",
		"path":			"/d/foshan/yingxionglou",
	]),
});
mapping query_quest()
{
	return quest[random(sizeof(quest))];
}