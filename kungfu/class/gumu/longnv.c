// longnv.c 小龙女

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_yunv();
string ask_yin();
int ask_tianluo();

void create()
{
	set_name("小龙女", ({"long nv","long"}));
	set("gender", "女性");
	set("age", 22);
	set("long",@LONG
她一生爱穿白衣，当真如风拂玉树，雪裹琼苞，兼之生性清冷，实当
得起“冷浸溶溶月”的形容。
LONG
);
	set("attitude", "friendly");
	set("per", 30);
	set("str", 30);
	set("int", 37);
	set("con", 36);
	set("dex", 38);

	set("chat_chance_combat",60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "duo" :),
		(: perform_action, "you" :),
	}) );

	set("shen_type",1);
	set("jing",3000);
	set("max_jing",3000);
	set("jingli",3000);
	set("max_jingli",3000);

	set("combat_exp",2700000);

	set_skill("force", 300);
	set_skill("yunv-xinfa", 300);
	set_skill("sword", 300);
	set_skill("yunv-jian", 300);
	set_skill("quanzhen-jian",300);
	set_skill("dodge", 300);
	set_skill("yunv-shenfa", 300);
	set_skill("parry", 300);
	set_skill("hubo", 300);
	set_skill("unarmed",300);
	set_skill("meinv-quan",300);
	set_skill("literate",300);
	set_skill("qufeng",300);
	set_skill("tianluo-diwang",300);

	map_skill("force", "yunv-xinfa");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");

	create_family("古墓新派", 3, "弟子");

	set("book_count", 1);
	set("ask_shoutao",1);

	set("inquiry", ([
		"玉女剑法" : "玉女剑法和全真剑法合壁，天下无敌！\n",
		"古墓新派" : "我的林祖师爷爷本来和重阳先师是一对璧人，可是...\n",
		"玉女心经" : (: ask_yunv :),
		"过儿":      "过儿不就在我身旁吗？\n",
		"尹志平": (: ask_yin() :),
		"天罗地网式":(: ask_tianluo() :),
	]));

	set("env/wimpy", 40);
	setup();

	carry_object("/d/gumu/npc/obj/shunvjian")->wield();
	carry_object("/d/gumu/npc/obj/baipao")->wear();

}
void attempt_apprentice(object ob)
{
	if(ob->query("per") < 20)
	{
		command("say 尊容实在不敢恭维，恐怕学不了玉女心法。");
	}
	else
	{
		command("say 好吧，我就收下你这个徒弟了。");
		command("recruit " + ob->query("id"));
	}
}

string ask_yunv()
{
	mapping fam;
	object ob;

	if (!(fam = this_player()->query("family"))|| fam["family_name"] != "古墓新派")
		return RANK_D->query_respect(this_player()) +"与本派毫无瓜葛，何以问起本派的心经？";
	if (query("book_count") < 1)
		return "你来晚了，本派的玉女心经已经被人取走了。";
	add("book_count", -1);
	ob = new("/clone/book/yunvjing1");
	ob->move(this_player());
	CHANNEL_D->do_channel(this_object(),"rumor",sprintf("%s拿到%s了！",this_player()->name(),ob->name()));
	return "好吧，这本「玉女心经」你拿回去好好研读。";
}

string ask_yin()
{
	object me;
	me = this_player();
	
	if(me->query("marks/小龙女"))
		return "多谢这位"+ RANK_D->query_respect(me)+"替我了却了一桩心事。";
		
	if(me->query_temp("ask_yin",1))
		return "昨日之事，历历在目，此仇不报，枉此一生。";

	me->set_temp("ask_yin",1);
		return "尹志平那狗贼，趁我不防，夺我清白，若是让我碰到，非杀了他不可！";

}
int accept_object(object who, object ob)
{
	if( ob->query("name") == HIR"尹志平的头颅"NOR 
	&& who->query_temp("ask_yin")
	&& ob->query("last_damage_from") == who ) {
		message_vision("$N说道：多谢这位"+ RANK_D->query_respect(who)+"替我了却了一桩心事。\n",this_object());
		if(!who->query("marks/小龙女")){
			CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s(%s)替小龙女了却了一桩心事，获得了一些奖励。",who->name(),who->query("id")));
			tell_object(who,"由于你替小龙女了却了一桩心事，你的潜能提高了 1000 点。\n");
			who->add("learned_points",-1000);
			who->delete_temp("ask_yin");
			who->set("marks/小龙女",1);
			if((string)who->query("gender") == "女性"){
				message_vision("$N微微笑道：你我既然如此有缘，你若是有兴趣，我可以教你一套武功。\n",this_object());
				who->set("learn_from_longnv",600);
			}
		}
		return 1;
	} 
}
int recognize_apprentice(object ob)
{
	if (!(int)ob->query("learn_from_longnv")) return 0;
	ob->add("learn_from_longnv",-1);
	return 1;
}
int ask_tianluo()
{
	object me,obj;
	
	me = this_player();
	
	if(me->query("family/family_name")!= "古墓新派"){
		say(name() +"冷冷的说道：古墓派岂是你随意进出的地方？受死吧。\n");
		kill_ob(me);
		return 1;
	}
	if((int)me->query_skill("tianluo-diwang",1) > 50
	&& query("ask_shoutao")){
		say(name()+"说道：这里有一双天蚕丝手套，你拿去练本门入门武功“天罗地网式”，一定事半功倍。\n");
		obj = new("/d/gumu/npc/obj/shoutao");
		obj->move(me,1);
		delete("ask_shoutao");
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s拿到%s了。"NOR,
			me->name(),obj->name() +HIM));
		return 1;
	}
	say(name()+"说道：天罗地网式是古墓派的入门武功，你要多加练习，才能领悟本门更高深的武功。\n");
	return 1;
}
