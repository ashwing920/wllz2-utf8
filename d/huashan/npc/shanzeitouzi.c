// shanzei.c 山贼

inherit NPC;

void create()
{
	set_name("山贼头子",({ "shanzei touzi","touzi" }));
	set("long",@LONG
他就是这群山贼当中的头目，黑溜溜的眼睛里泛出一丝杀气。
LONG);

	set("gender", "男性");
	set("age", 20 + random(30));
	set("per",20 + random(30));
	set("kar",20 + random(30));
	set("int",20 + random(30));
	set("dex",20 + random(30));

	set_temp("apply/damage",500);
	set_temp("apply/armor",500);
	set_temp("apply/dodge",500);
	set_temp("apply/parry",500);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",10000);
	set("max_neili",10000);
	set("max_qi",30000);
	set("qi",10000);
	set("jiali",200);
	set("combat_exp",6400000);

	set_skill("force",400);
	set_skill("unarmed",400);
	set_skill("blade",400);
	set_skill("parry",400);
	set_skill("dodge",400);
	set_skill("hunyuan-yiqi",400);
	set_skill("wuhu-duanmendao",400);
	set_skill("yingfeng-steps",400);
	set_skill("xiaohun-zhang",400);
	set_skill("perception",200);

	map_skill("dodge", "yingfeng-steps");
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");
	map_skill("unarmed","xiaohun-zhang");
	set("shen_type",-1);
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 5);
}
void init()
{
	object ob;
	if (interactive(ob = this_player())){
		message_vision("$N喊道：小的们，给我上！！！\n",this_object());
		this_object()->kill_ob(ob);
		ob->kill_ob(this_object());
	}
}
void afterdie_func(object killer)
{
	if(killer->query_temp("ask_shiqingshan"))
	set("killer",killer->query("name"));
}
