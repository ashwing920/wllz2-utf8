// su.c 苏荃

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("苏荃", ({ "su quan", "su" }));
	set("title",  HIY"神龙教"NOR"教主夫人" );
	set("long", "她就是神龙教教主洪安通的夫人。\n");
	set("gender", "女性");
	set("age", 23);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("combat_exp",6400000);
	set("score",20000);

	set_skill("force", 400);
	set_skill("hand", 400);
	set_skill("strike", 400);
	set_skill("staff", 400);
	set_skill("parry", 400);
	set_skill("dodge", 400);
	set_skill("leg",400);
	set_skill("finger",400);
	set_skill("poison",400);
	set_skill("yixingbu", 400);
	set_skill("jueming-tui",400);
	set_skill("yingxiong-sanzhao",400);
	set_skill("shenlong-bashi", 400);
	set_skill("huagu-mianzhang", 400);
	set_skill("shenlong-xinfa", 400);
	set_skill("shedao-qigong", 400);
	set_skill("sword",400);
	map_skill("finger","yingxiong-sanzhao");
	map_skill("leg","jueming-tui");
	map_skill("staff", "shedao-qigong");
	map_skill("force", "shenlong-xinfa");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-qigong");
	map_skill("dodge", "yixingbu");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("strike", "huagu-mianzhang");

	create_family("神龙教",2,"弟子");

	set("inquiry", ([
		"口号"   : "\n万年不老！永享仙福！寿与天齐！文武仁圣！\n",
	]));
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat 凭你这" + RANK_D->query_rude(this_player())+",也敢在太岁爷头上动土?\n") :),
		(: command("say 你活得不耐烦了找死啊？\n") :),
		(: perform_action, "staff.chang" :),
		(: perform_action, "staff.chang" :),
		(: perform_action, "staff.chang" :),
		(: perform_action, "staff.chang2" :),
		(: perform_action, "staff.chang2" :),
		(: perform_action, "staff.chang2" :),
		(: perform_action, "staff.chang3" :),
		(: perform_action, "staff.chang3" :),
		(: perform_action, "staff.chang3" :),
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

void init()
{
	object ob;
	if( interactive(ob = this_player()) && !is_fighting()
	&& living(this_object())
	&& !query("add_exp")) {
		remove_call_out("greeting");
		call_out("greeting",10,ob);
	}
}
void greeting(object ob)
{
	object obj;

	if( !ob || environment(ob) != environment() ) return;
	if(objectp(obj = present("usedgao", ob))){
		set("combat_exp",query("combat_exp")- 50000);
		set("add_exp",1);
	}
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("shenlong-xinfa",1) < 200 ) {
		command("say 你的本门内功心法太低了，还是努努力先提高一下吧！");
		return;
	}
	if ((int)ob->query_skill("shedao-qigong",1) < 200 ) {
		command("say 你的本门杖法太低了，还是努努力先提高一下吧！");
		return;
	}
	if ((int)ob->query("shen") > -100000  ) {
	command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}
