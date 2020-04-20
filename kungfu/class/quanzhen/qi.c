// qi.c 祁志诚

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("祁志诚", ({"qi zhicheng", "qi"}));
	set("gender", "男性");
	set("age", 24);
	set("class", "taoist");
	set("long",@LONG
他就是全真教第三代弟子中的好手，谭处端的大弟子祁志诚。他相貌英俊
，精明能干，深受长辈的信任，派遣他去掌管教中的经书典籍。
LONG
);
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 25);
	set("int", 25);
	set("con", 24);
	set("dex", 24);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
	}));

	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);

	set("combat_exp", 160000);
	set("score", 100000);

	set_skill("force", 100);
	set_skill("xiantian-qigong", 100);
	set_skill("sword", 100);
	set_skill("quanzhen-jian",100);
	set_skill("dodge", 100);
	set_skill("jinyan-gong", 100);
	set_skill("parry", 100);
	set_skill("unarmed",100);
	set_skill("strike",100);
	set_skill("haotian-zhang", 100);
	set_skill("literate",100);
	set_skill("taoism",100);
	set_skill("whip",100);
	set_skill("duanyun-bian",100);
	set_skill("cuff",100);
	set_skill("chunyang-quan",100);
	map_skill("cuff","chunyang-quan");
	map_skill("whip","duanyun-bian");
	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("strike", "haotian-zhang");
	prepare_skill("strike", "haotian-zhang");
	prepare_skill("cuff","chunyang-quan");
	create_family("全真教", 3, "弟子");

	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"道德经" : (: ask_me :),
	]) );

	setup();

	carry_object("/clone/weapon/fuchen")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family")) || fam["family_name"] != "全真教")
		return RANK_D->query_respect(this_player()) +
		"与本教毫无瓜葛，你这话可叫我弄不明白了。";
	if (query("book_count") < 1)
		return "你来晚了，道德经已经被人取走了。";
	add("book_count", -1);
	ob = new("/d/quanzhen/npc/obj/daodejing-ii");
	ob->move(this_player());
	message("channel:rumor",HIM"【武林传奇】某人："+ this_player()->name() +"拿到「道德经」了！\n"NOR,users());
	return "好吧，这本「道德经」你拿回去好好研读。";

}
