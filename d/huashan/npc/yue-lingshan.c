// yue-lingshan.c

inherit NPC;

void create()
{
	set_name("岳灵珊", ({ "yue lingshan", "yue", "lingshan" }) );
	set("nickname", "小师妹");
	set("long",@LONG
岳灵珊是华山剑派掌门岳不群的独生女儿。
LONG
);
	set("gender", "女性" );
	set("age", 17);
	set("per", 29);
	set("str", 16);
	set("con", 24);
	set("dex", 30);
	set("int", 27);

	set("attitude", "friendly");
	set("combat_exp", 3000000);
	set_skill("unarmed",270);
	set_skill("sword",270);
	set_skill("force",270);
	set_skill("parry",270);
	set_skill("dodge",270);
	set_skill("literate",270);
	set_skill("huashan-sword",270);
	set_skill("yunu-sword",270);
	set_skill("zixia-shengong",270);
	set_skill("huashan-ken",270);
	set_skill("feiyan-huixiang",270);
	set_skill("ziyin-yin",270);

	map_skill("sword", "yunu-sword");
	map_skill("parry", "yunu-sword");
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-ken");
	map_skill("dodge", "feiyan-huixiang");

	create_family("华山剑派", 14, "弟子");
	setup();
	carry_object(__DIR__"obj/green_water_sword")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
int accept_fight(object me)
{
	command("say 小女子怎会是你的对手?");
	return 0;
}
