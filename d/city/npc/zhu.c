// zhu.c 朱熹

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

string ask_buy();
int ask_degree();
void create()
{
	set_name("朱熹", ({ "zhu xi", "zhu" }));
	set("title","当代圣人");
	set("nickname",HIY"破万卷"NOR);
	set("long",@LONG
朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。
LONG
);
	set("gender", "男性");
	set("age", 65);
	set("max_qi",20000);
	set("qi",20000);
	
	set_skill("literate", 800);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage", 120);

	set("combat_exp",1600000);
	set("shen_type", 1);
	set("chat_chance",2);
	set("chat_msg", ({
		"朱熹说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		"朱熹说道：大学之道，在明明德。在亲民，在止于至善。 \n",
		"朱熹说道：格物致知，诚意正心，修身齐家，治国平天下。\n", 
	}));
	set("inquiry", ([
		"买书" : (:ask_buy:),
		"书"   : "唉！书到用时方恨少。",
		"借书" : "借？你不还我到哪里找你？哼！",
	]));
	set("vendor_goods", ([
		"/clone/book/lbook1": 20,
		"/clone/book/lbook2": 20,
		"/clone/book/lbook3": 20,
	]));
	setup();
}

void init()
{          
	object ob; 
	ob = this_player();
	
	if( interactive(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",1, ob);
	}
	add_action("do_vendor_list","list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	command("say 书院图书馆来了一部《蜀山剑侠传》，这位"+ RANK_D->query_respect(ob)+"快去看看吧！");
	return;
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/朱"))
		return 0;
	ob->add_temp("mark/朱", -1);
	return 1;
}

int accept_object(object who, object ob)
{

	if (!(int)who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/朱", ob->value() / 10);
		return 1;
	 }
}
string ask_buy()
{
	return "我这可有不少读书人必读的书哟！\n";
}
