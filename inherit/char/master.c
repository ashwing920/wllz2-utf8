
//#pragma optimize
//#pragma save_binary

#include <ansi.h>
#include <dbase.h>

int is_master() { return 1;}

int prevent_learn(object me, string skill)
{
	int betrayer;
	object ob;
	ob = this_object();

	if( betrayer = me->query("betrayer") )
	{
		if( me->query_skill(skill, 1) >= this_object()->query_skill(skill, 1) - betrayer * 20 ) {
			message_vision("$N神色间似乎对$n不是十分信任，也许是想起$p从前背叛师门的事情 ...。\n",
				this_object(), me );
			command("say 嗯 .... 师父能教你的都教了，其他的你自己练吧。");
			return 1;
		}
	}

	if( !me->is_apprentice_of(this_object())
	&&      (int)this_object()->query_skill(skill, 1) <= (int)me->query_skill(skill, 1) * 3 ) {
		command("hmm");
		command("pat " + me->query("id"));
		command("say 虽然你是我门下的弟子，可是并非我的嫡传弟子 ....");
		command("say 我只能教你这些粗浅的本门功夫，其他的还是去找你师父学吧。");
		return 1;
	}
	return 0;
}
void afterdie_func(object killer)
{
	object me;
	mapping fam,myfam;
	me = this_object();

	if(mapp(fam = killer->query("family"))
	&& mapp(myfam = me->query("family"))
	&& fam["family_name"] == myfam["family_name"]){
		tell_object(killer,HIR"你欺师灭祖，做下大逆不道之事，你的江湖威望降低了。\n"NOR);
		if(fam["master_id"] == (string)me->query("id"))
			killer->add("weiwang",-10000);
		else
			killer->add("weiwang",-1000);
	}
}
