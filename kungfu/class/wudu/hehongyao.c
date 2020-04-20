// ny netkill

inherit NPC;
inherit F_MASTER;

int ask_me();

void create()
{
	set_name("何红药", ({ "he hongyao", "he" }));
	set("title", "丑妇人");
	set("long", "一个面目丑陋的老妇人。\n");
	set("gender", "女性");
	set("age", 51);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("inquiry", ([
		"解药" : ( : ask_me : ),
	]));
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);

	set("yao", 10);

	set("max_jing",3000);
	set("neili",4500);
	set("max_neili",4500);
	set("jiali",225);
	set("combat_exp",2700000);
	set("score", 30000);

	set_skill("force", 300);
	set_skill("wudu-shengong", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("wudu-bian",300);
	set_skill("wudu-zhang",300);
	set_skill("wudu-xinfa",300);
	set_skill("whip",300);          
	set_skill("guimei-shenfa", 300);
	set_skill("strike",300);
	set_skill("pour",300);
	set_skill("literate",300);
	set_skill("unarmed",300);
	set_skill("poison",300);
	set_skill("hook",300);
//	set_skill("wudu-gou",300);
	
//	map_skill("hook","wudu-gou");
	map_skill("unarmed","wudu-zhang");
	map_skill("force", "wudu-shengong");
	map_skill("dodge", "guimei-shenfa");
	map_skill("strike", "wudu-zhang");
	map_skill("parry", "wudu-bian");
	map_skill("whip", "wudu-bian");

	create_family("五毒神教", 17, "左使者");
	
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );
	setup();
	carry_object("/clone/weapon/changbian")->wield();
	carry_object("/d/wudu/obj/shenyi")->wear();     
	add_money("gold",1);
}

void init()
{       
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");
	if( !ob || environment(ob) != environment() ) return;
	if (!myfam || myfam["family_name"] != "五毒神教") 
	say( "何红药说到：这位" + RANK_D->query_respect(ob)
				+ "，驾临这荒山野地，不知有何贵干，我劝你还是快快回去吧。\n");
	
}
	
void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") > -100) {
		command("say 要入我五毒神教，心怀慈悲可是不行的。");
		return;
	}
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	ob->set("title","五毒神教右使座下弟子");
	
}

int ask_me()
{       
	object pill;
	int i=(int)query("yao");
	if(i){
		command("say 这些药你拿去疗毒去吧。\n");
		pill=new("/d/wudu/obj/jieyao");
		pill->move(this_player());
		set("yao",i-1);
	} 
	else
		command("say 我这里没有了，你去别处问问");
		return 1;
}
