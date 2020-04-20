// wenhui.c 文晖小师太

inherit NPC;

void create()
{
	set_name("文晖小师太", ({ "wenhui","wenhui xiaoshitai","xiaoshitai"}));
	set("long",@LONG
她是峨嵋派的第五代弟子。
LONG
);
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	set("per", 30);

	set("max_jing",300);
	set("neili",1000);
	set("max_neili",1000);
	set("jiali",50);

	set("combat_exp",100000);
	set("score", 1000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 55);
	set_temp("apply/defense", 55);
	set_temp("apply/damage", 50);

	create_family("峨嵋派", 5, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth.c")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		   remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	 if( !ob || environment(ob) != environment() ) return;
	 command( "say 这位施主请先入座，我这就给您上茶点。\n");
}


