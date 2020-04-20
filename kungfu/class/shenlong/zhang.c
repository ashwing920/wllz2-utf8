// zhang.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("张淡月", ({ "zhang danyue", "zhang"}));
	set("title", HIY"神龙教"BLU"黑龙使"NOR);
	set("long",@LONG
这是一个黑衣大汉, 脸色大变, 身子发颤, 似乎恐惧已极。
LONG
);
	set("gender", "男性");
	set("age", 44);
	set("str", 35);
	set("dex", 20);

	set("max_jing",3000);
	set("jing",3000);
	set("combat_exp",800000);
	set("score", 20000);
	set("shen_type", -1);
	set("attitude", "peaceful");

	set_skill("force", 200);
	set_skill("hand", 200);
	set_skill("strike", 200);
	set_skill("staff", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("leg",200);
	set_skill("finger",200);
	set_skill("poison",200);
	set_skill("yixingbu", 200);
	set_skill("jueming-tui",200);
	set_skill("yingxiong-sanzhao",200);
	set_skill("shenlong-bashi", 200);
	set_skill("huagu-mianzhang", 200);
	set_skill("shenlong-xinfa", 200);
	set_skill("shedao-qigong", 200);
	set_skill("sword",200);

	map_skill("finger","yingxiong-sanzhao");
	map_skill("leg","jueming-tui");
	map_skill("staff", "shedao-qigong");
	map_skill("force", "shenlong-xinfa");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-qigong");
	map_skill("dodge", "yixingbu");
	prepare_skill("hand", "shenlong-bashi");
	prepare_skill("strike", "huagu-mianzhang");

	create_family("神龙教",2,"弟子");

	set("neili",4000);
	set("max_neili",4000);
	set("jiali",150);
	set("inquiry", ([
		"洪安通" :  "教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "教主脾气不好,要讨他欢心才好。\n",
		"口号" : "万年不老！永享仙福！寿与天齐！文武仁圣！\n",
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 10);
}
void init()
{
	object ob;

	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",10, ob);
	}
}
void greeting(object ob)
{
	object obj;
	if( !ob || environment(ob) != environment() ) return;
	if (interactive(ob)){
	if (obj = present("usedgao", ob))
		set("combat_exp",query("combat_exp")-100000);
	}
	return;
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("shenlong-xinfa",1) < 100 ) {
		command("say 你的本门内功心法太低了,还是努努力先提高一下吧！");
		return;
	}
	if ((int)ob->query_skill("shedao-qigong",1) < 100 ) {
		command("say 你的蛇岛奇功太低了,还是努努力先提高一下吧！");
		return;
	}
	if ((int)ob->query("shen") > 0  ) {
		command("say 我神龙教与世隔绝，向来不与您这种白道人物打交道，您请回吧！");
		return;
	}

	command("say 很好，很好。");
	command("recruit " + ob->query("id"));
}
