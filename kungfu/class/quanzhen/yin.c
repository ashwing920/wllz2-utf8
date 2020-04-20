// yin.c 尹志平

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("尹志平", ({"yin zhiping", "yin"}));
	set("gender", "男性");
	set("class", "taoist");
	set("nickname", HIM"清和真人"NOR);
	set("age", 24);
	set("long",@LONG
他是丘处机的得意大弟子尹志平，他粗眉大眼，长的有些英雄气概，在全
真教第三代弟子中算得上年轻有为。身材不高，眉宇间似乎有一股忧郁之
色。长的倒是长眉俊目，容貌秀雅，面白无须，可惜朱雀和玄武稍有不和。
LONG
);
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 28);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

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

	set("jing", 6000);
	set("max_jing",6000);
	set("neili",10000);
	set("max_neili",10000);
	set("jiali",150);

	set("combat_exp",100000);
	set("score", 10000);
	set_temp("apply/armor",800);
	set_temp("apply/damage",100);
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
	prepare_skill("cuff", "chunyang-quan");
	create_family("全真教", 3, "弟子");

	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"小龙女": "....... 我不认识，不认识。\n",
	]) );
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}
void afterdie_func(object killer)
{
	if(killer->query_temp("ask_yin"))
	set("killer",killer->query("name"));
}
