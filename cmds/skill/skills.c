// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
	BLU"不堪一击"NOR,
	BLU"毫不足虑"NOR,
	BLU"不足挂齿"NOR,
	BLU"初学乍练"NOR,
	BLU"初窥门径"NOR,
	BLU"略知一二"NOR,
	HIB"普普通通"NOR,
	HIB"平平淡淡"NOR,
	HIB"平淡无奇"NOR,
	HIB"粗通皮毛"NOR,
	HIB"半生不熟"NOR,
	HIB"马马虎虎"NOR,
	MAG"略有小成"NOR,
	MAG"驾轻就熟"NOR,
	MAG"心领神会"NOR,
	MAG"了然於胸"NOR,
	MAG"略有大成"NOR,
	MAG"今非昔比"NOR,
	CYN"豁然贯通"NOR,
	CYN"出类拔萃"NOR,
	CYN"神乎其技"NOR,
	CYN"威不可当"NOR,
	CYN"鹤立鸡群"NOR,
	CYN"无可匹敌"NOR,
	YEL"技冠群雄"NOR,
	YEL"神乎其技"NOR,
	YEL"不可一世"NOR,
	YEL"出神入化"NOR,
	YEL"傲视群雄"NOR,
	YEL"登峰造极"NOR,
	WHT"不寒而颤"NOR,
	WHT"所向披靡"NOR,
	WHT"一代宗师"NOR,
	WHT"神功盖世"NOR,
	WHT"举世无双"NOR,
	WHT"一代天骄"NOR,
	HIM"盖世奇才"NOR,
	HIM"旷世高手"NOR,
	HIM"暗藏杀机"NOR,
	HIM"深藏不露"NOR,
	HIM"无与伦比"NOR,
	HIM"空前绝后"NOR,
	HIC"惊世骇俗"NOR,
	HIC"震古铄今"NOR,
	HIC"独步江湖"NOR,
	HIC"独霸一方"NOR,
	HIC"雄霸天下"NOR,
	HIC"翻江倒海"NOR,
	RED"地动山摇"NOR,
	RED"惊天动地"NOR,
	RED"天旋地转"NOR,
	RED"鬼哭神嚎"NOR,
	RED"天崩地裂"NOR,
	HIR"天地无用"NOR,
	HIR"神功通玄"NOR,
	HIR"五气朝元"NOR,
	HIR"旷古绝伦"NOR,
	WHT"超凡入圣"NOR,
	HIW"返璞归真"NOR,
	HIR"深不可测"NOR,
	HIR"反璞归真"NOR,
	HIY"佛法无边"NOR,
	HIY"无量虚空"NOR,
	HIY"无穷无尽"NOR,
	HIR"天下无敌"NOR,
});

string *knowledge_level_desc = ({
	BLU"不堪一击"NOR,
	BLU"毫不足虑"NOR,
	BLU"不足挂齿"NOR,
	BLU"初学乍练"NOR,
	BLU"初窥门径"NOR,
	BLU"略知一二"NOR,
	HIB"普普通通"NOR,
	HIB"平平淡淡"NOR,
	HIB"平淡无奇"NOR,
	HIB"粗通皮毛"NOR,
	HIB"半生不熟"NOR,
	HIB"马马虎虎"NOR,
	MAG"略有小成"NOR,
	MAG"驾轻就熟"NOR,
	MAG"心领神会"NOR,
	MAG"了然於胸"NOR,
	MAG"略有大成"NOR,
	MAG"今非昔比"NOR,
	CYN"豁然贯通"NOR,
	CYN"出类拔萃"NOR,
	CYN"神乎其技"NOR,
	CYN"威不可当"NOR,
	CYN"鹤立鸡群"NOR,
	CYN"无可匹敌"NOR,
	YEL"技冠群雄"NOR,
	YEL"神乎其技"NOR,
	YEL"不可一世"NOR,
	YEL"出神入化"NOR,
	YEL"傲视群雄"NOR,
	YEL"登峰造极"NOR,
	WHT"不寒而颤"NOR,
	WHT"所向披靡"NOR,
	WHT"一代宗师"NOR,
	WHT"神功盖世"NOR,
	WHT"举世无双"NOR,
	WHT"一代天骄"NOR,
	HIM"盖世奇才"NOR,
	HIM"旷世高手"NOR,
	HIM"暗藏杀机"NOR,
	HIM"深藏不露"NOR,
	HIM"无与伦比"NOR,
	HIM"空前绝后"NOR,
	HIC"惊世骇俗"NOR,
	HIC"震古铄今"NOR,
	HIC"独步江湖"NOR,
	HIC"独霸一方"NOR,
	HIC"雄霸天下"NOR,
	HIC"翻江倒海"NOR,
	RED"地动山摇"NOR,
	RED"惊天动地"NOR,
	RED"天旋地转"NOR,
	RED"鬼哭神嚎"NOR,
	RED"天崩地裂"NOR,
	HIR"天地无用"NOR,
	HIR"神功通玄"NOR,
	HIR"五气朝元"NOR,
	HIR"旷古绝伦"NOR,
	WHT"超凡入圣"NOR,
	HIW"返璞归真"NOR,
	HIR"深不可测"NOR,
	HIR"反璞归真"NOR,
	HIY"佛法无边"NOR,
	HIY"无量虚空"NOR,
	HIY"无穷无尽"NOR,
	HIR"天下无敌"NOR,
});
string skill_level(string, int);

int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped,str;
	int i,j;
	str = "";
	seteuid(getuid());

	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看谁的技能？\n");
		if(wizardp(ob)&& !wizardp(me))
			return notify_fail("你要察看谁的技能？\n");
	}
	if( ob!=me && !wizardp(me)
		&& !ob->is_apprentice_of(me)
		&& !me->is_apprentice_of(ob)
		&& ob->query("id") != me->query("marry")
		&& ob->query("father_id") != me->query("id")
		&& ob->query("mather_id") != me->query("id"))
		return notify_fail("只有巫师、师徒关系或有亲属关系的人能察看他人的技能。\n");

	skl = ob->query_skills();
	j = (int)sizeof(skl);
	if(!sizeof(skl)) {
		write( (ob==me ? "你" : ob->name()) + "目前并没有学会任何技能。\n");
		return 1;
	}
	skl = ob->query_skills();
	sname  = sort_array( keys(skl), (: strcmp :) );
	for(i=0; i<sizeof(skl); i++){
		if(sname[i] && skl[sname[i]] < 1) ob->delete_skill(sname[i]);
	}
	write((ob==me ? "你" : ob->name()) + "目前所学过的技能有：\n");
	str = "─────────────────────────────────\n";
	sname  = sort_array( keys(skl), (: strcmp :) );

	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);

	for(i=0; i<sizeof(skl); i++) {
		str = sprintf("%s%s%s%-40s" NOR " - %-10s %3d/%5d\n", str,
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": HIY"□"NOR),
			to_chinese(sname[i]) + "(" + sname[i] + ")",
			skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
		);
	}
	str += "─────────────────────────────────\n";
	str += "                                       "+HIR+ (ob==me? "你":ob->name())+"目前共学会 "+HIW""+ chinese_number(j) + ""HIR" 种技能" NOR;
	this_player()->start_more(str);
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 14;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
指令格式 : skills|cha [<某人>]

这个指令可以让你(你)查询所学过的技能。

你也可以指定一个和你有师徒关系的对象或你的配偶，用 skills 可以查知对方的
技能状况。

巫师可以查询任何人或 NPC 的技能状况。

HELP
    );
    return 1;
}
