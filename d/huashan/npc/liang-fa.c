// liang-fa.c

inherit NPC;


void create()
{
	set_name("梁发", ({ "liang fa", "liang", "fa" }) );
	set("nickname", "闭嘴佛");
	set("gender", "男性");
	set("age", 30);
	set("long",
		"梁发是岳不群的第三弟子。\n");
	set("attitude", "peaceful");

	set("str", 26);
	set("con", 30);
	set("int", 24);
	set("dex", 30);

	set("neili", 4000);
	set("max_neili", 4000);
	set("jing",1800);
	set("jiali",200);
	set("combat_exp",800000);
	set("shen_type", 1);
	set("score", 2000);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("unarmed", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("literate", 200);
	set_skill("huashan-sword", 200);
	set_skill("huashan-neigong", 200);
	set_skill("huashan-ken", 200);
	set_skill("huashan-zhangfa", 200);
	set_skill("huashan-shenfa", 200);

	map_skill("sword", "huashan-sword");
	map_skill("parry", "huashan-sword");
	map_skill("force", "huashan-neigong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");

	create_family("华山剑派", 14, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
