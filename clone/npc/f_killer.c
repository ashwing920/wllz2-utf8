// f_killer.c
// 门派杀手

#include <ansi.h>

inherit NPC;
void checking();
void create()
{
	set_name(npc_name("男性"),({"killer"}));
	set("gender","男性");
	set("attitude", "heroism");
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
	&& ob->query_condition("f_killer")) {
	command("say "+ ob->name()+"，你杀我同门，纳命来！！！");
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
	message_vision("\n\n$N一声惨嚎：我们"+ this_object()->query("family/family_name")+"的师..尊们...不会放..过你的....\n",this_object());
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
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}
void leave()
{
	if (!environment()) return;
	message("vision",name() +"见没有得手，忿忿的离开了。\n",environment(),this_object());
	destruct(this_object());
}
