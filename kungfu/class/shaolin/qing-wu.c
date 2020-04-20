// Npc: /kungfu/class/shaolin/qing-wu.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("清无比丘", ({"qingwu biqiu","qingwu","biqiu",}));
	set("long",@LONG
他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含着无穷劲
力。他身穿一袭白布黑边袈裟，似乎身怀武艺。
LONG
);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 23);
	set("int", 17);
	set("con", 20);
	set("dex", 24);

	set("max_jing",800);
	set("neili",1500);
	set("max_neili",1500);
	set("jiali",75);
	set("combat_exp",100000);
	set("score",100);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("blade", 100);
	set_skill("cibei-dao", 100);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

	create_family("少林派", 40, "弟子");

	setup();

	carry_object("/d/shaolin/obj/jiedao")->wield();
	carry_object("/d/shaolin/obj/qing-cloth")->wear();
}


void attempt_apprentice(object ob)
{
	if( (string)ob->query("gender") != "男性" )
	{
		command ("say 阿弥陀佛！女施主呀，贫僧可不敢开这等玩笑啊。");
		return;
	}
	
	if( (string)ob->query("class")!="bonze" )
	{
		command ("say 阿弥陀佛！贫僧就收下你做『俗家弟子』了。");
	}
	command("say 阿弥陀佛，善哉！善哉！");
	command("recruit " + ob->query("id"));
}

