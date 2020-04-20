#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("曲洋", ({ "qu yang", "qu",}));
	set("long", @LONG
此人乃日月神教十大长老之一，武功深不可测。而他更痴迷于琴曲之道，
琴艺可以称得上是当世第一人。
LONG
);
	set("title",HIM"日月神教长老"NOR);
	set("gender", "无性");
	set("age", 60);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 22);
	set("int", 25);
	set("con", 21);
	set("dex", 30);

	set("max_jing",3000);
	set("neili",4500);
	set("max_neili",4500);
	set("jiali",150);
	set("combat_exp",2700000);

	set_skill("tianmo-zhang",300);
	set_skill("tianmo-sword",300);
	set_skill("tianmo-dao",300);
	set_skill("piaomiao-shenfa",300);
	set_skill("tianmo-dafa",300);

	map_skill("unarmed", "tianmo-zhang");
	map_skill("sword", "tianmo-sword");
	map_skill("parry", "tianmo-sword");
	map_skill("blade", "tianmo-dao");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "tianmo-dafa");
	create_family("日月神教",3,"长老");
	set("inquiry", ([
		"笑傲江湖曲" : (: ask_me :),
	]));
	set("book_count", 1);
	setup();
	carry_object("/d/heimuya/npc/obj/bi")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "日月神教")
		return RANK_D->query_respect(this_player()) + "与本教素无往来，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "笑傲江湖曲已赠知音人，你来晚一步了。";
	add("book_count", -1);
	ob = new("/d/heimuya/npc/obj/xo");
	ob->move(this_player());
	message("channel:rumor",HIM"【武林传奇】某人："+ this_player()->name()+"拿到笑傲江湖曲谱啦！\n"NOR,users());
	return "宝剑赠侠客，红粉配佳人，这本笑傲江湖曲就送给你吧，只盼你是个真正的知音人。";
}
