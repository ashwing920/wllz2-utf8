// mengmianr.c

inherit NPC;

void create()
{
	set_name("蒙面人", ({ "mengmian ren", "ren" }));
	set("long",@LONG
一个蒙着面部，身穿黑色夜行衣服的神秘人。
LONG
);
	set("gender", "男性");
	set("age", 25);
	set("attitude","killer");
	set("class", "fighter");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("jing",1000);
	set("max_jing",1000);
	set("neili",1500);
	set("max_neili",1500);
	set("jiali",75);
	set("combat_exp",100000);

	set("chat_chance_combat",60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "shield" :),
		(: exert_function, "neilisuck" :),
		(: exert_function, "jinglisuck" :),
		(: perform_action, "blade.riyue" :),
		(: perform_action, "blade.wenrou" :),
		(: perform_action, "blade.suifeng" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "dodge.lingbo" :),
	}) );

	set_skill("hand",100);
	set_skill("strike",100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed",100);
	set_skill("parry", 100);
	set_skill("lingboweibu",100);
	set_skill("chixin-jian",100);
	set_skill("beiming-shengong", 100);
	set_skill("zhemei-shou", 100);
	set_skill("liuyang-zhang",100);
	set_skill("literate",100);
	set_skill("sword",100);
	set_skill("blade",100);
	set_skill("ruyi-dao",100);

	map_skill("unarmed", "zhemei-shou");
	map_skill("hand","zhemei-shou");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("sword","chixin-jian");
	map_skill("force", "beiming-shengong");
	map_skill("blade","ruyi-dao");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	create_family("逍遥派", 5, "弟子");
	setup();

	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
