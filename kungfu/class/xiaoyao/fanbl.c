// kanggl.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_me();

void create()
{
	set_name("范百龄", ({ "fan bailing", "fan" }));
	set("long", @LONG
他便是函谷八友之一，据说他擅于棋艺，喜好研究棋局。
LONG
);
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("class", "scholar");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 38);

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
		"逍遥子":(:ask_me:),
	]) );

	set("jing",2000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",150);
	set("combat_exp",800000);

	set_skill("hand",200);
	set_skill("strike",200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed",200);
	set_skill("parry", 200);
	set_skill("lingboweibu",200);
	set_skill("chixin-jian",200);
	set_skill("beiming-shengong", 200);
	set_skill("zhemei-shou", 200);
	set_skill("liuyang-zhang",200);
	set_skill("literate",200);
	set_skill("sword",200);
	set_skill("blade",200);
	set_skill("ruyi-dao",200);

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
	set("nickname","棋魔");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();

}


string ask_me()
{
	object me,ob;
	ob=this_player();
	if((string)ob->query("family/family_name")!="逍遥派")
		return "你不是逍遥派弟子，打听祖师干啥。";

	ob->move("/d/xiaoyao/yandong");
	command("say 好吧，想见祖师我送你去。\n");
	message_vision(HIY"范百龄打开棋盘下的暗道让$N进了去。\n"NOR,ob);
                 return "这个密道可千万不要随便告诉别人。\n";	
}

void attempt_apprentice(object ob)
{
	if(ob->query_dex() < 20 ) {
		command("say 我派凌波微步是以身法为主，你的身法才"+ chinese_number(ob->query_dex())+"，还不够呀！");
		command("say " + RANK_D->query_respect(ob) + "的基本轻功是否还应该有所提高啊？");
		return;
	}

	if (ob->query_int() < 20) {
		command("say 我逍遥派武功最重视“逍遥”二字，何谓“逍遥”，这只能靠你自己去领悟。");
		command("say 但是" + RANK_D->query_respect(ob) + "的悟性似乎还有待提高啊。");
		return;
	}
	command("nod");
	command("say 好好，我就收下你吧！");
	command("recruit " + ob->query("id"));
	ob->set("class","scholar");
}
