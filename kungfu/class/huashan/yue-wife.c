//yue-wife.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("宁中则", ({ "ning zhongze", "ning","yue" }) );
	set("nickname", "淑女剑");
	set("gender", "女性");
	set("class", "swordsman");
	set("age", 50);
	set("long",@LONG
她江湖上人称淑女剑的宁中则，是岳不群的师妹，也是他的妻子。
LONG
);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 26);
	set("per", 26);
	set("int", 24);
	set("con", 30);
	set("dex", 30);


	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);

	set("apprentice_available", 3);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );

	set_skill("unarmed", 800);
	set_skill("sword", 800);
	set_skill("force", 800);
	set_skill("parry", 800);
	set_skill("dodge", 800);
	set_skill("literate", 800);
	set_skill("huashan-sword", 800);
	set_skill("yunu-sword", 800);
	set_skill("zixia-shengong", 800);
	set_skill("huashan-ken", 800);
	set_skill("feiyan-huixiang", 800);
	set_skill("ziyin-yin", 800);

	map_skill("sword", "yunu-sword");
	map_skill("parry", "yunu-sword");
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-ken");
	map_skill("dodge", "feiyan-huixiang");

	create_family("华山剑派", 13, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say 慢著，一个一个来。");
		else
			call_out("do_recruit",1,ob);
	} else {
		command("say 今天好累哟。");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "女性" ){
		 command("say 这位"+RANK_D->query_respect(ob)+"你还是找我夫君去吧。");
	}else {
	command("say 微笑道：好，好，只要你用心学，他日必有成就。");
	command("recruit " + ob->query("id") );
	ob->set("class", "swordsman");
   }
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	ob->set("class", "swordsman");
	add("apprentice_availavble", -1);
}
void reset()
{
	set("apprentice_available", 3);
}
