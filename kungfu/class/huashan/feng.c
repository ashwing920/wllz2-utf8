// feng.c 风清扬

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("风清扬", ({ "feng qingyang", "feng", "qingyang" }));
	set("title", "华山第十二代剑宗长老");
	set("long", @LONG
这便是当年名震江湖的华山名宿风清扬。他身著青袍，神气抑郁脸如金纸
。身材瘦长，眉宇间一直笼罩着一股淡淡的忧伤神色，显然对当年的剑宗
气宗之争一直难以忘怀。
LONG
);
	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);

	set("combat_exp",51200000);

	set_skill("unarmed",800);
	set_skill("cuff", 800);
	set_skill("force", 800);
	set_skill("blade", 800);
	set_skill("dodge", 800);
	set_skill("parry", 800);
	set_skill("sword", 800);
	set_skill("strike", 800);
	set_skill("huashan-neigong",800);
	set_skill("poyu-quan", 800);
	set_skill("fanliangyi-dao", 800);
	set_skill("huashan-sword", 800);
	set_skill("hunyuan-zhang", 800);
	set_skill("lonely-sword", 800);
	set_skill("feiyan-huixiang",800);
	set_skill("literate", 800);

	map_skill("cuff", "poyu-quan");
	map_skill("force", "huashan-neigong");
	map_skill("dodge", "feiyan-huixiang");
	map_skill("parry", "lonely-sword");
	map_skill("sword", "lonely-sword");
	map_skill("blade", "fanliangyi-dao");
	map_skill("strike", "hunyuan-zhang");

	create_family("华山剑派", 12, "弟子");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.poqi" :),
		(: perform_action, "sword.pozhang" :),
		(: perform_action, "sword.pojian" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("betrayer") )
	{
		command("say 依我看" + RANK_D->query_respect(ob) + "好象拜过别派的师傅？想来你也不适合学独孤九剑？");
		return;
	}
	if ((int)ob->query("mud_age") - (int)ob->query("feng_dietime") < 259200 )
	{
		command("say " + RANK_D->query_respect(ob) + "你好象原来是我的徒弟麽？");
		return;
	}

	if ((string)ob->query("family/family_name") != "华山剑派")
	{
		command("say " + RANK_D->query_respect(ob) + "既然已有名师指点，何必又来拜老朽呢？");
		return;
	}

	if (((int)ob->query_skill("sword",1) < 200) || ((int)ob->query_skill("huashan-sword",1) < 200))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的华山剑法还没学到家吧。");
		return;
	}
	if (((int)ob->query_skill("force",1) < 200) || ((int)ob->query_skill("huashan-neigong",1) < 200))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的华山内功还没学到家吧。");
		return;
	}
	if (((int)ob->query_skill("dodge",1) < 200) || ((int)ob->query_skill("feiyan-huixiang",1) < 200))
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的飞燕回翔还没学到家吧。");
		return;
	}
	if ( (int)ob->query_skill("literate",1) < 100)
	{
		command("say 我看" + RANK_D->query_respect(ob) + "的读书识字还没学到家吧。");
		return;
	}

	if ((int)ob->query("shen") < 150000)
	{
		command("say 我华山剑派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}

	if ((int)ob->query("kar") < 28)
	{
		command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我独孤九剑？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "swordsman")
	ob->set("class", "swordsman");
}
