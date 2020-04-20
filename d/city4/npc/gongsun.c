//weiqi...97/12/11

inherit NPC;

void do_something();

void create()
{
	set_name("公孙大娘",({"gongsun daniang","gongsun","daniang"}));
	set("age",32);
	set("gender","女性");
	set("per",20);
	set("long",@LONG
长安城内稍有名望的，不知道公孙大娘的人恐怕没几个。特别是那些文人
骚客，跟公孙大娘不熟简直就是没面子。
LONG
);
	set("title","长安乐坊老板娘");
	set("attitude","friendly");

	set("combat_exp",40000);
	set("max_force",400);
	set("force",400);
	set("force_factor",5);
	set_skill("unarmed",60);
	set_skill("dodge",90);
	set_skill("yueying-wubu",120);
	set_skill("parry",60);
	set_skill("literate",90);
	set_skill("sword",90);
	set("inquiry",([
		"name":"嘻嘻...连老娘我公孙大娘你都不知道...\n",
		"here":"嘿嘿...天下美景不胜数，长安此处最繁华。\n",
		"妓院":"大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
		"妓女":"大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
		"嫖妓":"大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
		"青楼":"大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
	]));

	setup();
	carry_object(__DIR__"obj/skirt")->wear();
	carry_object(__DIR__"obj/shoes")->wear();
	carry_object(__DIR__"obj/snow_sword")->wield();
	add_money("silver",200);
}
void do_something()
{
	command("bet "+ (random(5)+1) +" silver");
	call_out("do_something",60,this_object());
}
void init()
{
	object ob;

	if(interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("do_something");
		call_out("do_something",60,this_object());
	}
}
