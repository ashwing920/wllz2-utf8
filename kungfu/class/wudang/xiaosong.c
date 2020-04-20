// xiaosong.c 宋青书

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("宋青书", ({ "song qingshu", "song" }));
	set("long", @LONG
他就是宋远桥的儿子宋青书。他今年二十岁，乃是武当第三代中出类拔萃
的人物。
LONG
);
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 0);
	set("str", 25);
	set("int", 28);
	set("con", 25);
	set("dex", 25);
	
	set("jing",2000);
	set("max_jing", 2000);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",150);
	set("combat_exp",800000);
	set("score", 10000);

	set_skill("force", 200);
	set_skill("taiji-shengong", 200);
	set_skill("dodge", 200);
	set_skill("tiyunzong", 200);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("taiji-jian", 200);
	set_skill("taoism", 200);
	set_skill("literate", 200);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 3, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("guarded") < 3) {
		command("say " + RANK_D->query_respect(ob) +
			"你对我武当派尽了多少心力，有几分忠心呢？");
		return;
	}
	if ((int)ob->query_skill("taiji-shengong", 1) < 100) {
		command("say 我武当派乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +"是否还应该在太极神功上多下点功夫？");
		return;
	}
	if ((int)ob->query("shen") < 10000) {
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say " + RANK_D->query_respect(ob) + "若能做出" +"几件侠义之事，我一定收你。");
		return;
	}
	command("say 好吧，既然" + RANK_D->query_respect(ob) + "也是" +	"我辈中人，今天就收下你吧。");
	command("recruit " + ob->query("id"));
}
