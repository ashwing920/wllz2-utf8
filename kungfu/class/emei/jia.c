// jia.c 静迦师太

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_join();
void create()
{
	set_name("静迦师太", ({ "jingjia shitai","jingjia","shitai"}));
	set("long",@LONG
她是一位中年出家道姑，道冠高拢，慈眉善目。
LONG
);
	set("gender", "女性");
	set("age", 44);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");
	set("inquiry",([
		"剃度"  : (: ask_for_join :),
		"出家"  : (: ask_for_join :),
		"还俗"  : "峨嵋弟子，不能还俗。你找掌门师太吧。",
	]));

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);

	set("jing",4000);
	set("max_jing",4000);
	set("neili", 6000);
	set("max_neili",6000);
	set("jiali",300);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 6400000);
	set("score",1000);
	set_skill("yitian-sword", 400);
	set_skill("persuading",400);
	set_skill("throwing", 400);
	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("finger", 400);
	set_skill("parry", 400);
	set_skill("strike", 400);
	set_skill("sword", 400);
	set_skill("literate", 400);
	set_skill("mahayana", 400);
	set_skill("jinding-zhang", 400);
	set_skill("tiangang-zhi", 400);
	set_skill("huifeng-jian", 400);
	set_skill("zhutian-bu", 400);
	set_skill("linji-zhuang", 400);
	set_skill("blade",400);
	set_skill("yanxing-dao",400);
	map_skill("blade","yanxing-dao");
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","yitian-sword");
	map_skill("parry","huifeng-jian");

	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	add_action("do_kneel", "kneel");
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")!="bonze" ){
		command ("say 阿弥陀佛！贫尼不收俗家弟子。施主若想学艺可去找我俗家师妹。");
		return;
	}
	if( (string)ob->query("gender") != "女性" ){
		command ("say 阿弥陀佛！贫尼不收男弟子。施主若想学艺可去找我俗家师妹。");
		return;
	}
	if ((int)ob->query("shen")<10000){
		command("say " + RANK_D->query_respect(ob) + "你行侠仗义之事还做的不够。");
		return;
	}
	if ((int)ob->query_skill("mahayana",1) < 200){
		command("say 依我看，你的大乘涅磐功的修为好象还不够啊！");
		return;
	}
	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
	command("recruit " + ob->query("id"));
}

#include "tobebonze.h"
