// Killer.c 杀手
#include <ansi.h>

inherit NPC;

void greeting(object ob);
void reset_status();

void create()
{
	set_name(npc_name("男性"), ({"killer"}));
	set("nickname",HIR"杀手"NOR);
	set("long",@TEXT
这是一个身材高大的江湖人，两臂粗壮，膀阔腰圆，看起来似乎不怀好意。
TEXT
);
	set("title",HIY"赏金猎人"NOR);
	set("gender", "男性");
	set("attitude", "aggressive");
	set("class", "alchemist");
	set("type","killer");

	set("age", 20+random(30));
	set("shen_type", 0);

	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("int", 25+random(10));
	set("con", 25+random(10));

	set("jiaji", 50+random(100));
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: command("exert recover") :),
		(: command("exert regenerate"):),
	}) );
	set("combat_exp", 1000000+random(1000000));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	object ob;

	if( interactive(ob = this_player())
		&& ob->query("id") == query("victim")) {
		greeting(ob);
	}
}
void greeting(object ob)
{
	object me;
	me = this_object();

	if(!ob || environment(ob) != environment()) return;

	if(environment()->query("no_fight")
		&& !query("set_room")){
			environment()->delete("no_fight");
			set("set_room",environment());
			environment()->set("set_can_fight",1);
	}
	command("say 受人钱财，替人消灾，你怨不得我，受死吧！！");
	command("exert powerup");
	me->set_leader(ob);
	command("kill "+ ob->query("id"));
	ob->kill_ob(me);
	me->delete("victim");
	return;
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
	message("vision",HIR+"\n\n"+ name()+"拍拍身上的尘土，施展绝顶轻功，纵身跃起，消失在人群中。\n" NOR,
		environment(), this_object() );
	reset_status();
	destruct(this_object());
}
void reset_status()
{
	object room;

	if(objectp(room = query("set_room"))
		&& room->query("set_can_fight")){
		room->set("no_fight",1);
	}
}
void die()
{
	reset_status();
	::die();
}