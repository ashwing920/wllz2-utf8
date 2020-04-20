// suxingh.c  苏星河

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_he();
void create()
{
	set_name("苏星河",({"su xinghe","su"}));
	set("gender", "男性" );
	set("nickname", "聪辩老人");
	set("long",@LONG
此人就是号称聪辩老人的苏星河，据说他能言善辩，是一个武林中的智者
，而他的武功也是无人能知。
LONG
);
	set("shen_type",1);
	set("class", "scholar");
	set("age",60);
	set("str", 30);
	set("con", 30);
	set("int", 45);
	set("dex", 35);
	set("per", 30);

	set("chat_chance_combat",60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "shield" :),
		(: exert_function, "neilisuck" :),
		(: exert_function, "jinglisuck" :),
		(: perform_action, "blade.riyue" :),
		(: perform_action, "blade.wenrou" :),
		(: perform_action, "blade.suifeng" :),
		(: perform_action, "hand.duo" :),
		(: perform_action, "dodge.lingbo" :),
	}) );

	set("combat_exp",6400000);
	set("attitude", "peaceful");
	set("book_count", 1);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);

	set_skill("hand",400);
	set_skill("strike",400);
	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("unarmed",400);
	set_skill("parry", 400);
	set_skill("lingboweibu",400);
	set_skill("chixin-jian",400);
	set_skill("beiming-shengong", 400);
	set_skill("zhemei-shou", 400);
	set_skill("liuyang-zhang",400);
	set_skill("literate",400);
	set_skill("sword",400);
	set_skill("blade",400);
	set_skill("ruyi-dao",400);

	map_skill("unarmed", "zhemei-shou");
	map_skill("hand","zhemei-shou");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("sword","chixin-jian");
	map_skill("force", "beiming-shengong");
	map_skill("blade","ruyi-dao");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	create_family("逍遥派", 2, "弟子");

	set("title","逍遥派第二代大弟子");

	set_temp("鱼数",0);

	set("inquiry", ([
		"秘密地道" :(:ask_he:),
	]) );

	setup();

	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();

}

void attempt_apprentice(object ob)
{
	if((int)ob->query_skill("beiming-shengong", 1) < 300) {
		command("say 我逍遥派内功的源泉来自于北冥神功的心法。");
		command("say " + RANK_D->query_respect(ob) + "的北冥神功是否还应该有所提高啊？");
		return;
	}
	if((int)ob->query_skill("lingboweibu", 1) < 300) {
		command("say 本派的凌波微步是以身法为基础，依我看" + RANK_D->query_respect(ob) + "的身法似乎还不够啊。");
		return;
	}

	if (ob->query_int() < 55) {
		command("say 我逍遥派武功最重视“逍遥”二字，何谓“逍遥”，这只能靠你自己去领悟。");
		command("say 但是" + RANK_D->query_respect(ob) + "的悟性似乎还有待提高啊。");
		return;
	}

	command("nod");
	command("say 好好，我就收下你吧！");
	command("recruit " + ob->query("id"));
	ob->set("class","scholar");
}
string ask_he()
{
	object ob;
	mapping fam;
	ob=this_player();
	if (!(fam = ob->query("family"))
		|| fam["family_name"] != "逍遥派")
	{
		return"想要知道密道就得加入逍遥派。";
	}
	command("sigh");
	return"本派的密道在华山之上，很是艰险。你有兴趣可以去看看。";
}

