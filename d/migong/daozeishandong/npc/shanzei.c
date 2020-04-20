//shanzei.c 山贼

#include <ansi.h>

inherit NPC;

void create()
{
	int iType;

	iType = random(9);

	if( iType == 1 < 4){
		set_name(npc_name("男性"), ({ "shan zei" }));
		set("title","山贼");
	} else{
		set_name(npc_name("男性"), ({ "cao kou" }));
		set("title","草寇");
	}

	set("long",sprintf("这是一个穷凶极恶的%s，只见他手执钢刀，一双凶狠的眼睛射出一股迫人的杀气。\n",query("title")));
	set("age", random(20)+20);
	set("gender", "男性");
	set("str", 30 + random(20));
	set("dex", 50);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",8000);
	set("max_neili",8000);
	set("qi",5000);
	set("max_qi",5000);
	set("jiali",100);
	set("combat_exp",800000);

	set_temp("apply/armor",300);

	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));
	set_skill("dodge",150);
	set_skill("parry",150);
	set_skill("unarmed",150);
	set_skill("force",150);
	set_skill("blade",150);
	set_skill("perception",150);
	set_skill("jinwu-daofa",150);
	set_skill("huashan-shenfa",150);
	set_skill("huashan-ken",150);
	set_skill("huashan-neigong",150);

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
	carry_object(__DIR__"obj/blackcloth")->wear();

}
void init()
{
	object ob;

	if(interactive(ob = this_player())){
		say(this_object()->name()+"喝道：妈的！地狱无门你偏进来，受死吧！！\n\n");
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
	}
}
