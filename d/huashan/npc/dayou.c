// dayou.c 

inherit NPC;

void create()
{
	set_name("陆大有", ({ "lu dayou", "lu", "dayou" }));
	set("nickname", "六猴儿");
	set("long",@LONG
陆大有身材很瘦，又长的尖嘴猴腮的，但别看他其貌不扬，他在同门中排
行第六，是华山剑派年轻一代中的好手。肩上坐着一只小猴，一对眼睛四
处乱转。
LONG
);
	set("gender", "男性");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 23);
	set("int", 23);
	set("con", 24);
	set("dex", 28);
	
	set("neili", 4000);
	set("max_neili",4000);
	set("jiali", 200);
	set("combat_exp", 800000);
	set("score", 5000);
	set_skill("unarmed", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("literate", 200);
	set_skill("huashan-sword", 200);
	set_skill("huashan-neigong", 200);
	set_skill("huashan-ken", 200);
	set_skill("huashan-zhangfa", 200);
	set_skill("huashan-shenfa", 200);

	map_skill("sword", "huashan-sword");
	map_skill("parry", "huashan-sword");
	map_skill("force", "huashan-neigong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");
	create_family("华山剑派", 14, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
