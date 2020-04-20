// guxu.c 谷虚

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("谷虚道长", ({ "guxu daozhang", "guxu" }));
	set("long", @LONG
他就是俞莲舟的弟子谷虚道长。他今年四十岁，主管武当派的俗事。
LONG
);
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "taoist");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	
	set("jing",3000);
	set("max_jing", 3000);
	set("neili", 1000);
	set("max_neili",1000);
	set("jiali",50);
	set("combat_exp",100000);
	set("score", 8000);

	set_skill("force",100);
	set_skill("taiji-shengong", 100);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 100);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("wudang-jian", 100);
	set_skill("taoism", 100);
	set_skill("literate", 100);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "wudang-jian");
	map_skill("sword", "wudang-jian");

	create_family("武当派", 3, "弟子");
	set("class", "taoist");

	set("inquiry", ([
			"道德经" : (: ask_me :),
	]));
				
	set("book_count", 8);

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

string ask_me()
{
	object ob;
	if (query("book_count") < 1)
		return "你来晚了，本派的道德真经不在此处。";
		  if (this_player()->query_temp("jing") > 0) return " 你不是已经有了吗\n";
	add("book_count", -1);
		   if ((int)this_player()->query_skill("taoism",1) < 50)
			 ob = new("/clone/book/daodejing-i");
			else ob = new("/clone/book/daodejing-ii");
		   this_player()->set_temp("jing",1);
	ob->move(this_player());
	return "好吧，这本「道德经」你拿回去好好钻研。";
}
