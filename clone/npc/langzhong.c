// langzhong.c - 江湖郎中。

#include <ansi.h>

inherit NPC;
string ask_me();
void create()
{

	set_name(npc_name("男性"),({ "lang zhong","dorctor",}) );
	set("title","江湖郎中");
	set("long", @LONG
他是一个四处行医的江湖郎中。
LONG
);

	set("attitude", "friendly");
	set("gender", "男性" );
	set("age",30 + random(10));

	set("combat_exp",400000);
	set("env/wimpy", 30);

	set_skill("unarmed",60); 
	set_skill("parry",  60);
	set_skill("dodge",  60);

	set("chat_chance",10);
	set("chat_msg", ({
		(: random_move:),
	}) );
	set("inquiry", ([
		"治病" : (:ask_me:),
	]));
	setup();
	carry_object("/clone/cloth/gua-cloth")->wear();
}

int accept_object(object who, object ob)
{
       
	if( ob->value() >= 1000 ) {
		message_vision("$N对$n点了点头，说道：好吧，让我帮你看看。\n",this_object(),who);
		who->set_temp("give_doctor_money",1);
		remove_call_out("finish_doctor");
		call_out("finish_doctor",3,who);
		} 
	else   {
		command("say 这点儿钱就想让我帮你看病？你也太不够诚意了吧？");
		return 0;
	}
	return 1;
}
string ask_me()
{
	object me;
	me = this_player();
	
	if( me->query("eff_qi") == me->query("max_qi")
	&&  me->query("eff_jing") == me->query("max_jing"))
		return "你又没病，来找我干什么？";
	
	if( !me->query_condition("ill_shanghan")
	&& !me->query_condition("ill_fashao")
	&& !me->query_condition("ill_keshou")
	&& !me->query_condition("ill_dongshang")
	&& !me->query_condition("ill_zhongshu"))
		return "我只能医治一些伤寒，中暑的小病，其他的，只能另请高明了。";
	
	if(!me->query_temp("give_doctor_money"))
		return "要治病？一次十两银子。";
}
void finish_doctor()
{
	object me;
	me = this_player();
	
	if( me->query_condition("ill_shanghan"))
		me->apply_condition("ill_shanghan",0);
	if( me->query_condition("ill_fashao"))
		me->apply_condition("ill_fashao",0);
	if( me->query_condition("ill_keshou"))
		me->apply_condition("ill_keshou",0);
	if( me->query_condition("ill_dongshang"))
		me->apply_condition("ill_dongshang",0);
	if( me->query_condition("ill_zhongshu"))
		me->apply_condition("ill_zhongshu",0);
	
	me->set("eff_qi",me->query("max_qi"));
	me->set("qi",me->query("eff_qi"));
	me->set("eff_jing",me->query("max_jing"));
	me->set("jing",me->query("eff_jing"));
	message_vision("$N说道：好了，这位"+ RANK_D->query_respect(me)+"可要多保重身体才是。\n",this_object());
	return;
	
}
