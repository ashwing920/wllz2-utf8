// rankd.c

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

string query_rank(object ob)
{
	string my_rank;

	int shen = (int)ob->query("shen");
	int budd;
	int age = ob->query("age");
	int divorce = ob->query("divorced");

	my_rank = ob->query("rank_info/name");
	if(my_rank) return my_rank;

	if( ob->is_ghost() )
		return HIB "【孤魂野鬼】" NOR;

	switch (ob->query("family/family_name")) {
		case "峨嵋派": budd = (int)ob->query_skill("mahayana", 1); break;
		case "少林派":
		case "天龙寺": budd = (int)ob->query_skill("buddhism", 1); break;
		case "武当派":
		case "全真教": budd = (int)ob->query_skill("taoism", 1); break;
		case "雪山寺": budd = (int)ob->query_skill("lamaism", 1); break;
		case "血刀门": budd = (int)ob->query_skill("lamaism", 1); break;
		case "明教": budd = (int)ob->query_skill("shenghuo-shengong",1); break;
		case "丐帮": budd = (int)ob->query("beggarlvl");break;
	}

	switch(ob->query("gender")) {
		case "女性":
		case "雌性":
			switch(wizhood(ob)) {
				case "(admin)": return HIW "【 天  神 】" NOR;
				case "(arch)": return HIY "【 龙  女 】" NOR;
				case "(wizard)": return YEL "【 神  仙 】" NOR;
				case "(apprentice)": return HIM"【 天  仙 】" NOR;
				case "(immortal)": return CYN "【 小天仙 】" NOR;
				default:
					if( ob->query("PKS") > 20 && ob->query("PKS") > ob->query("MKS") / 4 )
						return HIR "【杀人女魔】" NOR;
					if( (int)ob->query("thief") > 10 )
						return "【 女惯窃 】";
					if (!ob->query("class")) {
						if (shen >= 5000000) return HIY "【巾帼神女】" NOR;
						else if (shen >= 3000000) return HIY "【武林天骄】" NOR;
						else if (shen >= 1000000) return HIY "【绝世天娇】" NOR;
						else if (shen >= 500000) return HIM "【旷世女侠】" NOR;
						else if (shen >= 50000) return HIM "【 女飞侠 】" NOR;
						else if (shen >= 5000) return HIW "【 女  侠 】" NOR;
						else if (shen >= 500) return HIY "【 小侠女 】" NOR;
						else if (shen <= -1500000) return HIR "【 妖  姬 】" NOR;
						else if (shen <= -1000000) return HIR "【灭世罗刹】" NOR;
						else if (shen <= -500000) return HIR "【旷世女魔】" NOR;
						else if (shen <= -50000) return HIR "【 女魔王 】" NOR;
						else if (shen <= -5000) return HIY "【 女魔头 】" NOR;
						else if (shen <= -500) return RED "【 小魔女 】" NOR;
					}
					switch(ob->query("class")) {
						case "bonze":
							if (budd >= 500) return HIY "【 神  尼 】" NOR;
							else if (budd >= 400) return HIY "【 圣  尼 】" NOR;
							else if (budd >= 300) return HIY "【 德  尼 】" NOR;
							else if (budd >= 200)  return HIY "【 比  丘 】" NOR;
							else if (budd >= 100) return HIY "【 比丘尼 】" NOR;
							else if (budd >= 30 || age >= 20) return HIY "【 尼  姑 】" NOR;
							else return "【 小尼姑 】";
						case "taoist":
							if (budd >= 500) return HIW "【 玄  女 】" NOR;
							else if (budd >= 400) return HIW "【 女真人 】" NOR;
							else if (budd >= 300) return HIW "【 仙  姑 】" NOR;
							else if (budd >= 200) return HIW "【 散  人 】" NOR;
							else if (budd >= 100) return HIW "【 道  姑 】" NOR;
							else if (budd >= 50 || age >= 20) return HIW "【 女  冠 】" NOR;
							return "【 小道姑 】";
						case "bandit": return "【 女飞贼 】";
						case "dancer":
							if((int)ob->query_skill("sword",1) >= 800 ) return HIM"【 尊  者 】"NOR;
							else if((int)ob->query_skill("sword",1) >= 500 ) return HIM"【 剑  使 】"NOR;
							else if((int)ob->query_skill("sword",1) >= 400 ) return HIM"【 剑  奴 】"NOR;
							else if((int)ob->query_skill("sword",1) >= 300 ) return HIM"【 剑  婢 】"NOR;
							else if((int)ob->query_skill("sword",1) >= 200 ) return HIM"【 侍  女 】"NOR;
							else if((int)ob->query_skill("sword",1) >= 100 ) return HIM"【 艺  女 】"NOR;
							else return HIM"【 舞  者 】"NOR;
						case "scholar": return "【 才  女 】";
						case "officer":
							if((int)ob->query("weiwang") >= 10000 ) return HIY"【 王  妃 】"NOR;
							else if((int)ob->query("weiwang") >= 5000 ) return HIY"【诰命夫人】"NOR;
							else return "【 女  官 】";
						case "fighter": 
							if(budd >= 600) return HIR"【光明使者】" NOR;
							else if(budd >= 500) return HIY"【护教法王】"NOR;
							else if(budd >= 400) return HIC"【 散  人 】"NOR;
							else if(budd >= 300) return HIB"【 掌旗使 】"NOR;
							else if(budd >= 200) return HIG"【 堂  主 】"NOR;
							else if(budd >= 100) return HIB"【 坛  主 】"NOR;
							else return "【 教  众 】";
						case "swordsman":
							if((int)ob->query_skill("sword",1) > 800) return HIR"【剑啸江湖】"NOR;
							else if((int)ob->query_skill("sword",1) > 700) return HIY"【神剑万里】"NOR;
							else if((int)ob->query_skill("sword",1) > 600) return HIY"【 剑  圣 】"NOR;
							else if((int)ob->query_skill("sword",1) > 500) return HIR"【 剑  魔 】"NOR;
							else if((int)ob->query_skill("sword",1) > 400) return HIY"【 剑  神 】"NOR;
							else if((int)ob->query_skill("sword",1) > 300) return HIR"【 剑  煞 】"NOR;
							else if((int)ob->query_skill("sword",1) > 200) return HIW"【 剑  仙 】"NOR;
							else if((int)ob->query_skill("sword",1) > 100) return HIR"【 剑  灵 】"NOR;
							else if((int)ob->query_skill("sword",1) > 50 ) return HIG"【 剑  侠 】"NOR;
							else return "【 女剑士 】";
						case "alchemist": return "【 女方士 】";
						case "shaman": return "【 女巫医 】";
						case "beggar":
							if((int)ob->query_skill("begging",1) > 500 ) return WHT"【 女神丐 】"NOR;
							else if((int)ob->query_skill("begging",1) > 400 ) return WHT"【 女侠丐 】"NOR;
							else if((int)ob->query_skill("begging",1) > 300 ) return WHT"【 女义丐 】"NOR;
							else if((int)ob->query_skill("begging",1) > 200 ) return WHT"【 乞  丐 】"NOR;
							else if((int)ob->query_skill("begging",1) > 100 ) return WHT"【 叫化婆 】"NOR;
							else return WHT "【 叫化妹 】" NOR;
						default:
							if (ob->query("marry")) {
							if (age < 30) return "【 少  妇 】";
							else if (age < 50) return "【中年妇人】";
							else return "【 老妇人 】";
					}
					if (divorce > 2) {
					if (age < 50) return "【 荡  妇 】";
					return "【 老荡妇 】";
				}
				if (divorce) {
					if (age < 50) return "【 寡  妇 】";
					return "【 老寡妇 】";
				}
				if (age < 18) return "【 少  女 】";
				else if (age < 30) return "【青年女子】";
				else if (age < 50) return "【中年女子】";
				else return "【 老处女 】";
			}
		}
		default:
			switch(wizhood(ob)) {
				case "(admin)": return HIW "【 天  神 】" NOR;
				case "(arch)": return HIY "【 龙  神 】" NOR;
				case "(wizard)": return YEL "【 神  仙 】" NOR;
				case "(apprentice)": return HIM"【 天  仙 】" NOR;
				case "(immortal)": return CYN "【 小天仙 】" NOR;
				default:
					if( ((int)ob->query("PKS") > 20) && ((int)ob->query("PKS") > (int)ob->query("MKS")) / 4 )
						return HIR "【杀人魔王】" NOR;
					if( (int)ob->query("thief") > 10 )
						return "【 惯  窃 】";
					if (!ob->query("class")) {
						if (shen >= 5000000) return HIY "【武林神话】" NOR;
						else if (shen >= 3000000) return HIY "【绝世神侠】" NOR;
						else if (shen >= 1000000) return HIC "【旷世大侠】" NOR;
						else if (shen >= 50000) return HIW "【 大  侠 】" NOR;
						else if (shen >= 5000) return HIM "【 侠  客 】" NOR;
						else if (shen >= 500) return HIY "【 少  侠 】" NOR;
						else if (shen <= -5000000) return HIR "【灭世魔尊】" NOR;
						else if (shen <= -3000000) return HIR "【盖世狂魔】" NOR;
						else if (shen <= -1000000) return HIR "【 魔  尊 】" NOR;
						else if (shen <= -50000) return HIR "【 魔  王 】" NOR;
						else if (shen <= -5000) return HIB "【 魔  头 】" NOR;
						else if (shen <= -500) return RED "【 少  魔 】" NOR;
					}
					switch(ob->query("class")) {
						case "bonze":
							if (budd >= 800) return HIY "【 神  僧 】" NOR;
							else if (budd >= 600) return HIY "【 长  老 】" NOR;
							else if (budd >= 500) return HIY "【 尊  者 】" NOR;
							else if (budd >= 400) return HIY "【 圣  僧 】" NOR;
							else if (budd >= 300) return HIY "【 禅  师 】" NOR;
							else if (budd >= 200) return HIY "【 罗  汉 】" NOR;
							else if (budd >= 100) return HIY "【 比  丘 】" NOR;
							return "【 僧  人 】";
						case "taoist":
							if(budd >= 500) return HIW "【 天  尊 】" NOR;
							else if(budd >= 400) return HIW "【道学宗师】" NOR;
							else if(budd >= 300) return HIW "【 天  师 】" NOR;
							else if(budd >= 200) return HIW "【 真  人 】" NOR;
							else if(budd >= 100) return HIW "【 道  长 】" NOR;
							else if(budd >= 50 || age >= 20) return HIW "【 道  士 】" NOR;
							else return CYN"【 道  童 】"NOR;
						case "lama":
							if (budd >= 500) return HIY "【 活  佛 】" NOR;
							else if (budd >= 400) return HIY "【 班  禅 】" NOR;
							else if (budd >= 300) return HIY "【 法  王 】" NOR;
							else if (budd >= 200) return HIY "【 国  师 】" NOR;
							else if (budd >= 100) return HIY "【 大喇嘛 】" NOR;
							else if (budd >= 50 || age >= 20) return HIY "【 小喇嘛 】" NOR;
							else return "【 喇  嘛 】";
						case "bandit": return "【 盗  贼 】";
						case "scholar":
							if((int)ob->query_skill("literate") > 600 ) return HIW"【 圣  人 】"NOR;
							else if((int)ob->query_skill("literate") > 500 ) return HIW"【 仁  者 】"NOR;
							else if((int)ob->query_skill("literate") > 400 ) return HIW"【 书  圣 】"NOR;
							else if((int)ob->query_skill("literate") > 300 ) return HIW"【 状  元 】"NOR;
							else if((int)ob->query_skill("literate") > 200 ) return HIW"【 进  士 】"NOR;
							else if((int)ob->query_skill("literate") > 100 ) return HIW"【 秀  才 】"NOR;
							else return CYN"【 学  童 】"NOR;
						case "officer":
							if((int)ob->query("weiwang") >= 20000 ) return HIY"【 皇  族 】"NOR;
							else if((int)ob->query("weiwang") >= 10000 ) return HIY"【 王  爷 】"NOR;
							else if((int)ob->query("weiwang") >= 8000 ) return HIY"【 侯  爷 】"NOR;
							else if((int)ob->query("weiwang") >= 5000 ) return HIY"【 侍  卫 】"NOR;
							else if((int)ob->query("weiwang") >= 1000 ) return HIY"【 武  将 】"NOR;
							else return HIY"【 官  差 】"NOR;
						case "fighter": 
							if(budd >= 600) return HIR"【光明使者】" NOR;
							else if(budd >= 500) return HIY"【护教法王】"NOR;
							else if(budd >= 400) return HIC"【 散  人 】"NOR;
							else if(budd >= 300) return HIB"【 掌旗使 】"NOR;
							else if(budd >= 200) return HIG"【 堂  主 】"NOR;
							else if(budd >= 100) return HIB"【 坛  主 】"NOR;
							else return "【 教  众 】";
						return "【 武  者 】";
						case "swordsman":
							if((int)ob->query_skill("sword",1) > 800) return HIR"【剑啸江湖】"NOR;
							else if((int)ob->query_skill("sword",1) > 700) return HIY"【神剑万里】"NOR;
							else if((int)ob->query_skill("sword",1) > 600) return HIY"【 剑  圣 】"NOR;
							else if((int)ob->query_skill("sword",1) > 500) return HIR"【 剑  魔 】"NOR;
							else if((int)ob->query_skill("sword",1) > 400) return HIY"【 剑  神 】"NOR;
							else if((int)ob->query_skill("sword",1) > 300) return HIR"【 剑  煞 】"NOR;
							else if((int)ob->query_skill("sword",1) > 200) return HIW"【 剑  仙 】"NOR;
							else if((int)ob->query_skill("sword",1) > 100) return HIR"【 剑  灵 】"NOR;
							else if((int)ob->query_skill("sword",1) > 50 ) return HIG"【 剑  侠 】"NOR;
							else return "【 剑  士 】";
						case "alchemist": return "【 方  士 】";
						case "shaman": return "【 巫  医 】";
						case "beggar":
							if((int)ob->query("beggarlvl",1) > 500 ) return WHT"【 神  丐 】"NOR;
							else if((int)ob->query_skill("begging",1) > 400 ) return WHT"【 侠  丐 】"NOR;
							else if((int)ob->query_skill("begging",1) > 300 ) return WHT"【 义  丐 】"NOR;
							else if((int)ob->query_skill("begging",1) > 200 ) return WHT"【 乞  丐 】"NOR;
							else if((int)ob->query_skill("begging",1) > 100 ) return WHT"【 花  丐 】"NOR;
							else return WHT"【 叫化子 】"NOR;
						case "eunuch":
							if((int)ob->query_skill("pixie-jian",1) >= 700) return HIM "【 九千岁 】"NOR;
							else if((int)ob->query_skill("pixie-jian",1) >= 600) return HIM "【东厂指挥】"NOR;
							else if((int)ob->query_skill("pixie-jian",1) >= 500) return HIM "【 大档头 】"NOR;
							else if((int)ob->query_skill("pixie-jian",1) >= 400) return HIM "【东厂档头】"NOR;
							else if((int)ob->query_skill("pixie-jian",1) >= 300) return HIM "【东厂千户】"NOR;
							else if((int)ob->query_skill("pixie-jian",1) >= 200) return HIM "【东厂百户】"NOR;
							else if((int)ob->query_skill("pixie-jian",1) >= 150) return HIM "【东厂太监】"NOR;
							else if((int)ob->query_skill("pixie-jian",1) >= 100) return HIM "【 太  监 】"NOR;
							else if((int)ob->query_skill("pixie-jian",1) >= 50) return HIM "【九品太监】"NOR;
							else return HIM"【 小太监 】"NOR;
						default:
							if (ob->query("marry")) {
								if (age < 30) return "【青年男子】";
								else if (age < 50) return "【中年男子】";
								else return "【 老头儿 】";
							}
							if (divorce > 2) {
								if (age < 50) return "【花花公子】";
								return "【 老色鬼 】";
							}
							if (divorce) {
								if (age < 50) return "【 鳏  夫 】";
								return "【 老鳏夫 】";
							}
							if (age < 18) return "【 少  年 】";
							else if (age < 30) return "【青年男子】";
							else if (age < 50) return "【中年男子】";
							else return "【 老处男 】";
					}
			}
	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;
	if(ob->query("race") != "人类") return ob->name();

	age = ob->query("age");
	if ((int)ob->query_skill("beauty") > 30) age -= ((int)ob->query_skill("beauty")-30)/5;
	switch(ob->query("gender")) {
	case "女性":
	case "雌性":
		switch(ob->query("class")) {
		case "bonze":
			if( age < 20 ) return "小师太";
			return "师太";
		case "taoist":
			if( age < 20 ) return "小仙姑";
			return "仙姑";
		default:
			if( age < 20 ) return "小姑娘";
			if( age < 50 ) return "姑娘";
			return "婆婆";
			}
	default:
		switch(ob->query("class")) {
		case "bonze":
			if( age < 20 ) return "小师父";
			return "大师";
		case "lama":
			if( age < 50 ) return "大师父";
			return "上人";
		case "taoist":
			if( age < 20 ) return "道兄";
			return "道长";
		case "fighter":
		case "swordsman":
			if( age < 20 ) return "小老弟";
			if( age < 50 ) return "壮士";
			return "老前辈";
		case "eunuch": return "公公";
		default:
			if( age < 20 ) return "小兄弟";
			if( age < 50 ) return "壮士";
			return "老爷子";
		}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) ) return str;
	if(ob->query("race") != "人类") return "禽兽";

	age = ob->query("age");
	if ((int)ob->query_skill("beauty") > 30) age -= ((int)ob->query_skill("beauty")-30)/5;
	switch(ob->query("gender")) {
	case "女性":
	case "雌性":
		switch(ob->query("class")) {
		case "bonze": return "贼尼";
		case "taoist": return "妖女";
		default:
			if( age < 20 ) return "小贱人";
			if (age < 50) return "贱人";
			return "死老太婆";
			}
	default:
		switch(ob->query("class")) {
		case "bonze":
			if( age < 50 ) return "死秃驴";
			return "老秃驴";
		case "lama":
			if( age < 50 ) return "死番僧";
			return "老番僧";
		case "taoist": return "死牛鼻子";
		case "eunuch": return "阉贼";
		default:
			if( age < 20 ) return "小王八蛋";
			if( age < 50 ) return "臭贼";
			return "老匹夫";
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;
	if(ob->query("race") != "人类") return ob->name();

	age = ob->query("age");
	if ((int)ob->query_skill("beauty") > 30) age -= ((int)ob->query_skill("beauty")-30)/5;
	switch(ob->query("gender")) {
	case "女性":
	case "雌性":
		switch(ob->query("class")) {
		case "bonze":
			if( age < 50 ) return "贫尼";
			return "老尼";
		default:
			if( age < 30 ) return "小女子";
			return "妾身";
		}
	default:
		switch(ob->query("class")) {
		case "lama":
			if( age < 50 ) return "小僧";
			return "老朽";
		case "bonze":
			if( age < 50 ) return "贫僧";
			return "老衲";
		case "taoist":
			return "贫道";
		case "eunuch": return "本官";
		default:
			if( age < 50 ) return "在下";
			return "老头子";
		}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;
	if(ob->query("race") != "人类") return "禽兽我";

	age = ob->query("age");
	if ((int)ob->query_skill("beauty") > 30) age -= ((int)ob->query_skill("beauty")-30)/5;
	switch(ob->query("gender")) {
	case "女性":
	case "雌性":
		switch(ob->query("class")) {
		case "bonze":
			if (age < 50) return "贫尼我";
			return "老尼我";
		default:
			if (age < 20) return "本小姐";
			if (age < 30) return "本姑娘";
			return "老娘我";
		}
	default:
		switch(ob->query("class")) {
		case "bonze":
			if( age < 50 ) return "大和尚我";
			return "老和尚我";
		case "lama":
			if( age < 50 ) return "大和尚我";
			return "本佛爷我";
		case "taoist":
			return "本山人我";
		case "eunuch": return "公公我";
		default:
			if( age < 50 ) return "大爷我";
			return "老子";
		}
	}
}
string query_close(object ob,int age,string rgender)
{
	int a1, a2;
	string gender;

	if (objectp(ob) ){
		if(!age)
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");

		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}
	if( !rgender )
		gender = ob->query("gender");
	else    gender = rgender;

	switch (gender) {
		case "女性" :
		case "雌性" :
			if (a2 - a1 >= 14) return "姑姑";
			if (a1 - a2 >= 14) return "侄女";
			if (a1 > a2) return "贤妹";
			return "姐姐";
			break;
		default :
			if (a2 - a1 >= 14) return "叔叔";
			if (a1 - a2 >= 14) return "侄子";
			if (a1 > a2) return "贤弟";
			return "哥哥";
	}
}

string query_self_close(object ob,int age)
{
	int a1, a2;

	string gender;
	if( objectp(ob) ) {
		if( !age )
			a1 = this_player()->query("age");
		else
			a1 = ob->query("age");
		if( !age)
			a2 = ob->query("age");
		else    a2 = age;
	}

	if( age )
		gender = ob->query("gender");
	else
		gender = this_player()->query("gender");

	switch (gender) {
		case "女性" :
		case "雌性" :
			if (a1 - a2 >= 14) return "姑姑我";
			if (a2 - a1 >= 14) return "侄女我";
			if (a1 > a2) return "姐姐我";
			return "小妹我";
			break;
		default :
			if (a1 - a2 >= 14) return "叔叔我";
			if (a2 - a1 >= 14) return "小侄我";
			if (a1 > a2) return "愚兄我";
			return "小弟我";
	}
}

