// zhixiang.c 制香道长

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("制香道长", ({ "zhixiang daozhang", "zhixiang", "daozhang" }));
	set("long",@LONG
他就是武当的制香道长。每天来武当烧香的人太多了，他和他手下的几个
伐木道士都忙不过来了。他今年四十岁。
LONG
);
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("jing",1000);
	set("max_jing",1000);
	set("neili",1500);
	set("max_neili",1500);
	set("jiali",75);
	set("combat_exp",100000);
	set("score",5000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 100);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 100);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("wudang-jian", 100);
	set_skill("taoism",100);
	set_skill("literate",100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");

	create_family("武当派", 5, "弟子");
	set("class", "taoist");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("guarded") < 1) {
		command("say " + RANK_D->query_respect(ob) +"你对我武当派尽了多少心力，有几分忠心呢？");
		return;
	}
	if ((int)ob->query("shen") < 0) {
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	command("recruit " + ob->query("id"));
}
