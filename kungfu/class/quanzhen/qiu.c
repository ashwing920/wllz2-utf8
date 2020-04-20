// qiu.c 丘处机

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_yaochu();

void create()
{
	set_name("丘处机", ({"qiu chuji", "qiu"}));
	set("gender", "男性");
	set("age", 36);
	set("class", "taoist");
	set("nickname",HIM"长春子"NOR);
	set("long",@LONG
他就是江湖上人称‘长春子’的丘处机丘真人，他方面大耳，满面红光，
剑目圆睁，双眉如刀，相貌威严，平生疾恶如仇。
LONG
);
	set("attitude", "heroism");
	set("shen_type",1);
	set("str", 32);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("title","全真七子之四");

	set("chat_chance_combat", 60);
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

	set("jing",3000);
	set("max_jing",3000);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali",225);

	set("combat_exp",2700000);
	set("score", 10000);

	set_skill("force", 300);
	set_skill("xiantian-qigong", 300);
	set_skill("sword", 300);
	set_skill("quanzhen-jian",300);
	set_skill("dodge", 300);
	set_skill("jinyan-gong", 300);
	set_skill("parry", 300);
	set_skill("unarmed",300);
	set_skill("haotian-zhang", 300);
	set_skill("literate",300);
	set_skill("strike",300);
	set_skill("taoism",300);
	set_skill("whip",300);
	set_skill("duanyun-bian",300);
	set_skill("cuff",300);
	set_skill("chunyang-quan",300);
	map_skill("cuff","chunyang-quan");
	map_skill("whip","duanyun-bian");
	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("strike", "haotian-zhang");
	prepare_skill("strike", "haotian-zhang");
	prepare_skill("cuff","chunyang-quan");
	create_family("全真教", 2, "弟子");

	set("give_yaochu",10);
	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"药锄": (: ask_yaochu :),
	]) );

	setup();

	carry_object("/clone/weapon/fuchen")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void init()
{
	object ob;
	if(interactive(ob = this_player()) && !is_fighting()){
		remove_call_out("greeting");
		call_out("greeting", 1,ob);
	}
}
void greeting(object ob)
{
	mapping fam;

	if(!ob || environment(ob) != environment()) return;
	if(!mapp(fam = ob->query("family")) || fam["family_name"] != "全真教"){
		if(ob->query("shen")>-5000)
			command("say 这里是本教重地，你走动小心些。");
		else {
			command("say 你这魔头，竟敢闯入我全真重地，我一定要杀了你！");
			this_object()->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
		}
	}
	else {
		command("smile "+ob->query("id"));
	}
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("xiantian-qigong",1) < 100 ) {
		command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen") < 10000) {
		command("say 行侠仗义是我辈学武人的基本品质，你若能多做些狭义之事，我一定收你为徒。\n");
		return;
	}
	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}
string ask_yaochu()
{
	mapping fam;
	object me,ob;
	me = this_player();

	if(!(fam = me->query("family")) || fam["family_name"] != "全真教")
		return "这位"+ RANK_D->query_respect(me)+"与本派素无来往，不知此话从何谈起？";

	if(query("give_chu") < 0)
		return "药锄已经被其他人拿走了，你稍后再来吧。";

	if(me->query_temp("get_yaochu") || present("yaochu",me))
		return "你不是已经拿了药锄了吗？";

	ob = new(__DIR__"yaochu");
	ob->move(me);
	add("give_yaochu",-1);
	me->set_temp("get_yaochu",1);
	message_vision("$N给$n一把药锄。\n",this_object(),me);
		return "嗯..山腰处有一片树林，你可以拿这把药锄去采一些药材回来。";
}
void reset()
{
	set("give_yaochu",10);
	set("book_count",1);
}
