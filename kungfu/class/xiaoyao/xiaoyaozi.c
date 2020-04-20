// xiaoyaozi.c 逍遥子

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("逍遥子", ({ "xiaoyao zi", "xiaoyao","zi" }));
	set("long", @LONG
他就是逍遥派开山祖师、但是因为逍遥派属于一个在江湖中的秘密教派，
所以他在江湖中不是很多人知道，但其实他的功夫却是。他年满七旬，满
脸红光，须眉皆白。
LONG
);
	set("gender", "男性");
	set("age", 75);
	set("class", "scholar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("per", 40);

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

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);

	set_skill("hand",800);
	set_skill("strike",800);
	set_skill("force", 800);
	set_skill("dodge", 800);
	set_skill("unarmed",800);
	set_skill("parry", 800);
	set_skill("lingboweibu",800);
	set_skill("chixin-jian",800);
	set_skill("beiming-shengong", 800);
	set_skill("zhemei-shou", 800);
	set_skill("liuyang-zhang",800);
	set_skill("literate",800);
	set_skill("sword",800);
	set_skill("blade",800);
	set_skill("ruyi-dao",800);

	map_skill("unarmed", "zhemei-shou");
	map_skill("hand","zhemei-shou");
	map_skill("strike","liuyang-zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("sword","chixin-jian");
	map_skill("force", "beiming-shengong");
	map_skill("blade","ruyi-dao");
	prepare_skill("hand","zhemei-shou");
	prepare_skill("strike","liuyang-zhang");
	create_family("逍遥派", 1, "开山祖师");

	setup();

	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("beiming-shengong", 1) < 400) {
		command("say 我逍遥派内功的源泉来自于北冥神功的心法。");
		command("say " + RANK_D->query_respect(ob) + "的北冥神功是否还应该有所提高啊？");
		return;
	}

	if((int)ob->query_skill("lingboweibu",1) < 400) {
		command("say 本派的凌波微步最讲究身法，依我看" + RANK_D->query_respect(ob) + "的身法似乎还不够啊。");
		return;
	}


	if (ob->query_int() < 55) {
		command("say 我逍遥派武功最重视“逍遥”二字。");
		command("say 而何谓“逍遥”，这只能靠你自己去领悟。");
		command("say 但是" + RANK_D->query_respect(ob) + "的悟性似乎还有待提高啊。");
		return;
	}
	command("ahaha");
	command("chat 想不到在这世上竟然还有人可以继承我的逍遥心法！");
	command("recruit " + ob->query("id"));
	switch(random(3)) {
	case 0:
		ob->set("title",HIR"逍遥派护法使者"NOR);
	break;
	case 1:
		ob->set("title",HIC"逍遥派护法使者"NOR);
	break;
	case 2:
		ob->set("title",HIY"逍遥派护法使者"NOR);
	break;
	case 3:
		ob->set("title",HIG"逍遥派护法使者"NOR);
	break;
	}
}
