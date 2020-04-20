// check.c

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
	WHT"登堂入室"NOR,
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
	WHT"登堂入室"NOR,
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
	object ob, man, *all;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp;
	int i, cost, check_level;

	seteuid(getuid());

	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++) {
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}

	if ( (!(fam = me->query("family")) || fam["family_name"] != "丐帮") )
		return notify_fail("你想要打探一些消息，心里却总是觉得缺了点什么。\n");

	if ( !objectp(man) )
		return notify_fail("周围没人能帮你去了解别人的技能！\n");

	if ( me->query_skill("checking",1) < 10 )
		return notify_fail("你的打探本领尚未纯熟，无法了解别人的技能！\n");

	if ( !arg)
		return notify_fail("你要打听谁的技能？\n");

	if ( present(arg, environment(me)) )
		return notify_fail("你要打听的人就在边上，在这里问不大妥当吧？\n");

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob) return notify_fail("你要打听谁的技能？\n");
	if((wizardp(ob) || !me->visible(ob)) && !wizardp(me))
		return notify_fail("你要打听谁的技能？\n");
	if ( ob == me )
		return notify_fail("你没这麽笨吧，要别人告诉你自己的技能？\n");

	cost = me->query("max_jing")/(me->query_skill("checking",1)/10) - 10;

	if ( me->query("jing") <= cost )
		return notify_fail("现在你太累了，无法去打听别人的技能。\n");

	tell_object(me, "你走上前去，小心翼翼地向" + man->name() + "打听关于" + ob->name() + "的情况 ...\n\n");
	message("vision", "只见" + me->name() + "陪着笑脸跟" + man->name() + "说着话，好象在打听些什么。\n\n",
		environment(me), ({ me, man }) );

	sp = me->query_skill("checking")*10 + me->query("kar")*5 + me->query("jing") + man->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;

	if ( random(sp) < random(dp) || ob->query("id") == "princess")
		return notify_fail( man->name() + "摇了摇头，说道：这事我可不清楚，"
			+ RANK_D->query_respect(me) + "还是去向别人打听一下吧！\n");

	me->receive_damage("jing", cost );

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( man->name() + "告诉你： " + ob->name() + "目前并没有学会任何技能。\n");
		return 1;
	}
	write( man->name() + "告诉你： " + ob->name() +"目前所学过的技能：\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );

	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);

	i = random(sizeof(skl));

	write(sprintf("%s%s%-40s" NOR " - %-10s %3d/%5d\n",
		(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": "□"),
		to_chinese(sname[i]) + " (" + sname[i] + ")",
		skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
		skl[sname[i]], (int)lrn[sname[i]],
	));
	check_level = me->query_skill("checking", 1);
	if ( (int)me->query("combat_exp") > (check_level*check_level*check_level)/10)
	{
		me->improve_skill("checking", random(me->query("int")));
	}

	write("\n");
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
指令格式 : check|dating [<某人>]

这个指令可以让你打听别人所学过的技能。

你也可以指定一个和你有师徒关系的对象，用 skills|cha 可以查知对方的技能状况。

此命令为丐帮弟子专用，并需学习相应的技能。

HELP
	);
	return 1;
}

