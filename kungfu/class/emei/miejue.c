// miejue.c 灭绝师太

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
string ask_me();
mixed out_master(mixed arg);

void create()
{
	set_name("灭绝师太", ({ "miejue shitai","miejue","shitai"}));
	set("long",@LONG
她是峨嵋派的第三代弟子，现任峨嵋派掌门人。
LONG
);
	set("gender", "女性");
	set("age", 62);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
	}) );
	set("inquiry",([
		"剃度"  : "贫尼只知除妖杀魔，不剃度弟子。",
		"出家"  : "贫尼只知除妖杀魔，不剃度弟子。",
		"还俗"  :  (: ask_for_quit :),
		"大乘涅磐功": (: ask_me :),
	]));
	set("book_give",1);
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("per", 26);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);

	set("combat_exp",51200000);

	set_skill("yitian-sword",800);
	set_skill("persuading", 800);
	set_skill("throwing", 800);
	set_skill("force", 800);
	set_skill("dodge", 800);
	set_skill("finger", 800);
	set_skill("parry", 800);
	set_skill("strike", 800);
	set_skill("sword", 800);
	set_skill("blade", 800);
	set_skill("literate", 800);
	set_skill("mahayana", 800);
	set_skill("jinding-zhang", 800);
	set_skill("tiangang-zhi", 800);
	set_skill("huifeng-jian", 800);
	set_skill("yanxing-dao", 800);
	set_skill("zhutian-bu", 800);
	set_skill("linji-zhuang", 800);
	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","yitian-sword");
	map_skill("blade","yanxing-dao");
	map_skill("parry","huifeng-jian");
	create_family("峨嵋派", 3, "掌门人");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	mapping ob_fam;

	string name, new_name;
	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派"){
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}
	if ((string)ob->query("class")!="bonze" ){
		command("say 阿弥陀佛！贫尼不收俗家弟子。");
		return;
	}
	if((int)ob->query_skill("mahayana",1)<400||(int)ob->query_skill("linji-zhuang",1)<400){
		command("say 依我看，你的大乘涅磐功和临济十二庄的修为好象还不够啊！");
		return;
	}
	if ((int)ob->query("shen") <100000){
		command("say " + RANK_D->query_respect(ob) + "你行侠仗义之事还做的不够。");
		return;
	}
	if ((string)ob->query("class")=="bonze" ){
	name = ob->query("name");
	new_name = "静" + name[2..3]+"师太";
	ob->set("name", new_name);
	command("say 从今以后你的法名叫做" + new_name + "，恭喜你成为峨嵋第四代弟子！");
	command("chat 恭喜"+ ob->name() +"成为峨嵋派第四代弟子，取法号："+ new_name +"。");
	}

	command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
	command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
	command("recruit " + ob->query("id"));
}

string ask_for_quit()
{
	object me;
	mapping myfam;
	me = this_player();

	myfam = (mapping)me->query("family");
	if (!myfam || (myfam["family_name"] != "峨嵋派"))
		return"你和峨嵋没有渊源，贫尼不敢给你还俗。\n";
	if( (string)me->query("class")!="bonze" )
		return "阿弥陀佛！出家人不打诳语。你已经是俗家人了。\n";
	me->set_temp("pending/quit_bonze", 1);
	command ("say 阿弥陀佛！善哉！善哉！你一心要还俗，我也不挽留。");
	command ("say 我将废去你部分武功。请跪下(kneel)听宣。");
		return "如果不愿还俗的，就安心在此修炼吧。\n";
}
string ask_me()
{
	object me,book;
	mapping myfam;
	me = this_player();

	if((!mapp(myfam = me->query("family"))) || myfam["family_name"] != "峨嵋派")
			return "这位"+ RANK_D->query_respect(me)+"与我峨嵋派素无来往，何来大乘涅磐功一说？";
	if( query("book_give") < 1)
		return "你来晚了，大乘涅磐功已经被其他人拿走了。";

	CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s拿到大乘涅磐功啦！",me->name()));
	add("book_give",-1);
	book = new("/clone/book/mahayana");
	book->move(me);
		return "好吧！这本大乘涅磐功你就拿去好好学习。";
}
