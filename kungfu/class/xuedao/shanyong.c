// shanyong.c  善勇

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("善勇", ({ "shan yong", "shan", "yong" }));
	set("long",@LONG
一个胖胖的西藏僧人，面带笑容，却常干笑里藏刀的事。
LONG
);
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",3000);
	set("max_jing", 3000);
	set("neili", 4500);
	set("max_neili",4500);
	set("jiali",225);
	set("combat_exp", 2700000);
	set("score",10000);

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

	set_skill("lamaism", 300);
	set_skill("literate", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
	set_skill("dodge", 300);
	set_skill("xuehai-mogong", 300);
	set_skill("xuedun", 300);
	set_skill("strike", 300);
	set_skill("miexian-zhang", 300);
	set_skill("xue-dao", 300);
	set_skill("unarmed",300);
	set_skill("wuying-shenquan",300);
	map_skill("unarmed","wuying-shenquan");
	map_skill("force", "xuehai-mogong");
	map_skill("dodge", "xuedun");
	map_skill("strike", "miexian-zhang");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");

	create_family("血刀门", 4, "弟子");
	set("class", "bonze");

	setup();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
	carry_object("/d/xuedao/obj/xblade1")->wield();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") != "男性"){
		command("say 我不收女徒弟。");
		return;
	}
	if ((int)ob->query_skill("xuehai-mogong", 1) < 200){
		command("say 入我血刀门，修习血海魔功是首要的。\n");
		return;
	}
	if ((int)ob->query("shen") > - 20000){
		command("say 你是不是向着侠义道，连杀人都不会！\n");
		return;
	}
	if((int)ob->query("MKS") < 1000 ){
		command("say 学习血海魔功必须心狠手辣，看来你还做得不够呀！\n");
		return;
	}
	command("haha");
	command("recruit " + ob->query("id"));
}
