// master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
	set("nickname", "九指神丐");
	set("gender", "男性");
	set("age", 75);
	set("long",@LONG
他就是丐帮第十七任帮主，号称“北丐”的洪七公老爷子。虽然已经七十
多岁的人了，仍然鹤发童颜，身体十分硬朗。
LONG
);
	set("attitude", "peaceful");
	set("class", "beggar");

	set("str", 30);
	set("int", 24);
	set("con", 30);
	set("dex", 24);

	set("chat_chance",5);
	set("chat_msg", ({
		"洪七公叹了口气道：“唉……何时能再吃到蓉儿做的「叫化鸡」啊……”\n",
		"洪七公说道：“俗话说「吃在江南」，所以老叫化特地跑来扬州看看。”\n",
		"洪七公喃喃道：“我们丐帮的「降龙十八掌」是天下最霸道的掌法。”\n",
	}));

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);
	set("shen_type",1);
	set("food",1);
	set("water",1);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action,"staff.tianxia" :),
		(: perform_action,"staff.chan" :),
		(: perform_action,"parry.qunmo" :),
		(: perform_action,"unarmed.slzy" :),
		(: exert_function, "powerup" :),
		(: exert_function, "shengang" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("force", 800);
	set_skill("huntian-qigong", 800);
	set_skill("unarmed", 800);
	set_skill("xianglong-zhang",800);
	set_skill("dodge", 800);
	set_skill("xiaoyaoyou",800);
	set_skill("parry", 800);
	set_skill("staff", 800);
	set_skill("dagou-bang",800);
	set_skill("begging", 800);
	set_skill("checking", 800);
	set_skill("training", 800);
	set_skill("hand",800);
	set_skill("shexing-diaoshou",800);
	set_skill("blade",800);
	set_skill("liuhe-daofa",800);
	set_skill("staff",800);
	set_skill("fengmo-zhang",800);
	map_skill("parry","fengmo-zhang");
	map_skill("hand","shexing-diaoshou");
	map_skill("blade","liuhe-daofa");
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("staff", "dagou-bang");

	create_family("丐帮", 17, "帮主");
	setup();

	carry_object(__DIR__"obj/yuzhu_zhang")->wield();
	carry_object("clone/cloth/cloth")->wear();
	carry_object(__DIR__"obj/jiaohuaji");
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 20 || (int)ob->query_con() < 20) {
		command("say 当叫化子需要能吃苦耐劳，依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合当叫化子？");
		return;
	}
	if(this_player()->query_temp("jiahuoji")) {
		command("haha");
		command("say 想不到你小小年纪，心思却很细，就跟当年的蓉儿一样！好吧，我就收下你！\n");
		command("recruit " + ob->query("id"));
		if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
	}
	else {
	command("say " + RANK_D->query_respect(ob) + "各项条件都不错，只可惜老叫化现在没力气收徒……");
	return;
	}
}

int accept_object(object who, object ob)
{
	if (ob->query("food_supply") <= 0)
		return 0;
	if ((string)ob->query("id") != "jiaohua ji") {
		command("say 老叫化对" + (string)ob->query("name") + "没什么兴趣……");
		return 0;
	}
	if (query("food") >= max_food_capacity() - ob->query("food_supply")) {
		command("say 老叫化现在饱得很。");
		return 0;
	}
	command("say 啊……这正是我想吃的叫化鸡呀！");
	command("eat ji");
	command("smile");
	who->set_temp("jiahuoji",1);
	return 1;
}