// wan-chunliu

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

int ask_me();

void create()
{
	set_name("齐玄轩",({"qi xuanxuan","qi"}));
	set("title",HIW"再世华佗"NOR);
	set("str",30);
	set("gender", "男性");
	set("age",48);
	set("long","他就是是桃源城里最有名的大夫，人称再世华佗。\n");
	set("combat_exp",200000);
	set("attitude","friendly");
	set("inquiry", ([
		"治病" : (:ask_me:),
	]));
	set("vendor_goods", ([
		"/clone/yaowu/lingzhi": 1,
		"/clone/yaowu/jinchuang": 1,
		"/clone/yaowu/yangjing": 1,
		"/clone/yaowu/wuchangdan": 1,
		"/clone/misc/dust": 1,
		"/d/shenlong/obj/xionghuang": 1,
		"/clone/yaowu/liqiwan": 1,
	]));
	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
	add_action("do_vendor_list", "list");
}
int accept_object(object who, object ob)
{
	if( ob->query("money_id")){
		if( !who->query_temp("ask_doctor")){
			command("say 无功不受禄，这位"+ RANK_D->query_respect(who)+"还是把钱收回去吧。");
			return 0;
		}

		if( ob->value() < 1000 ) {
			command("say 这点儿钱就想让我帮你看病？你也太不够诚意了吧？");
			return 0;
		} 
		message_vision("$N对$n点了点头，说道：好吧，让我帮你看看。\n",this_object(),who);
		remove_call_out("finish_doctor");
		call_out("finish_doctor",3,who);
		return 1;
	}

	command("say 你给我这个做什么？");
	return 0;
}
int ask_me()
{
	object me;
	me = this_player();
	
	if((int)me->query("eff_qi") == me->query("max_qi")
	&&(int)me->query("eff_jing") == me->query("max_jing")){
		command("say 你又没病，来找我干什么？");
		return 1;
	}
	
	if( me->query_condition("ill_shanghan") < 1
	&&  me->query_condition("ill_fashao") < 1
	&&  me->query_condition("ill_keshou") < 1
	&&  me->query_condition("ill_dongshang") < 1
	&&  me->query_condition("ill_zhongshu") < 1){
		command("say 我只能医治一些伤寒，中暑的小病，其他的，只能另请高明了。");
		return 1;
	}

	if(me->query_temp("ask_doctor")){
		command("say 请付上十两白银，老夫包你药到病除。");
		return 1;
	}

	me->set_temp("ask_doctor",1);
	command("say 嗯，要治病嘛，一次十两银子。");
	return 1;
}
void finish_doctor(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		
	if( ob->query_condition("ill_shanghan"))
		ob->apply_condition("ill_shanghan",0);
	if( ob->query_condition("ill_fashao"))
		ob->apply_condition("ill_fashao",0);
	if( ob->query_condition("ill_keshou"))
		ob->apply_condition("ill_keshou",0);
	if( ob->query_condition("ill_dongshang"))
		ob->apply_condition("ill_dongshang",0);
	if( ob->query_condition("ill_zhongshu"))
		ob->apply_condition("ill_zhongshu",0);
	
	ob->set("eff_qi",ob->query("max_qi"));
	ob->set("qi",ob->query("eff_qi"));
	ob->set("eff_jing",ob->query("max_jing"));
	ob->set("jing",ob->query("eff_jing"));
	message_vision("$N说道：好了，这位"+ RANK_D->query_respect(ob)+"可要多保重身体才是。\n",this_object());
	ob->delete_temp("ask_doctor");
	return;

}
