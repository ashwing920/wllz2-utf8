// ji.c 姬清虚

inherit NPC;

void create()
{
	set_name("姬清虚", ({"ji qingxu", "ji"}));
	set("gender", "男性");
	set("age", 24);
	set("class", "taoist");
	set("long",@LONG
他是一位体格强健的青年道士，似乎身怀武艺。
LONG
);
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 26);
	set("int", 25);
	set("con", 25);
	set("dex", 26);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
	}));

	set("jing",1000);
	set("max_jing",1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);

	set("combat_exp", 100000);
	set("score", 1000);

	set_skill("force", 100);
	set_skill("xiantian-qigong", 100);
	set_skill("sword", 100);
	set_skill("quanzhen-jian",100);
	set_skill("dodge", 100);
	set_skill("jinyan-gong", 100);
	set_skill("parry", 100);
	set_skill("strike",100);
	set_skill("unarmed",100);
	set_skill("haotian-zhang", 100);
	set_skill("literate",100);
	set_skill("taoism",100);
	set_skill("whip",100);
	set_skill("duanyun-bian",100);
	set_skill("cuff",100);
	set_skill("chunyang-quan",100);
	map_skill("cuff","chunyang-quan");
	map_skill("whip","duanyun-bian");
	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("strike", "haotian-zhang");
	prepare_skill("strike", "haotian-zhang");
	prepare_skill("cuff","chunyang-quan");
	create_family("全真教", 4, "弟子");

	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
	]) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

