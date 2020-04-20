// xi.c 张松溪

inherit NPC;

void create()
{
	set_name("张松溪", ({ "zhang songxi", "zhang" }));
	set("nickname", "武当四侠");
	set("long", @LONG
他就是张三丰的四弟子张松溪。他今年四十岁，精明能干，以足智多谋著
称。
LONG
);
	set("gender", "男性");
	set("age", 40);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("dex", 28);
	
	set("jing",4000);
	set("max_jing",4000);
	set("neili", 6000);
	set("max_neili",6000);
	set("jiali",300);
	set("combat_exp", 6400000);
	set("score", 50000);

	set_skill("force", 400);
	set_skill("taiji-shengong", 400);
	set_skill("dodge", 400);
	set_skill("tiyunzong", 400);
	set_skill("unarmed", 400);
	set_skill("taiji-quan", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("taiji-jian", 400);
	set_skill("taoism", 400);
	set_skill("literate", 400);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 2, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
