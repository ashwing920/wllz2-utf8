// ding.c 丁敏君

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("丁敏君", ({ "ding minjun","ding","minjun"}));
	set("long",@LONG
她是峨嵋派的第四代俗家弟子。是天下最恶心，无赖的人。
LONG
);
	set("gender", "女性");
	set("age", 22);
	set("attitude", "peaceful");
	set("shen_type", -2);
	set("class", "fighter");

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 10);

	set("jing",3000);
	set("max_jing",3000);
	set("neili", 4500);
	set("max_neili",4500);
	set("jiali",225);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp",2700000);
	set("score", 1000);
	set_skill("yitian-sword",300);
	set_skill("force", 300);
	set_skill("throwing",300);
	set_skill("dodge", 300);
	set_skill("finger",300);
	set_skill("parry", 300);
	set_skill("strike",300);
	set_skill("sword", 300);
	set_skill("jinding-zhang", 300);
	set_skill("tiangang-zhi", 300);
	set_skill("huifeng-jian", 300);
	set_skill("zhutian-bu", 300);
	set_skill("linji-zhuang",300);
	set_skill("blade",300);
	set_skill("yanxing-dao",300);
	map_skill("blade","yanxing-dao");
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","yitian-sword");
	map_skill("parry","huifeng-jian");
	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
