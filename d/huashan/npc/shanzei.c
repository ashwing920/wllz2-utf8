// shanzei.c 山贼

inherit NPC;

void create()
{
	set_name("山贼",({ "shan zei" }));
	set("long",@LONG
一个穷凶极恶的山贼，武功平平，却专门欺负弱小。
LONG);

	set("gender", "男性");
	set("age", 20 + random(30));
	set("per",20 + random(30));
	set("kar",20 + random(30));
	set("int",20 + random(30));
	set("dex",20 + random(30));

	set_temp("apply/damage",100);
	set_temp("apply/armor",300);

	set("jing",6000);
	set("max_jing",6000);
	set("neili",6000);
	set("max_neili",6000);
	set("max_qi",10000);
	set("qi",10000);
	set("jiali",200);
	set("combat_exp",2700000);
	set("shen_type", 1);

	set_skill("force",300);
	set_skill("unarmed",300);
	set_skill("blade",300);
	set_skill("parry",300);
	set_skill("dodge",300);
	set_skill("hunyuan-yiqi",300);
	set_skill("wuhu-duanmendao",300);
	set_skill("yingfeng-steps",300);
	set_skill("xiaohun-zhang",300);
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
		message_vision("$N狞笑道：嘿嘿！留下命来！！\n",this_object());
		this_object()->kill_ob(ob);
		ob->kill_ob(this_object());
	}
}