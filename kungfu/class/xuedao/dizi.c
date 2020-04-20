// 血刀门弟子

inherit NPC;

void create()
{
	set_name(npc_name("男性"),({ "xuedao dizi","dizi" }) );
	set("age", random(10)+14);
	set("long","他时候血刀门的弟子，刚拜师学艺不久，满脸稚气。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", random(20)+2);
	set("con", random(20)+2);
	set("str", random(20)+2);
	set("dex", random(20)+2);

	set("jingli",1000);
	set("max_jingli",200);
	set("neili", 900);
	set("max_neili", 500);
	set("jiali",300);
	set("combat_exp",200000);
	set("shen_type",-1);
	set_skill("lamaism", 60);
	set_skill("literate", 60);
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("dodge", 60);
	set_skill("xuehai-mogong", 60);
	set_skill("xuedun", 60);
	set_skill("strike", 60);
	set_skill("miexian-zhang", 60);
	set_skill("xue-dao", 60);
	set_skill("unarmed",60);
	set_skill("wuying-shenquan",60);
	map_skill("unarmed","wuying-shenquan");
	map_skill("force", "xuehai-mogong");
	map_skill("dodge", "xuedun");
	map_skill("strike", "miexian-zhang");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");

	create_family("血刀门",12,"弟子");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();
}

