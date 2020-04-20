// danqing-sheng.c 
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("丹青生", ({ "danqing sheng", "sheng" }));
	set("title", "梅庄四庄主");
	set("long",@LONG
他就是梅庄四位庄主排行第四的丹青生。身穿一件干干净净的青色长袍。
他已年愈四旬，身材瘦长，满脸红光。恬淡冲和，沉默寡言。
LONG
);
	set("gender", "男性");
	set("age", 40);
	set("class", "scholar");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 300000);
	set("score", 60000);

	set_skill("force", 100);
	set_skill("wuzheng-xinfa", 120);
	set_skill("dodge", 100);
	set_skill("piaoyibu", 110);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("wuyun-jianfa", 100);
	set_skill("literate", 130);

	map_skill("force", "wuzheng-xinfa");
	map_skill("dodge", "piaoyibu");
	map_skill("parry", "wuyun-jianfa");
	map_skill("sword", "wuyun-jianfa");

	create_family("梅庄", 1, "庄主");

	set("inquiry", ([
		"令牌" : (: ask_me :),
	]));

	set("item_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 0) {
		command("say 我梅庄虽然不是什么名门正派, 但择徒也极为严格。");
		command("say 在品行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if ((int)ob->query_skill("wuzheng-xinfa") < 30) {
		command("say 我是不轻易收徒的。");
		command("say 在我梅庄的内功上，" + RANK_D->query_respect(ob) +
			"是否还应该多下点功夫？");
		return;
	}
	command("say 好吧，在下就收下你了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "梅庄")
		return RANK_D->query_respect(this_player()) +
		"与本派素无来往，不知此话从何谈起？";
	if (query("item_count") < 1)
		return "你来晚了，梅花令牌不在此处。";
	add("item_count", -1);
	ob = new(__DIR__"obj/lingpai");
	ob->move(this_player());
	return "好吧，这块梅花令牌就交给你保管了。";
}

