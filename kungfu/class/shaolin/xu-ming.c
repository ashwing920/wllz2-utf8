// Npc: /kungfu/class/shaolin/xu-ming.c

inherit NPC;

void create()
{

	set_name("虚明", ({"xu ming","xu","ming",}));
	set("long",@LONG
他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相当矫捷，
看来似乎学过一点武功。
LONG
);
	set("nickname", "知客僧");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 35);
	set("dex", 20);

	set("max_jing",1000);
	set("neili",1500);
	set("max_neili",1500);
	set("jiali",75);
	set("combat_exp",100000);
	
	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("strike", 100);
	set_skill("banruo-zhang", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("damo-jian", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 41, "弟子");

	setup();

	carry_object("/d/shaolin/obj/changjian")->wield();
	carry_object("/d/shaolin/obj/xu-cloth")->wear();

}



