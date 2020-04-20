// yuebuqun.c 岳不群

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
void do_recruit(object ob);

void create()
{
	set_name("岳不群", ({ "yue buqun", "yue" }) );
	set("nickname","君子剑");
	set("gender", "男性");
	set("class", "swordsman");
	set("age", 55);
	set("long",@LONG
岳不群自幼执掌华山剑派，乃当今武林中一等一的高手。
LONG
);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);

	set("combat_exp",51200000);
	set("shen_type",-1);

	set("apprentice_available", 3);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
		(: perform_action, "wushuang" :),
		(: perform_action, "jianzhang" :),
		(: perform_action, "feilong" :),
	}) );

	set_skill("unarmed", 800);
	set_skill("sword", 800);
	set_skill("force", 800);
	set_skill("parry", 800);
	set_skill("dodge", 800);
	set_skill("literate", 800);
	set_skill("huashan-sword", 800);
	set_skill("zixia-shengong", 800);
	set_skill("huashan-ken", 800);
	set_skill("feiyan-huixiang", 800);
	set_skill("zhengqijue", 800);

	map_skill("sword", "huashan-sword");
	map_skill("parry", "huashan-sword");
	map_skill("force", "zixia-shengong");
	map_skill("unarmed", "huashan-ken");
	map_skill("dodge", "feiyan-huixiang");

	create_family("华山剑派", 13, "掌门");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/book/zixia_book");
}
void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say 慢著，一个一个来。");
		else
			do_recruit(ob);
	} else {
		command("say 老夫今天已经收了三个弟子，不想再收徒了。");
	}
}

void do_recruit(object ob)
{
	if( (int)ob->query_int() < 20 )
		command("say 我华山剑派以剑法为主，依我看"+RANK_D->query_respect(ob)+"不适合于学剑法。");
	else {
		command("say 好，好，好，很好。");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	add("apprentice_availavble", -1);
}
void reset()
{
	set("apprentice_available", 3);
}
