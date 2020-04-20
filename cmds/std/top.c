// top.c

#include <ansi.h>

inherit F_CLEAN_UP;

int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{

	object *list,*ob;
	int i,num;
	string msg;

	if(me->ban_say()) return 0;
	if(!wizardp(me)){
		if((int)me->query("jing") < (int)me->query("eff_jing")  / 10 )
			return notify_fail("你的精神太差了，没有办法得知其他玩家的资料。\n");
		me->receive_damage("jing",(int)me->query("eff_jing")/ 20);
	}

	ob = filter_array(children(USER_OB), (: userp($1) && !wizardp($1) :));

	if(!arg || (sscanf(arg,"%d",num ) != 1)) 
		num = 20;
	if(num > sizeof(ob)) num = sizeof(ob);

	if(num < 1 )
		return notify_fail("指定排行不能为零。\n");

	list = sort_array(ob, (: top_list :));
	msg = "\n";
	msg += "      ┏ "+ code_name() + "在线高手排行榜 ┓\n";
	msg += "┏━━┻┯━━━━━━━━━━┯━━━━┯┻━━━┓\n";
	msg += "┃ 名次 │    高        手    │ 门  派 │ 评  价 ┃\n";
	msg += "┠───┴──────────┴────┴────┨\n";
	for (i = 0 ;i < num ; i++) {
	if( i >= sizeof(list)) msg += "┃暂时空缺。                                      ┃\n";
		else {
		if(list[i] == me) msg += BBLU HIY;
		msg += sprintf("┃第%3d名  %-21s%-10s %5d  ┃\n"NOR,
		(i+1),list[i]->name(2),
		list[i]->query("family")? list[i]->query("family/family_name"):"普通百姓",
		get_score(list[i]));
		}
	}
	msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	msg += "  " + NATURE_D->game_time() + "记。\n";
	me->start_more(msg);
	return 1;

}
int top_list(object ob1, object ob2)
{
	int score1,score2;
	score1 = get_score(ob1);
	score2 = get_score(ob2);
	return score2 - score1;
}

int get_score(object ob)
{
	int tlvl,i,score;
	string *ski;
	mapping skills;

	reset_eval_cost();
	skills = ob->query_skills();
	if (!sizeof(skills)) return 1;
	ski  = keys(skills);
	for(i = 0; i<sizeof(ski); i++) {
		tlvl += skills[ski[i]];
	}  // count total skill levels
	score = tlvl/10;
	score += (int)ob->query("max_neili") / 100;
	score += (int)ob->query("combat_exp")/ 5000;
	score += (int)ob->query("score") / 100;
	score += (int)ob->query("weiwang") / 100;
	return score;
}

int help(object me)
{

write(@HELP
指令格式 : top

这个指令可以让你查阅目前在线的前二十名高手。该排行以经验、内力修为、
江湖威望和江湖阅历加以累计再进行排行。你也可以查询排行，为你想要查询
的排名位数。如：top 200 或 top 10。

HELP
    );
    return 1;
}
