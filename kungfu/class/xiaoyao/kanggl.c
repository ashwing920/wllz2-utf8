// kanggl.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_me();

void create()
{
	set_name("康广陵", ({ "kang guangling", "kang" }));
	set("long", @LONG
只见他高额凸颡，容貌奇古，笑眯眯的脸色极为和谟，手中抱着一具瑶琴。
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
		"棋谱":(:ask_me:),
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
	set("nickname","琴颠");
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/blade")->wield();

}


string ask_me()
{
	object me,ob;
	ob=this_player();
	if (query("book_count") < 1)
		return "你来晚了，棋谱我已经赠送给别入了。";

	add("book_count", -1);
	command("say 好吧，那我就把它送给你了。\n");
	message_vision(HIY"康广陵微笑着从怀中拿出了一本书，交了给$N。\n"NOR,ob);
	me=new("/clone/book/hand_book");
	me->move(ob);
	return "这本棋谱可千万不要随便给别人。\n";
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
