// goudu.c

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
string ask_me();

void create()
{
	set_name("苟读", ({ "gou du", "gou" }));
	set("long",@LONG
他看上去也是几十岁的人了，却是纯然一个书呆子的模样。
LONG
);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 25);
	set("int", 35);
	set("con", 25);
	set("dex", 25);

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

	set("inquiry", ([
		"论语":(:ask_me:),
	]) );
	set("jing",3000);
	set("max_jing", 3000);
	set("neili",4500);
	set("max_neili",4500);
	set("jiali",225);
	set("combat_exp",2700000);

	set_skill("hand",300);
	set_skill("strike",300);
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("unarmed",300);
	set_skill("parry", 300);
	set_skill("lingboweibu",300);
	set_skill("chixin-jian",300);
	set_skill("beiming-shengong", 300);
	set_skill("zhemei-shou", 300);
	set_skill("liuyang-zhang",300);
	set_skill("literate",300);
	set_skill("sword",300);
	set_skill("blade",300);
	set_skill("ruyi-dao",300);

	map_skill("unarmed", "zhemei-shou");
	map_skill("hand","zhemei-shou");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("sword","chixin-jian");
	map_skill("force", "beiming-shengong");
	map_skill("blade","ruyi-dao");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	set("book_count", 1);

	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","书呆");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();


}


string ask_me()
{
	object me,ob;
	ob=this_player();

	if (query("book_count") < 1)
		return "你来晚了，那本《论语》我已经赠送给别入了。";
	add("book_count", -1);

	if(ob->query("family/master_id")=="xiaoyao zi")
	{
		command("say 师叔想要《论语》，拿去就是。");
		message_vision(HIY"苟读从怀里掏出一本旧书，交了给$N \n\n"NOR,ob);
		me=new("/clone/book/lbook4");
		me->move(ob);
		return "这本书可千万不要借给别人啊，他们一借就不还的了。\n";
	}
	command("say 哈哈，《论语》就没有了，这里有我派高手从少林盗来的书。");
	command("say 既然你那么好学，我就把它送给你吧。");
	if (random(2) == 1) me=new("/clone/book/strike_book");
	else me=new("/clone/book/book-paper");
	me->move(ob);

	return "这本书可千万不要借给别人啊，他们一借就不还的了。\n";
}

void attempt_apprentice(object ob)
{
	if((int)ob->query_skill("beiming-shengong", 1) < 200) {
		command("say 我逍遥派内功的源泉来自于北冥神功的心法。");
		command("say " + RANK_D->query_respect(ob) + "的北冥神功是否还应该有所提高啊？");
		return;
	}
	if((int)ob->query_skill("lingboweibu",1) < 200) {
		command("say 本派的凌波微步是以身法为基础，依我看" + RANK_D->query_respect(ob) + "的身法似乎还不够啊。");
		return;
	}

	if (ob->query_int() < 35) {
		command("say 我逍遥派武功最重视“逍遥”二字，何谓“逍遥”，这只能靠你自己去领悟。");
		command("say 但是" + RANK_D->query_respect(ob) + "的悟性似乎还有待提高啊。");
		return;
	}
	command("nod");
	command("say 好好，我就收下你吧！");
	command("recruit " + ob->query("id"));
	ob->set("class","scholar");
}
