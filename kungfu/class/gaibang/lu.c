
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "掌棒龙头");
	set("gender", "男性");
	set("age", 45);
	set("long",@LONG
鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。因为他在丐
帮中有仁有义，行事光明磊落，深得洪七公的器重。
LONG
);
	set("attitude", "heroism");
	set("class", "beggar");
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);


	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	
	set("combat_exp", 6400000);
	set("score",20000);
	
	set_skill("force", 400);
	set_skill("huntian-qigong", 400);
	set_skill("unarmed", 400);
	set_skill("xianglong-zhang",400);
	set_skill("dodge", 400);
	set_skill("xiaoyaoyou", 400);
	set_skill("parry", 400);
	set_skill("staff", 400);
	set_skill("begging", 400);
	set_skill("training",400);
	set_skill("hand",400);
	set_skill("shexing-diaoshou",400);
	set_skill("blade",400);
	set_skill("liuhe-daofa",400);
	map_skill("hand","shexing-diaoshou");
	map_skill("blade","liuhe-daofa");
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry","xianglong-zhang");
	
	create_family("丐帮", 18, "九袋长老");
	setup();
	carry_object("/clone/weapon/staff")->wield();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object(__DIR__"obj/jiaohuaji");
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
