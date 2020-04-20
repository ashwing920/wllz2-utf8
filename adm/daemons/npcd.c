// npc_skd.c
// Design By Robert 蝴蝶君 email:robert_st@sina.com

//#pragma optimize
//#pragma save_binary

string *general_skill( object me )
{
	string family;

	if(!me) return 0;
	
	family = (string)me->query("family/family_name");

	switch(family) {
		case "白驼山派":
			return ({
				"force",
				"unarmed",
				"dodge",
				"parry",
				"staff",
				"hamagong",
				"chanchu-bufa",
				"shexing-diaoshou",
				"lingshe-zhangfa",
				"training",
				"hand",
				"literate",
				"perception",
				"strike",
				"poison",
				});
		case "大理段家":
			return ({
				"force",
				"dodge",
				"parry",
				"cuff",
				"strike",
				"sword",
				"staff",
				"finger",
				"unarmed",
				"kurong-changong",
				"tiannan-step",
				"jinyu-quan",
				"wuluo-zhang",
				"duanjia-sword",
				"sun-finger",
				"literate",
				"liumai-shenjian",
				});
		case "峨嵋派":
			return ({
				"yitian-sword",
				"persuading",
				"throwing",
				"force",
				"dodge",
				"finger",
				"parry",
				"strike",
				"sword",
				"blade",
				"literate",
				"mahayana",
				"jinding-zhang",
				"tiangang-zhi",
				"huifeng-jian",
				"yanxing-dao",
				"zhutian-bu",
				"linji-zhuang",
				});
		case "丐帮":
			return ({
				"force",
				"huntian-qigong",
				"unarmed",
				"xianglong-zhang",
				"dodge",
				"xiaoyaoyou",
				"parry",
				"staff",
				"dagou-bang",
				"begging",
				"checking",
				"training",
				"hand",
				"shexing-diaoshou",
				"blade",
				"liuhe-daofa",
				"staff",
				"fengmo-zhang",
				});
		case "古墓新派":
			return ({
				"force",
				"yunv-xinfa",
				"qufeng",
				"sword",
				"yunv-jian",
				"quanzhen-jian",
				"dodge",
				"yunv-shenfa",
				"parry",
				"unarmed",
				"meinv-quan",
				"literate",
				"taoism",
				"tianluo-diwang",
				});
		case "华山剑派":
			return ({
				"unarmed",
				"cuff",
				"force",
				"blade",
				"dodge",
				"parry",
				"sword",
				"strike",
				"huashan-neigong",
				"poyu-quan",
				"fanliangyi-dao",
				"huashan-sword",
				"hunyuan-zhang",
				"lonely-sword",
				"feiyan-huixiang",
				"literate",
				});
		case "昆仑派":
			return ({
				"perception",
				"force", 
				"dodge", 
				"parry", 
				"xuantian-force", 
				"sword", 
				"literate",
				"zhengliangyi-sword", 
				"yaoming-dodge", 
				"sanyin-unarmed",
				"unarmed",
				"strike",
				"cuff", 
				"zhentian-quan",
				"leg",
				"chuanyun-tui",
				"kunlun-zhang",
				});
		case "灵鹫宫":
			return ({
				"force",
				"unarmed",
				"dodge",
				"parry",
				"hand",
				"strike",
				"literate",
				"perception",
				"zhemei-shou",
				"liuyang-zhang",
				"yueying-wubu",
				"bahuang-gong",
				"tianyu-qijian",
				"sword",
				});
		case "明教":
			return ({
				"staff",
				"claw",
				"strike",
				"force",
				"unarmed",
				"dodge",
				"parry",
				"sword",
				"blade",
				"throwing",
				"perception",
				"tulong-daofa",
				"duoming-jinhua",
				"hunyuan-yiqi",
				"jiuyang-shengong",
				"qiankun-danuoyi",
				"qishang-quan",
				"taiji-quan",
				"taiji-dao",
				"shenghuo-ling",
				"cuff",
				"literate",
				"shenghuo-shengong",
				});
		case "慕容世家":
			return ({
				"force", 
				"sword", 
				"unarmed", 
				"parry",
				"dodge",
				"blade",
				"strike",
				"finger",
				"literate",
				"canhe-zhi",
				"xingyi-zhang",
				"shenyuan-gong",
				"douzhuanxingyi",
				"murong-sword",
				"murong-zhang",
				"taxue-steps",
				"murong-daofa",
				});
		case "全真教":
			return ({
				"force",
				"xiantian-qigong",
				"sword",
				"quanzhen-jian",
				"dodge",
				"jinyan-gong",
				"parry",
				"unarmed",
				"haotian-zhang",
				"literate",
				"strike",
				"taoism",
				"finger",
				"sun-finger",
				"whip",
				"duanyun-bian",
				"cuff",
				"chunyang-quan",
				});
		case "日月神教":
			return ({
				"sword",
				"parry",
				"literate",
				"dodge",
				"unarmed",
				"whip",
				"force",
				"tianmo-zhang",
				"staff",
				"tianmo-sword",
				"tianmo-dao",
				"riyue-bian",
				"piaomiao-shenfa",
				"wuchang-zhang",
				"xixing-force",
				"blade",
				"tianmo-dafa",
				});
		case "少林派":
			return ({
				"unarmed",
				"buddhism",
				"literate",
				"blade",
				"claw",
				"club",
				"cuff",
				"dodge",
				"finger",
				"force",
				"hand",
				"parry",
				"staff",
				"strike",
				"sword",
				"whip",
				"banruo-zhang",
				"cibei-dao",
				"damo-jian",
				"fengyun-shou",
				"fumo-jian",
				"hunyuan-yiqi",
				"jingang-quan",
				"longzhua-gong",
				"luohan-quan",
				"nianhua-zhi",
				"pudu-zhang",
				"qianye-shou",
				"sanhua-zhang",
				"riyue-bian",
				"shaolin-shenfa",
				"weituo-gun",
				"wuchang-zhang",
				"xiuluo-dao",
				"yingzhua-gong",
				"yijinjing",
				"yizhi-chan",
				"zui-gun",
				});
		case "神龙教":
			return ({
				"force",
				"hand",
				"strike",
				"staff",
				"parry",
				"dodge",
				"leg",
				"poison",
				"finger",
				"yixingbu",
				"jueming-tui",
				"yingxiong-sanzhao",
				"shenlong-bashi",
				"huagu-mianzhang",
				"shenlong-xinfa",
				"shedao-qigong",
				"sword",
				});
		case "唐门":
			return ({
				"poison",
				"force",
				"biyun-xinfa",
				"dodge",
				"qiulinshiye",
				"strike",
				"unarmed",
				"biye-wu",
				"parry",
				"throwing",
				"zimu-zhen",
				"literate",
				"zhuihun-biao",
				"liuxing-dao",
				"wuzhan-mei",
				"sword",
				});
		case "桃花岛":
			return ({
				"music",
				"cuixin-zhang",
				"force",
				"bibo-shengong",
				"hand",
				"finger",
				"tanzhi-shentong",
				"unarmed",
				"strike",
				"luoying-zhang",
				"xuanfeng-leg",
				"dodge",
				"anying-fuxiang",
				"parry",
				"sword",
				"luoying-shenjian",
				"yuxiao-jian",
				"lanhua-shou",
				"qimen-wuxing",
				"count",
				"literate",
				});
		case "天龙寺":
			return ({
				"force",
				"dodge",
				"parry",
				"finger",
				"sword",
				"tiannan-step",
				"kurong-changong",
				"duanjia-sword",
				"liumai-shenjian",
				"buddhism",
				"literate",
				});
		case "武当派":
			return ({
				"force",
				"taiji-shengong",
				"dodge",
				"tiyunzong",
				"unarmed",
				"taiji-quan",
				"parry",
				"sword",
				"taiji-jian",
				"liangyi-jian",
				"wudang-jian",
				"taoism",
				"literate",
				});
		case "五毒神教":
			return ({
				"force",
				"wudu-shengong",
				"dodge",
				"parry",
				"wudu-bian",
				"wudu-zhang",
				"wudu-xinfa",
				"whip",
				"guimei-shenfa",
				"strike",
				"pour",
				"literate",
				"unarmed",
				"poison",
			});
		case "逍遥派":
			return ({
				"hand",
				"strike",
				"force",
				"dodge",
				"unarmed",
				"parry",
				"lingboweibu",
				"chixin-jian",
				"beiming-shengong",
				"zhemei-shou",
				"liuyang-zhang",
				"literate",
				"sword",
				"blade",
				"ruyi-dao",
				});
		case "血刀门":
			return ({
				"lamaism",
				"literate",
				"force",
				"parry",
				"blade",
				"dodge",
				"xuehai-mogong",
				"xuedun",
				"strike",
				"miexian-zhang",
				"xue-dao",
				"unarmed",
				"wuying-shenquan",
				});
		case "星宿派":
			return ({
				"parry",
				"staff",
				"poison",
				"literate",
				"unarmed",
				"force",
				"throwing",
				"dodge",
				"strike",
				"claw",
				"feixing-shu",
				"zhaixinggong",
				"chousui-zhang",
				"sanyin-wugongzhao",
				"huagong-dafa",
				"tianshan-zhang",
				});
		case "雪山寺":
			return ({
				"longxiang",
				"necromancy",
				"force",
				"xiaowuxiang",
				"dodge",
				"shenkong-xing",
				"unarmed",
				"yujiamu-quan",
				"parry",
				"sword",
				"mingwang-jian",
				"lamaism",
				"literate",
				"staff",
				"xiangmo-chu",
				"strike",
				"huoyan-dao",
				"hammer",
				"riyue-lun",
				"magic",
				"essencemagic",
				"dashou-yin",
				"hand",
				});
		case "云龙门":
			return ({
				"literate",
				"force",
				"dodge",
				"unarmed",
				"parry",
				"whip",
				"blade",
				"sword",
				"hand",
				"claw",
				"houquan",
				"yunlong-xinfa",
				"yunlong-shengong",
				"wuhu-duanmendao",
				"yunlong-jian",
				"yunlong-shenfa",
				"yunlong-bian",
				"yunlong-shou",
				"yunlong-zhua",
			});
		default:
			return ({
				"literate",
				"force",
				"dodge",
				"unarmed",
				"parry",
				"whip",
				"blade",
				"sword",
				"hand",
				"claw",
				"houquan",
				"yunlong-xinfa",
				"yunlong-shengong",
				"wuhu-duanmendao",
				"yunlong-jian",
				"yunlong-shenfa",
				"yunlong-bian",
				"yunlong-shou",
				"yunlong-zhua",
			});

		}
}
mapping general_mapp(object me)
{
	string family;

	if( !me) return 0;

	family = me->query("family/family_name");

	switch(family) {
		case "白驼山派":   return ([
			"force":"hamagong",
			"dodge":"chanchu-bufa",
			"unarmed":"shexing-diaoshou",
			"parry":"lingshe-zhangfa",
			"staff":"lingshe-zhangfa",
			"strike":"hamagong",
			"hand":"shexing-diaoshou",
		]);
		case "大理段家":   return ([
			"force":"kurong-changong",
			"dodge":"tiannan-step",
			"finger":"liumai-shenjian",
			"cuff":"jinyu-quan",
			"strike":"wuluo-zhang",
			"parry":"sun-finger",
			"sword":"duanjia-sword",
			"staff":"duanjia-sword",
		]);
		case "峨嵋派":    return ([
			"force":"linji-zhuang",
			"finger":"tiangang-zhi",
			"dodge":"zhutian-bu",
			"strike":"jinding-zhang",
			"sword":"yitian-sword",
			"blade":"yanxing-dao",
			"parry":"huifeng-jian",
		]);
		case "丐帮":    return ([
			"parry":"fengmo-zhang",
			"hand":"shexing-diaoshou",
			"blade":"liuhe-daofa",
			"force":"huntian-qigong",
			"unarmed":"xianglong-zhang",
			"dodge":"xiaoyaoyou",
			"staff":"dagou-bang",
		]);
		case "古墓新派":        return ([
			"force":"yunv-xinfa",
			"sword":"yunv-jian",
			"dodge":"yunv-shenfa",
			"parry":"meinv-quan",
			"unarmed":"meinv-quan",
		]);
		case "华山剑派":        return ([
			"cuff":"poyu-quan",
			"force":"huashan-neigong",
			"dodge":"feiyan-huixiang",
			"parry":"lonely-sword",
			"sword":"lonely-sword",
			"blade":"fanliangyi-dao",
			"strike":"hunyuan-zhang",
		]);
		case "昆仑派":          return ([
			"dodge":"yaoming-dodge",
			"force":"xuantian-force",
			"parry":"zhengliangyi-sword",
			"sword":"zhengliangyi-sword",
			"unarmed":"sanyin-unarmed",   
			"leg":"chuanyun-tui",
			"strike":"kunlun-zhang",
			"cuff":"zhentian-quan",
		]);
		case "灵鹫宫":          return ([
			"sword":"tianyu-qijian",
			"force":"bahuang-gong",
			"strike":"liuyang-zhang",
			"dodge":"yueying-wubu",
			"unarmed":"liuyang-zhang",
			"hand":"zhemei-shou",
			"parry":"tianyu-qijian",
		]);
		case "明教":            return ([
			"dodge":"qiankun-danuoyi",
			"unarmed":"taiji-quan",
			"sword":"shenghuo-ling",
			"parry":"qiankun-danuoyi",
			"blade":"tulong-daofa",
			"throwing":"duoming-jinhua",
			"cuff":"qishang-quan",
			"force":"shenghuo-shengong",
		]);
		case "慕容世家":        return ([
			"finger":"canhe-zhi",
			"blade":"murong-daofa",
			"strike":"xingyi-zhang",
			"force":"douzhuanxingyi",
			"sword":"murong-sword",
			"unarmed":"murong-zhang",
			"parry":"murong-sword",
			"dodge":"taxue-steps",
		]);
		case "全真教":          return ([
			"cuff":"chunyang-quan",
			"whip":"duanyun-bian",
			"force":"xiantian-qigong",
			"sword":"quanzhen-jian",
			"dodge":"jinyan-gong",
			"parry":"quanzhen-jian",
			"strike":"haotian-zhang",
			"finger":"sun-finger",
		]);
		case "日月神教":        return ([
			"unarmed":"tianmo-zhang",
			"sword":"tianmo-sword",
			"parry":"tianmo-sword",
			"blade":"tianmo-dao",
			"dodge":"piaomiao-shenfa",
			"force":"xixing-force",
			"whip":"riyue-bian",
			"staff":"wuchang-zhang",
		]);
		case "少林派":          return ([
			"blade":"cibei-dao",
			"claw":"longzhua-gong",
			"club":"wuchang-zhang",
			"cuff":"luohan-quan",
			"dodge":"shaolin-shenfa",
			"finger":"nianhua-zhi",
			"force":"yijinjing",
			"hand":"fengyun-shou",
			"parry":"nianhua-zhi",
			"staff":"weituo-gun",
			"strike":"sanhua-zhang",
			"sword":"fumo-jian",
			"whip":"riyue-bian",
		]);
		case "神龙教":          return ([
			"finger":"yingxiong-sanzhao",
			"leg":"jueming-tui",
			"staff":"shedao-qigong",
			"force":"shenlong-xinfa",
			"hand":"shenlong-bashi",
			"strike":"huagu-mianzhang",
			"parry":"shedao-qigong",
			"dodge":"yixingbu",
		]);
		case "唐门":            return ([
			"force":"biyun-xinfa",
			"dodge":"qiulinshiye",
			"strike":"biye-wu",
			"unarmed":"biye-wu",
			"throwing":"zimu-zhen",
			"parry":"liuxing-dao",
			"sword":"wuzhan-mei",
		]);
		case "桃花岛":          return ([
			"force":"bibo-shengong",
			"finger":"tanzhi-shentong",
			"hand":"lanhua-shou",
			"strike":"luoying-zhang",
			"unarmed":"xuanfeng-leg",
			"dodge":"anying-fuxiang",
			"parry":"yuxiao-jian",
			"sword":"luoying-shenjian",
		]);
		case "天龙寺":          return ([
			"force":"kurong-changong",
			"dodge":"tiannan-step",
			"parry":"liumai-shenjian",
			"finger":"liumai-shenjian",
			"sword":"duanjia-sword",
		]);
		case "武当派":          return ([
			"force":"taiji-shengong",
			"dodge":"tiyunzong",
			"unarmed":"taiji-quan",
			"parry":"liangyi-jian",
			"sword":"taiji-jian",
		]);
		case "五毒神教":        return ([
			"unarmed":"wudu-zhang",
			"force":"wudu-shengong",
			"dodge":"guimei-shenfa",
			"strike":"wudu-zhang",
			"parry":"wudu-bian",
			"whip":"wudu-bian",
		]);
		case "逍遥派":          return ([
			"unarmed":"zhemei-shou",
			"hand":"zhemei-shou",
			"strike":"liuyang-zhang",
			"dodge":"lingboweibu",
			"sword":"chixin-jian",
			"force":"beiming-shengong",
			"blade":"ruyi-dao",
		]);
		case "血刀门":          return ([
			"unarmed":"wuying-shenquan",
			"force":"xuehai-mogong",
			"dodge":"xuedun",
			"strike":"miexian-zhang",
			"parry":"xue-dao",
			"blade":"xue-dao",
		]);
		case "星宿派":          return ([
			"force":"huagong-dafa",
			"dodge":"zhaixinggong",
			"strike":"chousui-zhang",
			"claw":"sanyin-wugongzhao",
			"parry":"tianshan-zhang",
			"staff":"tianshan-zhang",
			"unarmed":"chousui-zhang",
			"throwing":"feixing-shu",
		]);
		case "雪山寺":          return ([
			"strike":"huoyan-dao",
			"magic":"essencemagic",
			"hammer":"riyue-lun",
			"force":"xiaowuxiang",
			"dodge":"shenkong-xing",
			"unarmed":"yujiamu-quan",
			"parry":"yujiamu-quan",
			"staff":"xiangmo-chu",
			"hand":"dashou-yin",
			"sword":"mingwang-jian",
		]);
		case "云龙门":          return ([
			"dodge":"yunlong-shenfa",
			"force":"yunlong-shengong",
			"unarmed":"houquan",
			"blade":"wuhu-duanmendao",
			"hand":"yunlong-shou",
			"parry":"yunlong-shou",
			"claw":"yunlong-zhua",
			"sword":"yunlong-jian",
			"whip":"yunlong-bian",
		]);
		default: return ([
			"dodge":"yunlong-shenfa",
			"force":"yunlong-shengong",
			"unarmed":"houquan",
			"blade":"wuhu-duanmendao",
			"hand":"yunlong-shou",
			"parry":"yunlong-shou",
			"claw":"yunlong-zhua",
			"sword":"yunlong-jian",
			"whip":"yunlong-bian",
		]);
	}
}
int full_init(object me)
{
	string skill, map_to,family;
	object w_ob;
	int exp, i, iEnable, iRet;

	if( !me || userp(me))return 0;

	exp = (int)me->query("combat_exp");
	i = sizeof(general_skill(me));

	while( i--){
		skill = general_skill(me)[i];

		iRet = (exp>1000000) ?  (exp/100*800) : exp*800/100;
		iRet = efun::to_int( pow( efun::to_float(iRet), 1.0 / 3.0 ) );

		me->set_skill(skill,iRet);

		if( map_to = general_mapp(me)[skill]) 
			me->map_skill(skill,map_to);
	}

	iRet = (int)me->query_skill("force");

	me->set("max_jingli", iRet*15);
	me->set("jingli", iRet*15);
	me->set("max_neili", iRet*15);
	me->set("neili", iRet*15);

	me->set("max_jing",iRet*15);
	me->set("eff_jing",iRet*15);
	me->set("jing",iRet*15);
	me->set("max_qi",iRet*15);
	me->set("eff_qi",iRet*15);
	me->set("qi",iRet*15);

	me->set("jiali",iRet/2);

	me->add_temp("apply/damage",iRet / 5);
	me->add_temp("apply/unarmed_damage",iRet / 8);
	me->add_temp("apply/armor",iRet / 4);

	if(!objectp(me->query_temp("weapon"))){
		family = (string)me->query("family/family_name");
		switch(family) {
			case "白驼山派":
			case "星宿派":
			case "丐帮":
				w_ob=new("/clone/weapon/staff");
				break;
			case "逍遥派":
			case "血刀门":
			case "明教":
				w_ob=new("/clone/weapon/gangdao");
				break;
			case "少林派":
				w_ob=new("/clone/weapon/stick");
				break;
			case "唐门":
				w_ob=new("/d/tangmen/obj/gangbiao");
				break;
			case "五毒神教":
				w_ob=new("/clone/weapon/whip");
				break;
			default:
				w_ob=new("/clone/weapon/sword");
				break;
		}
		w_ob->move(me);
		w_ob->wield();
	}
	return 1;
}
