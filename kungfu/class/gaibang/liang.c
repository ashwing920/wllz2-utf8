// sample master.c code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("梁长老", ({"liang zhanglao", "liang", "zhanglao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "传功长老");
	set("gender", "男性");
	set("age", 55);
	set("long", @LONG
梁长老是丐帮出道最久，武功最高的长老，在武林中享名已久。丐帮武功
向来较强，近来梁长老一力整顿，更是蒸蒸日上。
LONG
);

	set("attitude", "heroism");
	set("class","beggar");
	set("no_get",1);
	
	set("str", 28);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	
	set("combat_exp",6400000);
	
	set_skill("force", 400); 
	set_skill("huntian-qigong", 400); 
	set_skill("unarmed", 400); 
	set_skill("xianglong-zhang", 400); 
	set_skill("dodge", 400); 
	set_skill("xiaoyaoyou", 400); 
	set_skill("parry", 400); 
	set_skill("staff", 400); 
	set_skill("dagou-bang", 400); 
	set_skill("begging", 400); 
	set_skill("checking", 400);
	set_skill("training", 400);
	set_skill("staff",400);
	set_skill("fengmo-zhang",400);
	map_skill("staff","fengmo-zhang");
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("parry", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 18, "九袋长老");
	setup();
	carry_object("clone/cloth/cloth")->wear();
	carry_object("clone/weapon/staff")->wield();
}

void init()
{
	object ob;
	mapping myfam;
	
	::init();
	if (interactive(ob = this_player()) && !is_fighting()) 
	{
		myfam = (mapping)ob->query("family");
		if (!myfam || myfam["family_name"] != "丐帮")
		{
			remove_call_out("saying");
			call_out("saying",1,ob);
		}
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	if(base_name(environment()) == query("startroom")) {
	message_vision("粱长老看到$N闯进来，大喝一声：你不是丐帮弟子，给我滚出去！\n\n", ob);
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	}
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	ob->move("/d/gaibang/inhole");
	message("vision","只听“乒”地一声，" + ob->query("name") +"从小门里飞了出来。\n", environment(ob), ob);
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("str") < 30 ) {
		command("say 我们丐帮的武艺一向以刚猛为主，" +RANK_D->query_respect(ob) + "臂力太弱，似乎不宜学丐帮的功夫？");
		return;
	}
	if((int)ob->query_skill("xianglong-zhang",1) < 200){
		command("say 降龙十八掌乃是丐帮的绝学，依我看这位" + RANK_D->query_respect(ob)+"似乎还不够啊！");
		return;
	}
	if((int)ob->query_skill("begging",1) < 200) {
		command("say 叫化绝活乃是丐帮的得意功夫，依我看这位" + RANK_D->query_respect(ob)+"似乎还不够啊！");
		return;
	}

	command("say 好吧，希望" + RANK_D->query_respect(ob) +"能勤练武艺，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));

}

#include "/kungfu/class/gaibang/gaibang.h"
