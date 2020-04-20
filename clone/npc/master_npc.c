// man.c

#include <ansi.h>
void make_skill();
inherit NPC;

void create()
{
	set_name("师兄",({"master"}));
	set("attitude", "heroism");
	set("age", random(20) + 20);
	set("gender","男性");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("gold", 10);
	call_out("back",300);
	add_money("gold",10 + random(10));

}
void init()
{
	if(living(this_object())){
		add_action("do_hit","hit");
		add_action("do_fight","hit");
		add_action("ansuan","hit");
		add_action("touxi","hit");
	}
}
int do_hit(string arg)
{
	object me;
	me = this_player();
	if( id(arg) && (me->query("killer_quest/name") == this_object()->query("name"))){
		me->kill_ob(this_object());
		this_object()->kill_ob(me);
		make_skill();
		return 1;
	}
}
void make_skill()
{
	string *attack;
	string exert,perform;
	int n;

	attack = this_object()->query("perform");
	n = random(sizeof(attack));
	perform = attack[n];
	attack = this_object()->query("exert");
	n = random(sizeof(attack));
	exert = attack[n];
	set("chat_chance_combat",480);
	set("chat_msg_combat", ({
		(: perform_action,perform :),
		(: exert_function, exert :),
		(: make_skill() :),
	}));
	return;
	
}
void afterdie_func(object killer)
{
	object me;
	mapping killer_quest;
	int m, n;

	me=this_object();

	if(!me) return;
	if(!(killer_quest = killer->query("killer_quest"))) return;       
	if(killer_quest["name"] != me->name()) return;

	message_vision("$N打败了$n，完成了黄泉给予的任务。\n",killer,this_object());
	
	if(killer_quest["time"] > time()) {
	n = (int)me->query("combat_exp") / 9000;
	n /= 3;
	if(n>= 3000) n = 3000;
	m = n + random(n/2);
	killer->add("potential", m);
	killer->add("combat_exp",n);
	killer->add("score",1);
	killer->add("weiwang",100);
	tell_object(killer, sprintf("你的潜能增加了%s点，经验增加了%s点！\n", chinese_number(m),chinese_number(n)));
	tell_object(killer, sprintf("你的江湖阅历增加了%s点！\n", chinese_number(1)));
	tell_object(killer, sprintf("你的江湖威望增加了%s点！\n", chinese_number(100)));
	SCORE_D->set_score(killer);
	killer->add_temp("finish_killer_quest",1);
	if(killer->query_temp("finish_killer_quest") > (random(10) + 10)){
		killer->add("combat_exp",5000);
		killer->add("weiwang",200);
		killer->delete_temp("finish_killer_quest");
		tell_object(killer,HIW"┌──────────────────────────┐\n"+
				"│"HIY"由于你连续的完成了任务："HIW"                            │\n"+
				"│"HIY"你得到了二千点武学经验的附加奖励！                 "HIW" │\n"+
				"│"HIY"你的江湖威望增长了二百点！                    ^o^  "HIW" │\n"+
				 "└──────────────────────────┘\n\n"NOR);
		}
	}
	else {
	tell_object(me,"可惜时间已经太迟了。\n");
	}
	killer->delete("killer_quest");
	killer->delete_temp("finish_killer_quest");
}
void back()
{
	if(!this_object()) return;
	destruct(this_object());
}
