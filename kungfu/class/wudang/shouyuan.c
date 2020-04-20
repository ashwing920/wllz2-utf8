// shouyuan.c 守园道长

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("守园道长", ({ "shouyuan daozhang", "shouyuan", "daozhang" }));
	set("long",@LONG
他就是这里的守园弟子守园道长。他今年四十岁，做些守园俗事。
LONG
);
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");
	set("str", 21);
	set("int", 21);
	set("con", 21);
	set("dex", 21);

	set("max_jing",500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 4000);

	set_skill("force", 100);
	set_skill("taiji-shengong", 100);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 100);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("wudang-jian", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");

	create_family("武当派", 4, "弟子");
	set("class", "taoist");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("guarded") < 1) {
		command("say " + RANK_D->query_respect(ob) +
			"你对我武当派尽了多少心力，有几分忠心呢？");
		return;
	}
	if ((int)ob->query("shen") < 0) {
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	command("recruit " + ob->query("id"));
}
