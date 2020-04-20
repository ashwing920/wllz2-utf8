// gqlist.c

inherit F_CLEAN_UP;

mapping *quest = ({
	([
		"quest_type":           "抓",
		"where":                "刑部大门",
		"path":                 "/d/xingbu/gate",
	]),

/*
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "北京城",
		"path":                 "/d/city2/nandaj1",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "北京塘沽口",
		"path":                 "/d/city2/haigang",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "扬州西大街",
		"path":                 "/d/city/xidajie1",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "扬州东大街",
		"path":                 "/d/city/dongdajie2",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "扬州西门",
		"path":                 "/d/city/ximen",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "北京城地安门",
		"path":                 "/d/city2/di_an2",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "扬州广场",
		"path":                 "/d/city/guangchang",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "青城山路",
		"path":                 "/d/qingcheng/path2",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "忘忧谷",
		"path":                 "/d/xuedao/wangyougu",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "大雪山山谷",
		"path":                 "/d/xuedao/sroad8",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "北京城永定门",
		"path":                 "/d/city2/yongding",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "终南山口",
		"path":                 "/d/city4/zhongnan",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "泰山脚下",
		"path":                 "/d/taishan/taishanjiao",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "武功镇碎石路",
		"path":                 "/d/village/eroad1",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "武功镇小巷",
		"path":                 "/d/village/alley1",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "黄河帮寨门",
		"path":                 "/d/huanghe/huanghegate",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "桃源城外十里亭",
		"path":                 "/d/shaolin/roadw",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "扬州南大街",
		"path":                 "/d/city/nandajie2",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "桃源西码头",
		"path":                 "/d/center/roadw5",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "成都南大街",
		"path":                 "/d/city3/southroad1",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "嘉兴城",
		"path":                 "/d/quanzhou/jiaxing",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "北京南大街",
		"path":                 "/d/city2/nandaj1",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "苏州东大街",
		"path":                 "/d/suzhou/dongdajie2",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "泰山天街",
		"path":                 "/d/taishan/tianjie",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "桃源不夜舫",
		"path":                 "/d/center/buyefang/main-02",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
	([
		"sourse":		"/clone/npc/yifan",
		"quest_type":           "抓",
		"where":                "桃源城南大街",
		"path":                 "/d/center/roads4",
		"diff":                 4,
		"score":		1,
		"from":			"官府",
		"exp_bonus":		45 + random(20),
		"pot_bonus":		55 + random(30),
	]),
*/
});
mapping query_quest()
{
	return quest[random(sizeof(quest))];
}
