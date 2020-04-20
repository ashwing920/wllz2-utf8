//xunbu.c 巡捕

#include <ansi.h>

inherit NPC;

void create()
{
	int iType;

	iType = random(9);

	if(( iType == 1 ) || ( iType == 2 ))
		set_name("捕快", ({ "xun bu" }) );
	else if(( iType == 3 ) || ( iType == 4 ))
		set_name("巡捕", ({ "xun bu" }) );
	else
		set_name("捕头", ({ "xun bu" }) );

	set("long",sprintf("这是一位%s，身着官服，腰赔钢刀的巡捕，一脸严肃，看起来让人害怕。\n", name()));
	set("age", random(30)+10);
	set("gender", "男性");
	set("str", 24);
	set("dex", 46);

	set("jing",50000);
	set("max_jing",50000);
	set("jingli",50000);
	set("max_jingli",50000);
	set("neili",150000);
	set("max_neili",150000);
	set("combat_exp",51200000);
	set("shen_type", 1);
	set("jiali",800);

	set_temp("apply/shade_vision",1000);
	set_temp("apply/astral_vision",1000);

	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
		(: perform_action, "blade.duan":),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));

	set_skill("force",1000);
	set_skill("unarmed",1000);
	set_skill("blade",1000);
	set_skill("parry",1000);
	set_skill("dodge",1000);
	set_skill("hunyuan-yiqi",1000);
	set_skill("wuhu-duanmendao",1000);
	set_skill("yingfeng-steps",1000);
	set_skill("xiaohun-zhang",1000);
	set_skill("perception",1000);

	set_temp("apply/damage",2000);
	set_temp("apply/armor",2000);

	map_skill("dodge", "yingfeng-steps");
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("parry", "wuhu-duanmendao");
	map_skill("unarmed","xiaohun-zhang");

	set("chat_chance",5);
	set("chat_msg", ({
		(: random_move :),
	}));
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/junfu")->wear();

}

void init()
{
	object ob;

	::init();
	if(objectp(ob = this_player()) 
	&& userp(ob) &&	ob->query_condition("killer")) {
		kill_ob(ob);
		set_leader(ob);
	}
	add_action("do_halt","halt");
}
int accept_fight(object me)
{
	me = this_player();
	command("chat 大胆！你这个"+ RANK_D->query_rude(me) +"竟然敢对本大爷下手？！");
	me->apply_condition("killer",500);
	set_leader(me);
	return 1;
}
int accept_kill(object me)
{
	command("chat 大胆！你这个"+ RANK_D->query_rude(me) +"竟然敢对本大爷下手？！");
	me->apply_condition("killer",500);
	set_leader(me);
	return 1;
}
int do_halt(string arg)
{
	object ob,me;
	ob = this_player();
	me = this_object();
	if(wizardp(me)) return 0;
	if( ob->is_fighting(me) && me->is_fighting(ob)){
		message_vision("$N想跳出战圈不打了，$n喝道：想逃？没那么容易！\n",ob,me);
		return 1;
	}
	return 0;
}
