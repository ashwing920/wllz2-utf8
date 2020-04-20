// nuselang.c - 马夫人

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("马夫人", ({ "ma furen", "ma" }) );
	set("title","丐帮马大元的"HIM"遗孀"NOR);
	set("long", @LONG
她就是丐帮马大元的遗孀。她是一位出了名的荡妇。
LONG
);
	set("attitude", "heroism");
	set("gender", "女性" );
	set("age",32);
	set("per",25);
	set("str",1000);
	set("chat_chance",20);
	set("class","dancer");
	set("chat_msg",({
		(: random_move :),
	}));
	set("combat_exp",30000);
	set("shen_type",-1);
	set("env/wimpy", 30);

	set_skill("unarmed",30); 
	set_skill("parry",30);
	set_skill("dodge",150);
	setup();        
	carry_object("/clone/cloth/pink-silk")->wear(); 
	add_money("silver",10);
}

void init()
{       
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	object me;

	me = this_object();
	if( !ob || environment(ob) != environment() ) return;           
	switch( random(3) ) {
		case 0:
			if( ob->query("gender") == "男性" && ob->query("per") >= me->query("per") ) {
				me->set_leader(ob);
				message_vision("$N似乎打算跟随$n一起行动。\n", me, ob);
			}
			break;
		case 1:
			if( ob->query("gender") == "男性" ) {
				say(me->query("name") + "色迷迷地叫道：亲亲的" + ob->query("name") + "哥哥好啊～～～\n" );
			}
			break;
	}
}
