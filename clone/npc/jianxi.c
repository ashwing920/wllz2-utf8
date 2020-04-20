// man.c

inherit NPC;

void create_quest(object ob);

void create(object ob)
{
	set("title","商旅");
	set_name(npc_name("男性"),({"shang lv"}));
	set("age",15+random(20));
	set("attitude", "heroism");
	set("str",30);
	set("dex",30);
	set("chat_chance_combat",150);
	set("chat_msg_combat", ({
		 (: command, "exert recover":),
		 (: command, "exert regenerate":),
	}));
	set("chat_chance",5+random(100));
	set("chat_msg",({
		(: random_move :),
	}));
	set("back_time",time()+60);
	set("env/wimpy",30);
	set_temp("apply/armor",150);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/misc/shoe")->wear();
	add_money("silver",10 + random(10));
}
int heal_up()
{
	object env;
	env = environment(this_object());

	if( env && !is_fighting()
	&& time() >= query("back_time")) {
		call_out("leave", 1);
		return 1;
	}
	if(query("chat_chance") > 10 ){
		add("chat_chance",- 5);
	}
	if(env && env->query("no_fight")){
		random_move();
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",name()+"急急忙忙地走开了。\n",environment(), this_object() );
	destruct(this_object());
}
void afterdie_func(object killer)
{
	object me,book;
	me = this_object();

	if(killer = me->query("my_killer")){
		book = new("/clone/misc/book");
		book->set_name(killer->query("quest/quest"),({"mi ji","book","shu"}));
		book->set("master",killer);
		book->move(this_object());
	}
}
void create_quest(object ob)
{
	int time,diff,exp,pot;
	
	time = 1200 + random(500) + time();
	diff = 4 + random(3);
	exp = diff * 10 + random(10);
	pot = diff * 10 + random(10);

	if(!ob || !ob->query("family")) return;

	set("family",ob->query("family"));
	set("combat_exp",(int)ob->query("combat_exp"));
	set("back_time",time);
	set("my_killer",ob);
	ob->set("quest/exp_bonus",exp);
	ob->set("quest/pot_bonus",pot);
	ob->set("quest/score",1);
	ob->set("quest/diff",diff);
	ob->set("quest/must_ask",1);
	ob->set("quest/quest_type","找");
	ob->set("quest/from","门派");
	ob->set("quest/quest",query("family/family_name")+"秘籍");
	ob->set("quest/obj",this_object());
	ob->set("quest/task_time",time);
	NPC_D->full_init(this_object());
	return;
}
