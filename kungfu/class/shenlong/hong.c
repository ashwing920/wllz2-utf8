// hong.c 洪安通

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("洪安通", ({ "hong antong", "hong" }));
	set("title",  HIY"神龙教"NOR"教主" );
	set("nickname", HIR "永享仙福" NOR);
	set("long",@LONG
他就是武功盖世、令江湖人等谈之色变的神龙教教主洪安通。
LONG
);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 38);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);

	set_skill("force", 800);
	set_skill("hand", 800);
	set_skill("strike", 800);
	set_skill("staff", 800);
	set_skill("parry", 800);
	set_skill("dodge", 800);
	set_skill("leg",800);
	set_skill("poison",800);
	set_skill("finger",800);
	set_skill("yixingbu", 800);
	set_skill("jueming-tui",800);
	set_skill("yingxiong-sanzhao",800);
	set_skill("shenlong-bashi", 800);
	set_skill("huagu-mianzhang", 800);
	set_skill("shenlong-xinfa", 800);
	set_skill("shedao-qigong", 800);
	set_skill("sword",800);
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
	create_family("神龙教",1,"教主");

	set("inquiry", ([
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"洪安通" :  "\n你不想活了是不是?\n",
		"教主" :  "\n我就是神龙教教主。\n",
		"口号" : "\n万年不老！永享仙福！寿与天齐！文武仁圣！\n",
	]) );
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
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}
void die()
{
	message_vision("\n$N奇道：“咦,居然有人能杀了我,....”说完睁着两眼倒地死了。\n", this_object());
	::die();
}

void init()
{
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 50, ob);
	}
}
void greeting(object ob)
{
	object obj;

	if(!ob || environment(ob) != environment()) return;

	if (obj = present("usedgao", ob)){
		set("combat_exp",query("combat_exp") - 50000);
	}
	return;
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("shenlong-xinfa",1) < 400 ) {
		command("say 你的本门内功心法太低了,还是努努力先提高一下吧！");
		return;
	}
	if ((int)ob->query_skill("shedao-qigong",1) < 400 ) {
		command("say 你的蛇岛奇功太低了,还是努努力先提高一下吧！");
		return;
	}
	if ((int)ob->query("shen") > -10000  ) {
		command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}
	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}
