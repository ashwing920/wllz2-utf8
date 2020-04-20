// shi-daizi.c

inherit NPC;

void create()
{
	set_name("施戴子", ({ "shi daizi", "shi", "daizi" }) );
	set("gender", "男性");
	set("age", 22);
	set("long",@LONG
施戴子是岳不群的第四位弟子。
LONG
);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("int", 24);
	set("dex", 30);

	set("combat_exp", 3500000);
	set("shen_type", 1);

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
		(: perform_action, "wushuang" :),
		(: perform_action, "jianzhang" :),
		(: perform_action, "feilong" :),
	}) );
	set_skill("unarmed",300);
	set_skill("sword",300);
	set_skill("force",300);
	set_skill("parry",300);
	set_skill("dodge",300);
	set_skill("literate",300);
	set_skill("huashan-sword",300);
	set_skill("zixia-shengong",300);
	set_skill("huashan-ken",300);
	set_skill("feiyan-huixiang",300);
	set_skill("zhengqijue",300);
	map_skill("sword", "huashan-sword");
	map_skill("parry", "huashan-sword");
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-ken");
	map_skill("dodge", "feiyan-huixiang");
	create_family("华山剑派", 14, "弟子");
	setup();
	carry_object("/clone/weapon/sword")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
