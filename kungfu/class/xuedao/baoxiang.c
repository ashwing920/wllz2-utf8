//baoxiang.c  宝象

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("宝象", ({ "bao xiang", "bao", "xiang" }));
	set("long",@LONG
一个极高极瘦的僧人，俩眼凶芒四射。此人在血刀老祖
门下，最是心狠手辣。
LONG
);
	set("gender", "男性");
	set("age", 35);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",4000);
	set("max_jing",4000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali", 300);
	set("combat_exp",6400000);
	set("score", 40000);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "blade.jtmd" :),
		(: perform_action, "strike.xue" :),
		(: perform_action, "strike.jue" :),
		(: perform_action, "unarmed.luan" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

	set_skill("lamaism", 400);
	set_skill("literate", 400);
	set_skill("force", 400);
	set_skill("parry", 400);
	set_skill("blade", 400);
	set_skill("dodge", 400);
	set_skill("xuehai-mogong", 400);
	set_skill("xuedun", 400);
	set_skill("strike", 400);
	set_skill("miexian-zhang", 400);
	set_skill("xue-dao", 400);
	set_skill("unarmed",400);
	set_skill("wuying-shenquan",400);
	map_skill("unarmed","wuying-shenquan");
	map_skill("force", "xuehai-mogong");
	map_skill("dodge", "xuedun");
	map_skill("strike", "miexian-zhang");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");

	create_family("血刀门",3,"弟子");
	set("class", "bonze");

	setup();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
	carry_object("/d/xuedao/obj/xblade1")->wield();

	add_money("gold",1);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("gender") != "男性")
	{
		command("say 我不收女徒弟。\n");
		return;
	}
	if (ob->query("shen") > 0)
	{
		command("say 我正想找你们侠义道的晦气。");
		this_object()->kill_ob(ob);
		return;
	}
	if ((int)ob->query_skill("xuehai-mogong", 1) < 300)
	{
		command("say 入我血刀门，修习血海魔功是首要的。\n");
		return;
	}
	if ((int)ob->query("shen") > - 30000)
	{
		command("say 你是不是向着侠义道，连杀人都不会！\n");
		return;
	}
	if((int)ob->query("MKS") < 3000)
	{
		command("say 学习血海魔功必须心狠手辣，看来你还做得不够呀！\n");
		return;
	}


	command("haha");
	command("recruit " + ob->query("id"));
}


