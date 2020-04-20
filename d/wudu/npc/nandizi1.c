//by netkill

inherit NPC;

void create()
{
	set_name("男教众", ({ "nanjiaozhong", "nan","jiaozhong" }));
	set("title","五毒神教蜘蛛堂");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 24);
	set("int", 24);
	set("con", 24);
	set("dex", 24);
	
	set("max_qi", 300);
	set("max_jing", 100);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 10);
	set("combat_exp", 60000);

	set_skill("force", 50);
	set_skill("wudu-shengong", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("wudu-zhang",50);
	set_skill("wudu-xinfa",50);
	
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "guimei-shenfa");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-zhang");
	
	create_family("五毒神教", 18, "弟子");
	
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "whip.wudu" :),
		(: exert_function, "recover" :),
	}) );
	
	setup();
	carry_object("/d/wudu/obj/shenyi")->wear();
}


