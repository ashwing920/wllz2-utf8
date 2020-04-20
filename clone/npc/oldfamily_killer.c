// man.c

#include <ansi.h>

inherit NPC;
void checking();
void create()
{
	set_name(npc_name("男性"),({"killer"}));
	set("attitude", "heroism");
	set("gender","男性");
	set("age", 30+random(20));
	set("str", 30);
	set("per", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 50);
	
	set("chat_chance_combat",300);
	set("chat_msg_combat", ({
		 (: command, "exert recover":),
		 (: command, "exert regenerate":),
	}));

	set("max_jing",5000);
	set("jing",5000);
	set("qi",5000);
	set("max_qi",5000);
	set("neili",2000);      
	set("max_neili", 2000);  
	set("env/wimpy",10);
	set("combat_exp",200000);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("gold",1);

}
void init()
{       
	object ob;
	if( interactive(ob = this_player()) 
	&& !this_object()->query_temp("unconcious")
	&& ob->query_condition("oldfamily_killer")) {
	command("say "+ ob->name()+"，你这个叛徒，快快受死吧！！！");
	command("follow "+ ob->query("id"));
	checking();
	}
	add_action("do_hit","hit");
	add_action("do_halt","halt");
}
int do_hit(string arg)
{
	checking();
	return 0;
}
int do_halt()
{
	if(this_player()->is_fighting(this_object()) 
	&& this_object()->is_fighting(this_player())) {
		message_vision(YEL"$N狂笑道：想逃？没那么容易！\n"NOR,this_object());
		return 1;
	}
	else 
		return 0;
}
void checking()
{
	object me, player;
	me = this_object();
	player = this_player();
	
	me->kill_ob(player);
	player->kill_ob(me);
    
	if((int)player->query_temp("powerup") 
	&& !(int)this_object()->query_temp("powerup")){
	add_temp("apply/attack",query_skill("force")/4);
	add_temp("apply/armor",query_skill("force")/4);
	set_temp("powerup",1);
	}

}
void die()
{
	message_vision("\n\n$N哀号一声：我们不会就此罢手的........\n",this_object());
	::die();
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

int heal_up()
{
	if( environment() && !is_fighting()
	&& !query_temp("unconcious")) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}
void leave()
{
	if (!environment()) return;
	destruct(this_object());
}
