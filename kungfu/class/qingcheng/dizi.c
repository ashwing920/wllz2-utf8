// yu.c

inherit NPC;

void create()
{
	set_name("青城弟子",({ "qingchen dizi","dizi","di zi" }));
	set("gender", "男性");
	set("age",22+random(10));
	set("long","他是青城派的弟子。\n");
	set("class", "taoist");
	set("combat_exp",3000000);
	set("shen_type", -1);
	
	set("max_neili",8000);
	set("neili",8000);
	set("max_qi",30000);
	set("qi",30000);
	set("max_jing",20000);
	set("jing",20000);
	set("max_jingli",7000);
	set("jingli",7000);

	set_temp("apply/damage",200);
	set_temp("apply/armor",1000);

	set_skill("literate",300);
	set_skill("unarmed",300);
	set_skill("kuihua-xinfa",300);
	set_skill("parry",300);
	set_skill("force",300);
	set_skill("dodge",300);
	set_skill("changquan",300);
	set_skill("pixie-jian",300);
	set_skill("sword",300);

	map_skill("sword","pixie-jian");
	map_skill("parry","pixie-jian");
	map_skill("dodge","pixie-jian");
	map_skill("force","kuihua-xinfa");
	map_skill("unarmed","changquan");

	create_family("青城派",random(10) + 21,"弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
}
