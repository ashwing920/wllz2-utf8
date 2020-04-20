// wang.c 王重阳
// By Lgg,1998.10

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_jiuyin();
string ask_zhipu();
string ask_duan();

void create()
{
	set_name("王重阳", ({"wang chongyang", "wang"}));
	set("gender", "男性");
	set("age", 66);
	set("class", "taoist");
	set("nickname",HIW"活死人"NOR);
	set("long",@LONG
他就是全真教的开山祖师、首代掌教王重阳王真人。他白须飘飘，宽袍缓
袖，眉目清癯，颇有些仙风道骨的味道。他本来一腔热血欲报效国家力抗
金兵，可惜朝廷腐败，于是心灰意冷，又从道德经中悟得了天地滋生的大
道，手创全真教。
LONG
);
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "recover" :),
		(: perform_action, "sword.ju" :),
		(: perform_action, "sword.ju" :),
		(: perform_action, "sword.ju" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.ding" :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield changjian") :),
		(: command("wield chacngjian") :),
		(: command("wield changjian") :),
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "finger.qiankun" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
		(: perform_action, "strike.ju" :),
	}));

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);

	set("combat_exp",51200000);

	set_skill("force", 800);
	set_skill("xiantian-qigong", 800);
	set_skill("sword", 800);
	set_skill("quanzhen-jian",800);
	set_skill("dodge", 800);
	set_skill("jinyan-gong", 800);
	set_skill("parry", 800);
	set_skill("unarmed",800);
	set_skill("haotian-zhang", 800);
	set_skill("literate",800);
	set_skill("strike",800);
	set_skill("taoism",800);
	set_skill("finger",800);
	set_skill("sun-finger",800);
	set_skill("whip",800);
	set_skill("duanyun-bian",800);
	set_skill("cuff",800);
	set_skill("chunyang-quan",800);
	map_skill("cuff","chunyang-quan");
	map_skill("whip","duanyun-bian");
	map_skill("force", "xiantian-qigong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("strike", "haotian-zhang");
	map_skill("finger","sun-finger");
	prepare_skill("finger","sun-finger");
	prepare_skill("strike","haotian-zhang");
	prepare_skill("cuff","chunyang-quan");
	create_family("全真教", 1, "掌教");

	set("book_count",1);
	set("inquiry", ([
		"全真教" :  "我全真教是天下道家玄门正宗。\n",
		"九阴真经" : (: ask_jiuyin :),
		"一阳指" : (: ask_zhipu :),
		"段皇爷" : (: ask_duan :),
	]) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();

}

void attempt_apprentice(object ob)
{
	if (ob->query_int() < 30) {
		command("say 你的资质不够，还是先找我那几个徒弟学习吧。");
		return;
	}
	if ((int)ob->query_skill("xiantian-qigong",1) < 300 ) {
		command("say 你的本门内功心法火候不足,难以领略更高深的武功。");
		return;
	}
	if ((int)ob->query("shen") < 10000) {
		command("say 行侠仗义是我辈学武人的基本品质，你若能多做些狭义之事，我一定收你为徒。\n");
		return;
	}
	command("say 好吧，依你资质，定可传我衣钵，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
}

string ask_jiuyin()
{
	mapping fam;
	object me;
	int lvl_force;
	me = this_player();

	if(!mapp(fam = me->query("family"))
		|| fam["family_name"] != "全真教")
			return RANK_D->query_respect(me) +"与本教毫无瓜葛，这话从何说起？";
	
	if(!(lvl_force = (int)me->query_skill("force",1))
	|| lvl_force < 50)
		return RANK_D->query_respect(me) +"的基本内功火候如此之浅，强练真经上的上乘武功有害无益。";

	return "九阴真经是天下武学正宗，我已交给我师弟周伯通保管，不过....在古墓派的石棺内，我还刻着一些图形。";
}

string ask_duan()
{
	object me=this_player();
	if(me->query_temp("tmark/指")==4) {
		me->add_temp("tmark/指",1);
		return("段皇爷号称‘南帝’，家传的一阳指是天下最厉害的指法。\n");
	}
	else {
		me->set_temp("tmark/指",0);
		return("你问段皇爷做甚么，莫非想与他为难？\n");
	}
}

string ask_zhipu()
{
	object ob,me=this_player();
	if(me->query_temp("tmark/指")==5) {
		me->set_temp("tmark/指",0);
		if(query("book_count")>0) {
			ob=new("/clone/book/zhifapu");
			ob->move(me);
			add("book_count",-1);
			message("channel:rumor",HIM"【武林传奇】某人："+me->name()+"拿到指法谱啦！\n"NOR,users());
			return "好吧，你历经艰苦，意志甚坚，这本指法谱就交给你了。";
		}
		else
			return "你来晚了，指法谱已经被人取走了。";
	}
	else {
		me->set_temp("tmark/指",0);
		return  RANK_D->query_respect(me) +"不是想跟我较量较量吧？\n";
	}
}
