// feng.c 静风师太

#include <ansi.h>

inherit NPC;
string ask_yao();
string ask_jian();

void create()
{
	set_name("静风师太", ({ "jingfeng shitai","jingfeng","shitai"}));
	set("long",@LONG
她是一位中年师太，只见她眉目底垂，手中握着一把钢刀。自然而然的有
股威严。
LONG
);
	set("gender", "女性");
	set("age", 42);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);

	set("jing",4000);
	set("max_jing",4000);
	set("neili", 4500);
	set("max_neili",4500);
	set("jiali",225);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp", 2700000);
	set("score", 1000);
	set_skill("yitian-sword",300);
	set_skill("sword",300);
	set_skill("persuading", 300);
	set_skill("force", 300);
	set_skill("throwing",300);
	set_skill("dodge", 300);
	set_skill("finger", 300);
	set_skill("parry", 300);
	set_skill("strike", 300);
	set_skill("blade", 300);
	set_skill("literate",300);
	set_skill("mahayana",300);
	set_skill("jinding-zhang",300);
	set_skill("tiangang-zhi", 300);
	set_skill("yanxing-dao", 300);
	set_skill("zhutian-bu", 300);
	set_skill("linji-zhuang",300);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("blade","yanxing-dao");
	map_skill("parry","yanxing-dao");
	map_skill("sword","yitian-sword");
	set("inquiry", ([
		"伤药" : (: ask_yao :),
		"武器" : (: ask_jian :),
	]));
	set("gao_count",3);
	set("jian_count",2);
	create_family("峨嵋派", 4, "弟子");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
void attempt_apprentice(object ob)
{
	command ("say 阿弥陀佛！贫尼不收弟子。\n");
	command ("say 你若想继续学峨嵋派的功夫，还是去找我俗家师妹吧。\n");
	return;
}
string ask_yao()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "峨嵋派")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";
	if (this_player()->query("qi")>=this_player()->query("max_qi"))
		return "你未曾受伤，讨这药膏做什么？";
	if (ob = present("tianxiang gao", this_player()))
		return "你身上不是带着本门秘药？！";
	if (query("gao_count") < 1)
		return "你来晚了，本门秘药已尽数给了本派弟子。";
	add("gao_count", -1);
	ob = new("/d/emei/obj/tianxiang-gao");
	ob->move(this_player());
	return "我这里有本门秘药，你拿去疗伤吧。";
}
string ask_jian()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "峨嵋派")
		return RANK_D->query_respect(this_player()) +"与本派素无来往，不知此话从何谈起？";
	if (query("jian_count") < 1)
		return "我现在没有什么武器好给，你下次在来吧。";
	if (ob = present("ruanjian", this_player()))
		return "你身上不是带着武器吗？怎么还来要！";
	add("jian_count", -1);
	ob = new("/d/emei/obj/ruanjian");
	ob->move(this_player());
	return "我这里有一把软剑，你拿去用吧。";
}