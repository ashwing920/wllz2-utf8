//fae-shizhe.c 罚恶使者

#include <ansi.h>

inherit NPC;
void create()
{

	set("title","武林列传第"+ chinese_number(random(20) +1)+"代罚恶使");
	set_name(npc_name("男性"),({ "fae shizhe","shi zhe","fae"}));
	set("long",sprintf("他就是%s。\n",query("title")));
	set("age", random(30)+10);
	set("gender", "男性");
	set("str", 24);
	set("dex", 46);

	set("gender","男性");
	set("attitude", "heroism");
	set("chat_chance_combat",20);
	set("is_zongshi",1);
	set("chat_msg_combat", ({
		(: perform_action,"leg.lianhuan":),
		(: perform_action,"spear.zhimeng":),
		(: exert_function, "regenerate":),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}));
	add_temp("apply/damage",1000);
	add_temp("apply/armor",1000);
	add_temp("apply/dodge",1000);
	add_temp("apply/attack",1000);
	set("combat_exp",51200000);
	set_skill("force",800);
	set_skill("taixuan-gong",800);
	set_skill("leg",800);
	set_skill("jueming-tui",800);
	set_skill("cuff",800);
	set_skill("kongming-quan",800);
	set_skill("spear",800);
	set_skill("duanhun-qiang",800);
	set_skill("unarmed",800);
	set_skill("xianglong-zhang",800);
	set_skill("taoism",800);
	set_skill("dodge",800);
	set_skill("tiyunzong",800);

	map_skill("cuff","kongming-quan");
	map_skill("leg","jueming-tui");
	map_skill("unarmed","xianglong-zhang");
	map_skill("spear","duanhun-qiang");
	map_skill("force","taixuan-gong");
	map_skill("dodge","tiyunzong");
	create_family("武当派", 18,"弟子");
	setup();
	carry_object("clone/misc/cloth")->wear();
	carry_object("/clone/weapon/spear")->wield();
}
void init()
{
	object ob;

	if (interactive(ob = this_player())){
		if(ob->query_condition("killer")) {
			this_object()->kill_ob(ob);
			ob->kill_ob(this_object());
			this_object()->set_leader(ob);
		}
	}
	add_action("do_halt","halt");
}

int accept_fight(object me)
{
	me = this_player();
	command("chat 大胆！你这个"+ RANK_D->query_rude(me) +"竟然敢对本大爷下手？！");
	call_out("make_skill", 0,this_object());
	me->apply_condition("killer", 500);
	command("kill "+ me->query("id"));
	set_leader(me);
	return 1;
}
int do_halt(string arg)
{
	object ob,me;
	ob = this_player();
	me = this_object();
	if( ob->is_fighting(me) && me->is_fighting(ob)){
		message_vision("$N想跳出战圈不打了，$n喝道：想逃？没那么容易！\n",ob,me);
		return 1;
	}
	return 0;
}
int heal_up()
{
	if( environment() && !is_fighting()) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}
void leave()
{
	message("vision",name()+"急急忙忙地走开了。\n",environment(), this_object() );
	destruct(this_object());
}
