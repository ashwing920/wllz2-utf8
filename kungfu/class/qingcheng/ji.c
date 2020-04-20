// ji.c

inherit NPC;

void create()
{
	set_name("吉人通", ({ "ji rentong", "ji", "rentong" }));
	set("gender", "男性");
	set("age", 25);
	set("long", "他就是和申人俊抗孟不离的吉人通。\n");

	set("combat_exp", 70000);
	set("shen_type", -1);

	set_skill("sword", 70);
	set_skill("pixie-jian", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	map_skill("parry", "pixie-jian");
	map_skill("sword", "pixie-jian");
	create_family("青城派", 6, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}

