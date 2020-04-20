//by netkill

inherit NPC;

void create()
{
	set_name("护洞弟子", ({ "hudong dizi", "dizi","zi" }));
	set("title","五毒神教");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 1000);
	set("max_neili", 400);
	set("jiali", 10);
	set("combat_exp", 60000);

	set_skill("force", 80);
	set_skill("wudu-shengong", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("wudu-zhang",80);
	set_skill("wudu-xinfa",80);
	
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "guimei-shenfa");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-zhang");
	
	create_family("五毒神教", 18, "弟子");
	
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );
	
	setup();
	carry_object("/d/wudu/obj/shenyi")->wear();
}


