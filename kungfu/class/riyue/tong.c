#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("童百熊", ({ "tong baixiong", "tong",}));
	set("long",@LONG
一名须法俱白的老者，身材魁梧，双目炯炯有神，他掌管着日月教风雷堂
，负责着教中所有对外的事务。
LONG
);
	set("title",HIY"日月神教风雷堂主"NOR);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("max_jing",2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",150);
	set("combat_exp",800000);

	set_skill("sword", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("force",200);
	set_skill("tianmo-zhang",200);
	set_skill("strike", 200);
	set_skill("tianmo-sword",200);
	set_skill("literate", 200);
	set_skill("blade", 200);
	set_skill("piaomiao-shenfa",200);
	set_skill("tianmo-dafa",200);
	set_skill("xixing-force",200);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "tianmo-sword");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	create_family("日月神教",3,"弟子");
	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("parry",1) < 100) {
		command("say 习武之人，最主要练好基本功。");
		command("say " + RANK_D->query_respect(ob) + "是否还应该在基本招架上多下点功夫？");
		return;
}
	 if (ob->query_dex() < 26) {
		command("say " + RANK_D->query_respect(ob) +"身手不捷，还是另求高师吧。");
		return;
	}
	command("say 哈哈！ 那我就收下你吧。");
	command("recruit " + ob->query("id"));
	ob->set("nickname",HIG"日月神教风雷堂弟子"NOR);
}
