//shanzei.c 山贼

#include <ansi.h>

inherit NPC;

void create()
{
	int iType;

	iType = random(9);

	if( iType == 1 < 4){
		set_name(npc_name("男性"), ({ "biaoxing dahan","dahan"}));
		set("title","彪形大汉");
		set("long",@LONG
这是一个高大魁梧，十分壮硕的彪形大汉。五大三粗的身段，却是一个呆
头呆脑的家伙。
LONG);
		set("str",100);
	} else{
		set_name(npc_name("男性"), ({ "ren fanzi","fanzi"}));
		set("title","人贩子");
		set("long",@LONG
这是一个阴险狡诈的人贩子。骨瘦如柴，尖耳猴腮，一副刁钻的嘴脸。
LONG);
		set("dex",100);
	}

	set("age", random(20)+20);
	set("gender", "男性");

	set("jing",6000);
	set("max_jing",6000);
	set("neili",12000);
	set("max_neili",12000);
	set("qi",9000);
	set("max_qi",9000);
	set("jiali",200);
	set("combat_exp",2000000);

	set_temp("apply/armor",400);

	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}));
	set_skill("dodge",210);
	set_skill("parry",210);
	set_skill("unarmed",210);
	set_skill("force",210);
	set_skill("blade",210);
	set_skill("perception",210);
	set_skill("jinwu-daofa",210);
	set_skill("huashan-shenfa",210);
	set_skill("huashan-ken",210);
	set_skill("huashan-neigong",210);

	map_skill("force","huashan-neigong");
	map_skill("blade","jinwu-daofa");
	map_skill("dodge","huashan-shenfa");
	map_skill("unarmed","huashan-ken");
	map_skill("parry","jinwu-daofa");

	set("chat_chance",15);
	set("chat_msg", ({
		(: random_move :),
	}));
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/misc/shoe")->wear();

}
void init()
{
	object ob;

	if(interactive(ob = this_player())){
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
		e = i + (int)killer->query_temp("kill_"+ me->query("title"));
		p = e + random(20);
		if( p > 200) p = 200;
		if( e > 200) e = 200;
		killer->add("potential",p);
		killer->add("combat_exp",e);
		tell_object(killer,sprintf(HIC"在这场战斗中，你的实战经验提高了%s点，潜能增长了%s点。\n"NOR,
		chinese_number(e),chinese_number(p)));
		killer->add_temp("kill_"+ me->query("title"),1);
	}
}
