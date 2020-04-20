// fengas.c

inherit NPC;
inherit F_MASTER;

#include <ansi.h>
string ask_me();

void create()
{
	set_name("冯阿三", ({ "feng asan", "feng" }));
	set("long",@LONG
据说他就是鲁班的后人，当代的第一巧匠，设计机关的能手。
LONG
);
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("class", "alchemist");
	set("shen_type", 1);
	set("str", 38);
	set("int", 28);
	set("con", 30);
	set("dex", 28);

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
		"机关" : (:ask_me:),
	]) );

	set("jing",3000);
	set("max_jing", 3000);
	set("neili", 4500);
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
	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","巧匠");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();

}

string ask_me()
{
	object ob;
	ob=this_player();

	if (random(100)<70)
		return "我在设计机关方面是有点特长，让大家见笑了。";
	command("laugh");
	return "别吵着我，我在看书呢。哈哈，《逍遥自在》……这书真好笑\n";
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

	command("chat 好好！我就收下你吧！！");
	command("recruit " + ob->query("id"));
	ob->set("class","scholar");
}
