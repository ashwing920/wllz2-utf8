// huangzhong-gong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黄钟公", ({ "huangzhong gong", "gong" }));
	set("title", "梅庄大庄主");
	set("long",@LONG
他就是梅庄四位庄主排行第一的黄钟公。身穿一件干干净净的黄色长袍。
他已年愈六旬，身材中等，面容和蔼可亲。
LONG
);
	set("gender", "男性");
	set("age", 62);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 60000);

	set_skill("force", 150);
	set_skill("wuzheng-xinfa", 150);
	set_skill("dodge", 150);
	set_skill("piaoyibu", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("wuyun-jianfa", 150);
	set_skill("literate", 100);

	map_skill("force", "wuzheng-xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun-jianfa");
	map_skill("sword", "wuyun-jianfa");
	create_family("梅庄", 1, "庄主");
	setup();
	carry_object("clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("wuzheng-xinfa") < 120) {
		command("say 我是不轻易收徒的。");
		command("say 在我梅庄的内功上，" + RANK_D->query_respect(ob) +
			"是否还应该多下点功夫？");
		return;
	}
	command("say 好吧，在下就收下你了。");
	command("recruit " + ob->query("id"));
}

