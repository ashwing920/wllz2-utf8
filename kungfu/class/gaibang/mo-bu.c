// mo-bu.c

inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("莫不收", ({"mo bushou", "mo", "bushou"}));
	set("title", "丐帮三袋弟子");
	set("gender", "男性");
	set("age",21);
	set("long",@LONG
这是位丐帮三袋弟子，看来是个很吃得开的一方霸主。
LONG
);
	set("attitude", "peaceful");
	set("class", "beggar");
	set("str", 21);
	set("int", 20);
	set("con", 20);
	set("dex", 23);

	set("jing",2000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp",800000);

	set_skill("force", 200);
	set_skill("huntian-qigong", 200);
	set_skill("unarmed", 200);
	set_skill("xianglong-zhang", 200);
	set_skill("dodge", 200);
	set_skill("xiaoyaoyou", 200);
	set_skill("parry", 200);
	set_skill("begging", 200);
	set_skill("checking", 200);
	set_skill("training",200);
	set_skill("hand",200);
	set_skill("shexing-diaoshou",200);
	map_skill("hand","shexing-diaoshou");
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry","xianglong-zhang");
	
	create_family("丐帮", 19, "弟子");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)						  
{
	if( ob->query("shen") < 0 ) {
		command("say 丐帮在江湖中一向行侠仗义，从不和邪魔歪道之人打交道！");
		return;
	}
	
	command("say 好吧，希望你能好好学习本门武功，将来为丐帮争一口气！");
	command("recruit " + ob->query("id"));
	ob->set("class","beggar");
}
#include "/kungfu/class/gaibang/gaibang.h"
