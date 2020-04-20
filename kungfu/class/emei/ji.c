// ji.c 纪晓芙

inherit NPC;
inherit F_MASTER;
int ask_jian();

void create()
{
	set_name("纪晓芙", ({ "ji xiaofu","ji","xiaofu"}));
	set("long",@LONG
她是峨嵋派的第四代俗家弟子。偏心偏听的灭绝抛弃她，她独自在这里苦
度光阴。
LONG
);
	set("gender", "女性");
	set("age", 22);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);

	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("inquiry",([
		"倚天剑"  : (:ask_jian:),
		"屠龙刀"  : "这里没有屠龙刀。倚天剑倒是有一柄。",
		"杨不悔"  : "我的女儿啊。她在哪里？你知道么？",
		"杨逍"	: "我这辈子是不指望见到他了。",
		"灭绝"	: "师父就是太偏心。",
	]));

	set("jing",3000);
	set("max_jing",3000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("jingli", 1500);
	set("max_jingli", 1500);

	set("combat_exp",800000);
	set("score", 1000);

	set_skill("yitian-sword",200);
	set_skill("throwing", 200);
	set_skill("persuading", 200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("finger", 200);
	set_skill("parry", 200);
	set_skill("strike", 200);
	set_skill("sword", 200);
	set_skill("mahayana", 200);
	set_skill("jinding-zhang", 200);
	set_skill("tiangang-zhi", 200);
	set_skill("huifeng-jian", 200);
	set_skill("zhutian-bu", 200);
	set_skill("linji-zhuang", 200);
	set_skill("blade",200);
	set_skill("yanxing-dao",200);
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

void attempt_apprentice(object ob)
{
	if ((int)ob->query("shen") < 1000) {
		command("say 我峨嵋乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
		return;
	}
	
	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));
	ob->set("title","峨嵋派第五代俗家弟子");
}
int ask_jian()
{
	object ob;
	ob = this_player();
	ob->set("marks/ji",0);
	ob->set("marks/skysword",1);
	say( "纪晓芙微微叹了口气：“倚天剑就在舍身崖下。\n");
	tell_object(ob,"纪晓芙所完这句话，飘然跃下舍身崖去。衣袂飘动，白云荡处，伤感顿生。\n");
	destruct(this_object());
	return 1;
}
