//shanzei.c 山贼

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(npc_name("男性"), ({ "shanzei shouling","shouling","shanzei" }));
	set("title","山贼首领");
	set("long",@LONG
他是盗贼山洞中的首领之一，强壮，高大魁梧的身段，一看就知道是个练
武之人。
LONG);
	set("age", random(20)+20);
	set("gender", "男性");
	set("str", 30 + random(20));
	set("dex", 50);

	set("jing",9000);
	set("max_jing",9000);
	set("neili",15000);
	set("max_neili",15000);
	set("qi",9000);
	set("max_qi",9000);
	set("jiali",200);
	set("combat_exp",2500000);

	set_temp("apply/armor",550);

	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}));
	set_skill("dodge",250);
	set_skill("parry",250);
	set_skill("unarmed",250);
	set_skill("force",250);
	set_skill("blade",250);
	set_skill("perception",250);
	set_skill("ruyi-dao",250);
	set_skill("zhaixinggong",250);
	set_skill("chousui-zhang",250);
	set_skill("hamagong",250);

	map_skill("force","hamagong");
	map_skill("blade","ruyi-dao");
	map_skill("dodge","zhaixinggong");
	map_skill("unarmed","chousui-zhang");
	map_skill("parry","ruyi-dao");

	set("chat_chance",15);
	set("chat_msg", ({
		(: random_move :),
	}));
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/blackcloth")->wear();
	carry_object(__DIR__"obj/blackhat")->wear();
	carry_object(__DIR__"obj/blackshield")->wear();
}
void init()
{
	object ob;

	if(interactive(ob = this_player())){
		say(this_object()->name()+"喝道：你这"+ RANK_D->query_rude(ob)+"活得不耐烦了，竟敢闯入我们山洞来，纳命来！！\n\n");
		this_object()->kill_ob(ob);
		this_object()->set_leader(ob);
		ob->kill_ob(this_object());
	}
}

void afterdie_func(object killer)
{
	object me;
	int p,e,i;

	me = this_object();

	message_vision("$N将$n杀死了！\n", killer,me);
	if((string)killer->query_temp("apply_job/guanfu/place") == "盗贼山洞"){
		i = (int)me->query("combat_exp") / 20000;
		if( i > 200 ) i = 200;
		e = i + (int)killer->query_temp("apply_job/guanfu/kill_"+ me->query("title"));
		p = e + random(20);
		if( p > 200) p = 200;
		if( e > 200) e = 200;
		killer->add("potential",p);
		killer->add("combat_exp",e);
		tell_object(killer,sprintf(HIC"在这场战斗中，你的实战经验提高了%s点，潜能增长了%s点。\n"NOR,
		chinese_number(e),chinese_number(p)));
		killer->add_temp("apply_job/guanfu/kill_"+ me->query("title"),1);
		killer->apply_condition("apply_guanfu",killer->query_condition("apply_guanfu") +1);
	}
}
