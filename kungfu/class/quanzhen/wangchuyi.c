// wangchuyi.c 王处一

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("王处一", ({"wang chuyi", "wang"}));
	set("gender", "男性");
	set("age", 35);
	set("class", "taoist");
	set("nickname",RED"玉阳子"NOR);
	set("long",@LONG
他就是全真七子之五王处一王真人。他身材修长，服饰整洁，三绺黑须飘
在胸前，神态潇洒。
LONG
);
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 32);
	set("int", 30);
	set("con", 32);
	set("dex", 30);

	set("title","全真七子之五");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
	}));

	set("chat_chance", 8);
	set("chat_msg", ({
		"王处一长叹一声，唉，可恨那杨康把我的药全都藏起来了。\n",
		"王处一道：谁能帮我找回药来，我一定重重酬谢他。\n",
	}));

	set("jing",3000);
	set("max_jing",3000);
	set("neili", 4500);
	set("max_neili",4500);
	set("jiali",225);

	set("combat_exp", 500000);
	set("score", 300000);

	set_skill("force", 300);
	set_skill("xiantian-qigong", 300);
	set_skill("sword", 300);
	set_skill("quanzhen-jian",300);
	set_skill("dodge", 300);
	set_skill("jinyan-gong", 300);
	set_skill("parry", 300);
	set_skill("strike",300);
	set_skill("unarmed",300);
	set_skill("haotian-zhang", 300);
	set_skill("literate",300);
	set_skill("taoism",300);
	set_skill("whip",300);
	set_skill("duanyun-bian",300);
	set_skill("cuff",300);
	set_skill("chunyang-quan",300);
	map_skill("cuff","chunyang-quan");
	map_skill("whip","duanyun-bian");
	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("strike", "haotian-zhang");
	prepare_skill("strike", "haotian-zhang");
	prepare_skill("cuff","chunyang-quan");
	create_family("全真教", 2, "弟子");

	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"南帝" : (: ask_me :),
		"段皇爷" : (: ask_me :),
	]) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("xiantian-qigong",1) < 100 ) {
		command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen") < 5000 ) {
		command("say 行侠仗义是我辈学武人的基本品质，你若能多做些狭义之事，我一定收你为徒。\n");
		return;
	}
	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

int accept_object(object who, object ob)
{
	if( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if (  (string)ob->query("name") != HIR"熊胆"NOR
		&& ob->query("name") != HIY"田七"NOR
		&& ob->query("name") != HIW"没药"NOR
		&& ob->query("name") != RED"血竭"NOR )
			return 0;

	if(who->query("learn_from_wang")){
		message_vision("王处一看了看$N送去的药，点头谢道：真是多谢你了。\n", who);
		return 1;
	}

	message_vision("王处一看了看$N送去的药，点了点头道：难为你了，我可以教你点功夫。\n", who);
	who->add_temp("tmark/王", 60);
	return 1;

}
string ask_me()
{
	object me=this_player();

	if(me->query_temp("tmark/指")==1) {
		me->add_temp("tmark/指",1);
		return("去年师傅去过段皇爷那里，据说段皇爷把他最厉害的一阳指功夫传授给我师傅了。\n");
	}
	else {
		me->set_temp("tmark/指",0);
		return("段皇爷遇上了一件大伤心事，现在出家做了和尚了，唉！");
	}
}

int recognize_apprentice(object ob)
{
	mapping fam;
	if(!(fam = this_player()->query("family")))
		return notify_fail("王处一道：你可还没拜过师啊，要学功夫还是先拜个师父再说吧。\n");
	if(!(int)ob->query_temp("tmark/王")) return 0;
	if(ob->query("learn_from_wang",1)) return 0;

	if ( fam["family_name"] == "全真教"
		&& fam["master_name"] == "王处一"
		&& fam["master_id"] == "wang chuyi") return 1 ;

	if((int)ob->query_temp("tmark/王") == 1){
		message_vision("王处一看看$N，说道：我能教你的东西到此为止，你也不要再找我学功夫了。\n", ob);
		ob->set("learn_from_wang",1);
	}

	ob->add_temp("tmark/王", -1);
	return 1;
}
