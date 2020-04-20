// xuedao.c  血刀老祖

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("血刀老祖", ({ "xuedao laozu", "xue dao", "laozu" }));
	set("long",@LONG
这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第
四代掌门。
LONG
);
	set("gender", "男性");
	set("age", 85);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);

	set_skill("lamaism", 800);
	set_skill("literate", 800);
	set_skill("force", 800);
	set_skill("parry", 800);
	set_skill("blade", 800);
	set_skill("dodge", 800);
	set_skill("xuehai-mogong", 800);
	set_skill("xuedun", 800);
	set_skill("strike", 800);
	set_skill("miexian-zhang", 800);
	set_skill("xue-dao", 800);
	set_skill("unarmed",800);
	set_skill("wuying-shenquan",800);
	map_skill("unarmed","wuying-shenquan");
	map_skill("force", "xuehai-mogong");
	map_skill("dodge", "xuedun");
	map_skill("strike", "miexian-zhang");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "blade.jtmd" :),
		(: perform_action, "strike.xue" :),
		(: perform_action, "strike.jue" :),
		(: perform_action, "unarmed.luan" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	create_family("血刀门",2,"掌门");
	set("class", "bonze");
	set("inquiry", ([
		"秘籍" : (: ask_me :),
	]));
	set("book_count", 1);
	setup();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
	carry_object("/d/xuedao/obj/xblade")->wield();

	add_money("gold",2);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") != "男性"){
		command("say 我不收女徒弟。\n");
		return;
	}
	if ((string)ob->query("family/family_name") != "血刀门"){
		command("say 这位" + RANK_D->query_respect(ob) +"既非本门弟子，还是请回吧！");
		return;
	}
	if ((int)ob->query("shen") > - 100000){
		command("say 你是不是向着侠义道，连杀人都不会！");
		return;
	}
	if ((int)ob->query_skill("xuehai-mogong", 1) < 400){
		command("say 入我血刀门，修习血海魔功是首要的。");
		return;
	}
	command("haha");
	command("recruit " + ob->query("id"));
}
string ask_me()
{
	mapping fam;
	object ob;
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "血刀门")
		return RANK_D->query_respect(this_player()) + "与本门素无来往，想死？";
	if (query("book_count") < 1)
		return "你来晚了，本门秘籍不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/zhoutiantu");
	ob->move(this_player());
	message("channel:rumor",HIM"【武林传奇】某人：听说"+ this_player()->name()+"从血刀老祖那里拿到「周天图」了！\n"NOR,users());
	return "好吧，这本「周天图」你拿回去好好钻研。";
}


