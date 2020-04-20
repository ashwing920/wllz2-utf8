// man.c

#include <ansi.h>

inherit NPC;
void checking();
void make_skill();
void create()
{
	set_name(npc_name("男性"),({"family killer","killer"}));
	set("attitude", "heroism");
	set("age", 30+random(20));
	set("str", 30);
	set("per", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 50);
	
	set("chat_chance",10);
	set("chat_msg", ({
		(: random_move :)
	}));
	set("chat_chance_combat",300);
	set("chat_msg_combat", ({
		 (: command, "exert recover":),
		 (: command, "exert regenerate":),
	}));

	set("shen_type",-1);
	set("max_jing",5000);
	set("jing",5000);
	set("qi",5000);
	set("max_qi",5000);
	set("neili",2000);      
	set("max_neili", 2000);  
	set("combat_exp",100000);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("gold",1);
	remove_call_out("back");
	call_out("back",180,this_object());

}
void init()
{       
	object ob;
	
	if( interactive(ob = this_player()) 
	&& !this_object()->query_temp("unconcious")
	&& ob->query("family/family_name") == this_object()->query_temp("to_kill")
	&& ob->query("combat_exp") >= 100000
	&& ob->query("mud_age") > 345600 ) {
		checking();
	}
	add_action("do_fight","hit");
	add_action("do_fight","touxi");
	add_action("do_fight","halt");
}
int do_fight(string arg)
{
	object ob,me;
	ob = this_object();
	me = this_player();
	
	if(id(arg)
	&& me->query("family/family_name") == ob->query_temp("to_kill")) {
		checking();
		return 1;
	}
	return 0;
}
void checking()
{
	object me, player;
	int n;
	me = this_object();
	player = this_player();

	n =(int)player->query("combat_exp");
	if( n <= 0) n = 500000;
	set("combat_exp", n);
	make_skill();
	NPC_D->full_init(this_object());
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
	mapping family;
	int m, n;

	me=this_object();
	family = killer->query("family");

	if(!family || family["family_name"] != me->query_temp("to_kill")) return;
	
	CHANNEL_D->do_channel(me,"rumor",sprintf("%s打败了%s，保护了"+ family["family_name"]+"的其他弟子。\n",killer->name(),this_object()->name()));
	n = (int)me->query("combat_exp") / 2000;
	m = n /2 + random(80);
	killer->add("potential", m);
	killer->add("combat_exp",n);
	killer->add("score",1);
	tell_object(killer, sprintf("你的潜能增加了%s点！\n", chinese_number(m)));
	tell_object(killer, sprintf("你的经验增加了%s点！\n", chinese_number(n)));
	tell_object(killer, sprintf("你的江湖阅历增加了%s点！\n", chinese_number(1)));
	SCORE_D->set_score(killer);
	CHANNEL_D->do_channel(me,"rumor",sprintf("%s被奖励了%s点潜能，%s点经验，江湖阅历提高了。",killer->name(1),chinese_number(m),chinese_number(n)));

}
int accept_fight(object ob)
{
	object me;
	me=this_object();

	if( me->is_fighting()&&!( me->is_fighting(ob))) 
		return notify_fail(me->name()+"冷笑说道：“想倚多为胜吗！”\n");

	if( (int)ob->query("combat_exp") < 100000 ){
		command("heihei");
		command("say 凭你这一点功夫，还不配与我动手！\n");
		return 0;
	}

	checking();
	if( !me->is_killing( ob->query("id") )) me->kill_ob(ob);
	return 1;
}
void back()
{
	destruct(this_object());
}
