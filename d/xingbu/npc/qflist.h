// list for gao_yingming

string *arrest_path = ({
	"/d/city2/nandaj1",
	"/d/city2/haigang",
	"/d/city/xidajie1",
	"/d/city/dongdajie2",
	"/d/city/ximen",
	"/d/city2/di_an2",
	"/d/city/guangchang",
	"/d/qingcheng/path2",
	"/d/xuedao/wangyougu",
	"/d/xuedao/sroad8",
	"/d/city2/yongding",
	"/d/fuzhou/fzroad1",
	"/d/taishan/taishanjiao",
	"/d/village/eroad1",
	"/d/village/alley1",
	"/d/emei/shenshuian",
	"/d/city/nandajie2",
	"/d/center/roadw5",
	"/d/city3/southroad1",
	"/d/suzhou/dongdajie2",
	"/d/taishan/tianjie",
	"/d/center/buyefang/main-02",
	"/d/center/roads4",
});
string *kill_path=({
	"/d/city2/nandaj1",
	"/d/city2/haigang",
	"/d/city/xidajie1",
	"/d/city/dongdajie2",
	"/d/city/ximen",
	"/d/city2/di_an2",
	"/d/city/guangchang",
	"/d/qingcheng/path2",
	"/d/xuedao/wangyougu",
	"/d/xuedao/sroad8",
	"/d/city2/yongding",
	"/d/fuzhou/fzroad1",
	"/d/taishan/taishanjiao",
	"/d/village/eroad1",
	"/d/village/alley1",
	"/d/emei/shenshuian",
	"/d/city/nandajie2",
	"/d/center/roadw5",
	"/d/city3/southroad1",
	"/d/suzhou/dongdajie2",
	"/d/taishan/tianjie",
	"/d/center/buyefang/main-02",
	"/d/center/roads4",
	"/d/guanwai/damen",
	"/d/city2/di_anmen",
	"/d/hangzhou/shanlu8",
	"/d/city2/nandaj2",
	"/d/fuzhou/fzroad1",
	"/d/dali/xiaodao1",
	"/d/dali/heilongling",
	"/d/city2/xisi2",
	"/d/xiangyang/walle7",
	"/d/dali/shanlu7",
	"/d/xiangyang/walln8",
	"/d/dali/luwang",
	"/d/dali/zhenxiong",
	"/d/city3/northroad1",
	"/d/city2/zhulin1",
	"/d/suzhou/nandajie1",
	"/d/fuzhou/yushan",
	"/d/emei/lianhuashi",
	"/d/suzhou/road1",
	"/d/lingzhou/luorilin2",
	"/d/lingzhou/dawu",
	"/d/foshan/road3",
	"/d/suzhou/dongmen",
	"/d/suzhou/bingying",
	"/d/huanghe/huangtu",
	"/d/huanghe/wuwei",
	"/d/kunming/yunnan",
	"/d/kunming/wangfu",
	"/d/qingcheng/sandaoshi",
	"/d/city4/road4",
	"/d/wanjiegu/port",
	"/d/xiangyang/westjie1",
	"/d/dali/road3",
	"/d/city4/road1",
	"/d/city2/yongding",
	"/d/city/dongdajie2",
	"/d/city2/yongding",
	"/d/hangzhou/yuquan",
	"/d/village/eroad1",
	"/d/village/alley1",
	"/d/dali/feilihusouth",
	"/d/guanwai/nancheng",
	"/d/city/nandajie2",
	"/d/xiangyang/wallw3",
	"/d/city3/southroad1",
	"/d/xiangyang/walls6",
	"/d/lingzhou/jiuguan",
	"/d/hangzhou/pinghuqiuyue",
	"/d/dali/yanan2",
	"/d/taishan/tianjie",
	"/d/center/buyefang/main-02",
	"/d/center/qishe",
	"/d/center/roads4",
	"/d/lingzhou/baxian",
});
string query_city(string filename)
{
	string city_name;
	int len;
	len=strlen(filename);
	len--;
	while(filename[len]!='/' && len>0) {
		len--;
	}
	city_name = filename[1..(len-1)];
	switch(city_name){
		case "d/baituo": return "白驼山";
		case "d/center": return "桃源";
		case "d/city": return "扬州";
		case "d/city2": return "北京";
		case "d/city3": return "成都";
		case "d/city4": return "长安城";
		case "d/dali": return "大理";
		case "d/emei": return "峨嵋山";
		case "d/foshan": return "佛山";
		case "d/fuzhou": return "福州";
		case "d/guanwai": return "关外";
		case "d/guiyun": return "归云庄";
		case "d/gumu": return "古墓新派";
		case "d/hangzhou": return "杭州";
		case "d/heimuya": return "黑木崖";
		case "d/hengshan": return "恒山派";
		case "d/henshan": return "衡阳";
		case "d/huanggon": return "皇宫";
		case "d/huanghe": return "黄河";
		case "d/huashan": return "华山";
		case "d/kunlun": return "昆仑山";
		case "d/kunming": return "昆明";
		case "d/lingjiu": return "灵鹫宫";
		case "d/lingzhou": return "灵州";
		case "d/meizhuang": return "梅庄";
		case "d/mingjiao": return "明教";
		case "d/qianjinlou": return "千金楼";
		case "d/qingcheng": return "青城山";
		case "d/quanzhen": return "全真教";
		case "d/quanzhou": return "泉州";
		case "d/shaolin": return "少林寺";
		case "d/shenlong": return "神龙教";
		case "d/songshan": return "嵩山";
		case "d/suzhou": return "苏州";
		case "d/taishan": return "泰山";
		case "d/tangmen": return "唐门";
		case "d/taohua": return "桃花岛";
		case "d/tianlongsi": return "天龙寺";
		case "d/village": return "武功镇";
		case "d/wanjiegu": return "万劫谷";
		case "d/wudang": return "武当山";
		case "d/wudu": return "五毒教";
		case "d/xiakedao": return "侠客岛";
		case "d/xiangyang": return "襄阳";
		case "d/xiaoyao": return "逍遥派";
		case "d/xingbu": return "成都刑部";
		case "d/xingxiu": return "星宿海";
		case "d/xuedao": return "大雪山";
		case "d/xueshan": return "雪山派";
		case "d/yanziwu": return "燕子坞";
			default: return "桃源";
	}
}
