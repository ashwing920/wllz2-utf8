// man.c

#include <ansi.h>

inherit NPC;

void create_quest(object ob);

void create()
{
	set_name(npc_name("男性"),({"pan tu"}));
	set("attitude", "heroism");
	set("chat_chance_combat",150);
	set("str",30);
	set("dex",30);
	set("chat_msg_combat", ({
		 (: command, "exert recover":),
		 (: command, "exert regenerate":),
	}));
	set("chat_chance",5 + random(100));
	set("chat_msg",({
		(: random_move :),
	}));
	set("back_time",time()+60);
	set_temp("apply/armor",150);
	set("env/wimpy",30);
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
void create_quest(object ob)
{
	int time,diff,exp,pot;

	time = 1200 + random(500) + time();
	diff = 4 + random(3);
	exp = diff * 10 + random(10);
	pot = diff * 10 + random(10);

	if(!ob || !ob->query("family")) return;

	set("family",ob->query("family"));
	set("title",query("family/family_name")+"叛徒");
	set("combat_exp",(int)ob->query("combat_exp"));
	set("back_time",time);
	ob->set("quest/exp_bonus",exp);
	ob->set("quest/pot_bonus",pot);
	ob->set("quest/score",1);
	ob->set("quest/diff",diff);
	ob->set("quest/must",1);
	ob->set("quest/quest_type","拿");
	ob->set("quest/from","门派");
	ob->set("quest/quest",HIR + this_object()->name(1)+"的头颅"NOR);
	ob->set("quest/obj",this_object());
	ob->set("quest/task_time",time);
	NPC_D->full_init(this_object());
	return;
}
