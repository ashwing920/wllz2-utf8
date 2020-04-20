// ny netkill

inherit NPC;
inherit F_MASTER;

int ask_me();

void create()
{
	set_name("齐云", ({ "qi yun", "qi" }));
	set("nickname", "锦衣神丐");
	set("title", "五毒神教左使者");
	set("long", "他怎么看也不象个乞丐。\n");
	set("gender", "男性");
	set("age", 51);
	set("attitude", "peaceful");
	set("inquiry", ([
		"解药" : ( : ask_me : ),
	]));
	set("shen_type", -10);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("yao", 10);
	
	set("max_jing", 3000);
	set("neili",4500);
	set("max_neili",4500);
	set("jiali",225);
	set("combat_exp",2700000);
	set("score", 70000);

	set_skill("force", 300);
	set_skill("wudu-shengong", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
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
		(: perform_action, "whip.wudu" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/clone/weapon/changbian")->wield();
	carry_object("/d/wudu/obj/shenyi")->wear();	
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") > -1000 ) {
		command("say 要入我五毒神教，心怀慈悲可是不行的。");
		return;
	}
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	ob->set("title","五毒神教左使座下弟子");
}
int ask_me()
{	
	object pill;
	
	int i=(int)query("yao");
	if (i){
		command("say 这些药你拿去疗毒去吧。\n");
		pill=new("/d/wudu/obj/jieyao");
		pill->move(this_player());
		set("yao",i-1);
	} 
		else
		command("say 我这里没有了，你去别处问问");
		return 1;
}