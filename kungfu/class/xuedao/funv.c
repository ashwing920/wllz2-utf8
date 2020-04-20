//whitlady.c

#include <ansi.h>; 
inherit NPC;
int ask_me();

void create()
{
	set_name("少女", ({ "shao nv","nv","girl" }) );
	set("gender", "女性" );
	set("age", 18);
	set("long", "一个擅长姹女法的魔派少女。\n");
	set("shen_type", -1);
	set("combat_exp", 100000);
	set("str", 20);
	set("dex", 18);
	set("con", 19);
	set("int", 20);
	set("attitude", "friendly");
	   set("inquiry", ([
		"双修" : (:ask_me:),
	]) );


	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("score", 800);

	set_skill("force",80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 12);
	set_temp("apply/defense", 12);
	set_temp("apply/damage", 11);
	set_temp("apply/armor", 7);
	setup();
	carry_object("/d/baituo/obj/baipao")->wear();
}
int ask_me()
{
	object ob;
	ob=this_player();

	if (ob->query("family/family_name") != "血刀门")
		return notify_fail("你不是我魔派弟子，我不和你做些事。\n");
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi")){
		command("?"+ob->query("id"));	 
		command("say 你必要找我啊？\n");
		return 1;
	}
	else{
	 message_vision("少女抱着$N滚倒在床上，按要决和$N双修魔功。\n", ob);
		remove_call_out("recover");
		call_out("recover",2,ob);
		return 1;
	}
}


int recover(object ob)
{
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("过了一阵，少女起身整整衣服。\n",ob);
	command("say 你的伤势已经全好了，可以做事了，下次来。\n");
	return 1;
}
