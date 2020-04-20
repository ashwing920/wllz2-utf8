// rascal.c

#include <ansi.h>

inherit NPC;

void create()
{
	int level;
	string myname;
	myname = NAME_D->random_name(1)+NAME_D->random_name(4)+NAME_D->random_name(4);
	set_name(myname,({"hengshan dizi","di zi"}));
	set("gender","女性");
	set("long",@LONG
她是恒山派的一个小尼姑，一身道袍，清风飘逸，看起来武功平平，身手
不见得怎么样。
LONG
);
	set("attitude","heroism");
	set("age", random(20) + 30);
	set("str", 20 + random(11));
	set("cps", 20 + random(11));
	set("cor", 20 + random(11));
	set("per", 20 + random(11));
	set("int", 20 + random(11));
	set("con", 20 + random(11));
	set("spi", 20 + random(11));
	set("kar", 20 + random(11));

	set("chat_chance_combat",5);
	set("chat_msg_combat", ({
		sprintf(HIW"\n%s惊惶失色，惊叫道：救命("HIG"saveme"HIW")啊～～救命("HIG"saveme"HIW")啊～～\n\n"NOR, name()),
	}) );
	set("chat_chance",5);
	set("chat_msg", ({
		(: random_move :)
	}));

	set("jing",2000);
	set("max_jing",2000);
	set("max_qi",4000);
	set("qi",4000);
	set("neili",5000);
	set("max_neili",5000);
	set("jiali",200);
	set("shen_type",-1);
	set("bellicosity",8000);

	level = 100 + random(100);
	set_skill("literate", level);
	set_skill("force", level);
	set_skill("dodge", level);
	set_skill("unarmed", level);
	set_skill("parry", level);
	set_skill("whip", level);
	set_skill("blade", level);
	set_skill("sword", level);
	set_skill("hand", level);
	set_skill("claw", level);
	set_skill("lingxu-bu",level);
	set_skill("hengshan-jian",level);

	map_skill("dodge","lingxu-bu");
	map_skill("sword","henshan-jian");

	set("combat_exp",500000 + (100000 * random(10)));
	create_family("恒山派",random(15) + 10,"弟子");
	setup();
	carry_object("/d/shaolin/obj/cheng-cloth")->wear();
	carry_object("/clone/weapon/sword")->wield();
	remove_call_out("back");
	call_out("back",300,this_object());
}
void init()
{
	add_action("do_saveme","saveme");
}
int do_saveme(string arg)
{
	object me;
	int m,n;
	me = this_player();

	if(!id(arg)) return 0;
	if(!me->query_temp("save_hengshan")) return 0;

	if((int)me->query("shen") > 0)
		message_vision("$N对$n做了一个鞠道：多谢这位"+ RANK_D->query_respect(me)+"拔刀相助！免我遭那贼人毒手！\n",this_object(),me);
	else
		message_vision("$N冷冷的看了$n一眼，说道：虽然你今日救我，可你我正邪两派誓不两立，就等他日再领教"+ RANK_D->query_respect(me) +"高招吧！\n",this_object(),me);

	message_vision("$N说完，匆匆忙忙的离开了。\n",this_object());
	message("channel:chat",HIG"【大话泥潭】"+ sprintf(NOR + WHT"%s把嵩山派派来的刺客杀死了，拯救了恒山派的%s。\n"NOR,me->name(),this_object()->name()),users());
	m = 100 + random(50);
	n = 150 + random(100);
	me->add("potential",m);
	me->add("combat_exp",n);
	me->add("score",50);
	SCORE_D->set_score(me);
	tell_object(me,"你从嵩山派弟子的手中救出了恒山派弟子"+ this_object()->name(1) +"。\n");
	tell_object(me, sprintf("你的潜能增加了%s点！\n", chinese_number(m)));
	tell_object(me, sprintf("你的经验增加了%s点！\n", chinese_number(n)));
	tell_object(me, "你的江湖阅历增加了五十点！\n");
	me->add_temp("save_hengshan",-1);
	destruct(this_object());
	return 1;
}
void back()
{
	if(!this_object() || !environment(this_object())) return;
	destruct(this_object());
}