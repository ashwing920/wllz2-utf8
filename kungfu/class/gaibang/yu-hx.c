// gaibang npc code

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("余洪兴", ({"yu hongxing", "yu", "hongxing"}));
	set("title", "丐帮八袋弟子");
	set("gender", "男性");
	set("age", 30);
	set("long",@LONG
这是位笑眯眯的丐帮八袋弟子，生性多智，外号小吴用。
LONG
);
	set("attitude", "heroism");
	set("class", "beggar");
	set("str", 20);
	set("int", 30);
	set("con", 22);
	set("dex", 20);

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
