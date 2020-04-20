// rascal.c

#include <ansi.h>

inherit NPC;

void create()
{
	int level;
	set_name(npc_name("男性"),({"heiyi ren","robber"}));
	set("nickname",HIK"一剑无"HIR"血"HIK"之"HIW"刺客"NOR);
	set("gender","男性");
	set("long",@LONG
他身着黑色夜行衣，头戴黑色头巾，手持长剑，蒙着脸，你只能看到他那
一双冷酷的颜色，不时透出丝丝杀气。
LONG
);
	set("attitude", "heroism");
	set("age", random(20) + 30);
	set("str", 20 + random(11));
	set("cps", 20 + random(11));
	set("cor", 20 + random(11));
	set("per", 20 + random(11));
	set("int", 20 + random(11));
	set("con", 20 + random(11));
	set("spi", 20 + random(11));
	set("kar", 20 + random(11));

	set("chat_chance_combat",5);
	set("chat_msg_combat", ({
		sprintf("%s喝道：顺我者昌，逆我者亡，受死吧！！\n", name()),
	}) );
	set("chat_chance",5);
	set("chat_msg", ({
		(: random_move :)
	}));

	set("jing",2000);
	set("max_jing",2000);
	set("max_qi",4000);
	set("qi",4000);
	set("neili",5000);
	set("max_neili",5000);
	set("jiali",200);
	set("shen_type",5);
	set("bellicosity",8000);

	level = 100 + random(100);
	set_skill("literate", level);
	set_skill("force", level);
	set_skill("dodge", level);
	set_skill("unarmed", level);
	set_skill("parry", level);
	set_skill("whip", level);
	set_skill("sword", level);
	set_skill("hand", level);
	set_skill("claw", level);

	set_skill("sword",level);
	set_skill("unarmed",level);
	set_skill("force",level);
	set_skill("perception",level);
	set_skill("songshan-sword", level);
	set_skill("sanyin-unarmed", level);
	set_skill("yaoming-dodge", level);
	set_skill("songshan-qigong",level);

	map_skill("dodge","yaoming-dodge");
	map_skill("force","songshan-qigong");
	map_skill("unarmed", "sanyin-unarmed");
	map_skill("sword","songshan-sword");
	map_skill("parry","songshan-sword");

	set("combat_exp",500000 + (100000 * random(10)));
	setup();
	carry_object("/clone/cloth/black-cloth")->wear();
	carry_object("/clone/weapon/sword")->wield();
	add_money("silver",50);
	remove_call_out("back");
	call_out("back",300,this_object());
}
void init()
{
	object ob;
	ob = this_player();

	if(ob->query("family") && (string)ob->query("family/family_name") == "恒山派"){
		ob->kill_ob(this_object());
		this_object()->kill_ob(ob);
		this_object()->set_leader(ob);
	}
}
void afterdie_func(object killer)
{
	if(!killer) return;
	killer->add_temp("save_hengshan",1);
}
void back()
{
	if(!this_object() || !environment(this_object())) return;
	message_vision("$N见没得手，骂骂咧咧的离开了。\n",this_object());
	destruct(this_object());
}
