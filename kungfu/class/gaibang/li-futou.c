// li-futou.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("李斧头", ({"li futou", "li", "futou"}));
	set("title", "丐帮六袋弟子");
	set("gender", "男性");
	set("class", "beggar");
	set("age", 20);
	set("long",@LONG
这是位丐帮六袋弟子，看来是个深藏不露的高手。
LONG
);
	set("attitude", "heroism");
	set("str", 27);
	set("int", 25);
	set("con", 24);
	set("dex", 27);

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
