
// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("龙亦凡", ({"island master", "long", "master"}));
	set("nickname", "不败神龙");
	set("gender", "男性");
	set("age", 80);
	set("long", 
		"这难道就是传说中的侠客岛岛主龙亦凡吗？\n他看上去跟一般的中年人无异，可是他已有百岁高龄。\n");
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("force", 10000);
	set("max_force", 10000);
	set("force_factor", 50);
	
	set("combat_exp", 2000000);
	set("score", 500000);
	
	set_skill("force", 200);
	set_skill("huntian-qigong", 150);
	set_skill("unarmed", 150);
	set_skill("banruo-zhang", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 150);
//	 set_skill("move", 100);
	set_skill("literate", 100);
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "banruo-zhang");
	map_skill("dodge", "shaolin-shenfa");
//	map_skill("move", "xiake-steps");
	
	setup();
	create_family("侠客岛", 3, "弟子");
}

