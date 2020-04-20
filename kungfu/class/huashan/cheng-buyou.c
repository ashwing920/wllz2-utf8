// cheng-buyou.c  成不忧

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name("成不忧", ({ "cheng buyou", "cheng" }) );
	set("gender", "男性");
	set("class", "swordsman");
	set("title", "华山剑宗第十三代弟子");
	set("age", 41);
	set("long",@LONG
一个白净面皮的矮子，可也不能小看他。
LONG
);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);

	set("combat_exp",6400000);
	set("shen_type",1);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: perform_action, "sword.feilong" :),
		(: exert_function, "powerup" :),
	}) );

	set_skill("unarmed", 400);
	set_skill("sword", 400);
	set_skill("force", 400);
	set_skill("parry", 400);
	set_skill("dodge", 400);
	set_skill("literate", 400);
	set_skill("huashan-sword", 400);
	set_skill("huashan-neigong", 400);
	set_skill("huashan-ken", 400);
	set_skill("huashan-zhangfa", 400);
	set_skill("huashan-shenfa", 400);

	map_skill("sword", "huashan-sword");
	map_skill("parry", "huashan-sword");
	map_skill("force", "huashan-neigong");
	map_skill("unarmed", "huashan-zhangfa");
	map_skill("dodge", "huashan-shenfa");

	create_family("华山剑派", 13, "弟子");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	object ob;
	if( interactive(ob=this_player()) && !is_fighting() ){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if(ob->query("family/master_id") != "yue buqun")
		  say ("成不忧说：这位"+RANK_D->query_respect(ob) + "，来投我剑宗吧。\n");
	else{
		  message_vision("成不忧一见$N就大怒：我最讨厌伪君子的徒弟了。\n", ob);
		  this_object()->kill_ob(ob);
	}
	return;
}

void attempt_apprentice(object ob)
{
	command("say 老夫从不收徒，你找我封师兄好了。");
}

