// huyuan.c
inherit NPC;
void create()
{
	set_name("护院", ({"hu yuan","yuan",}));
	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 30);
	set("shen_type", 1);
	set("str", 17);
	set("int", 24);
	set("con", 20);
	set("dex", 22);
	set("max_qi", 3350);
	set("max_jing", 2200);
	set("neili", 1350);
	set("max_neili", 1350);
	set("jiali", 100);
	set("combat_exp", 300000);
	set("score", 100);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("sword", 120);
	set_skill("parry", 100);

	create_family("梅庄", 3, "弟子");

	setup();

	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

