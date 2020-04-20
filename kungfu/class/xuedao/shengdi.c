//shengdi.c  胜谛

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("胜谛", ({ "sheng di", "sheng", "di" }));
	set("long",@LONG
这是一个身形魁梧的西藏僧人，神色冷漠。武功是同门中最高的一人。
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

	set("jing",2000);
	set("max_jing",2000);
	set("neili", 3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp", 800000);
	set("score",50000);

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

	set_skill("lamaism", 200);
	set_skill("literate", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("blade", 200);
	set_skill("dodge", 200);
	set_skill("xuehai-mogong", 200);
	set_skill("xuedun", 200);
	set_skill("strike", 200);
	set_skill("miexian-zhang", 200);
	set_skill("xue-dao", 200);
	set_skill("unarmed",200);
	set_skill("wuying-shenquan",200);
	map_skill("unarmed","wuying-shenquan");
	map_skill("force", "xuehai-mogong");
	map_skill("dodge", "xuedun");
	map_skill("strike", "miexian-zhang");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");

	create_family("血刀门",5,"弟子");
	set("class", "bonze");

	setup();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
	carry_object("/d/xuedao/obj/xblade1")->wield();

	add_money("gold",1);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") != "男性"){
		command("say 我不收女徒弟，你回去吧！");
		return;
	}
	if (ob->query("shen") > -10000) {
		command("say 看来我还要先教你如何心狠杀人。\n");
		return;
	}
	if ((int)ob->query_skill("xuehai-mogong",1) < 100){
		command("say 入我血刀门，修习血海魔功是首要的。\n");
		return;
	}
	if(((int)ob->query("MKS") + (int)ob->query("PKS")) < 1000){
		command("say 学习血海魔功必须心狠手辣，看来你还做得不够呀！\n");
		return;
	}
	command("haha");
	command("recruit " + ob->query("id"));
}
