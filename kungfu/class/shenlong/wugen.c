// wugeng.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("无根道长", ( { "wugen daozhang", "wugen","daozhang" }) );
	set("title", HIY"神龙教"HIR"赤龙使"NOR);
	set("gender", "男性" );
	set("age", 55);
	set("long",@LONG
这是个五十来岁的黑须道长,相貌威武,眼中略带杀气。
LONG
);
	set("int", 30);
	set("str", 25);
	set("con", 25);
	set("dex", 25);

	set("jing",2000);
	set("max_jing",2000);
	set("neili",4000);
	set("max_neili",4000);
	set("jiali",200);
	set("combat_exp",800000);
	set("score",15000);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 80);

	set_skill("unarmed",200);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("staff", 200);
	set_skill("literate", 200);
	set_skill("poison",200);
	set_skill("huashan-zhangfa", 200);
	set_skill("huashan-shenfa",200);
	set_skill("huashan-sword", 200);
	set_skill("zixia-shengong", 200);
	set_skill("shenlong-xinfa", 200);
	set_skill("shedao-qigong", 200);
	set_skill("sword",200);
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-sword");
	map_skill("sword", "huashan-sword");

	create_family("神龙教",2,"弟子");

	set("inquiry", ([
		"洪安通" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"教主" :  "\n教主脾气不好,要讨他欢心才好。\n",
		"口号" : "\n万年不老！永享仙福！寿与天齐！文武仁圣！\n",
	]));
	setup();
	carry_object("/clone/weapon/duanjian")->wield();
	carry_object("/clone/cloth/cloth")->wield();
	add_money("silver",10);
}

void init()
{
	object ob;
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting",10, ob);
	}
	add_action("do_join","join");
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
	command("say 我不收徒！");
	return;
}
