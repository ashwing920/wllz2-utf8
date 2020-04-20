// song.c 宋远桥

inherit NPC;
inherit F_MASTER;

#include <ansi.h>

string ask_me();
string ask_yu();

void create()
{
	set_name("宋远桥", ({ "song yuanqiao", "song" }));
	set("nickname", "武当首侠");
	set("long",@LONG
他就是张三丰的大弟子、武当七侠之首的宋远桥。身穿一件干干净净的灰
色道袍。他已年过六十，身材瘦长，满脸红光。恬淡冲和，沉默寡言。
LONG
);
	set("gender", "男性");
	set("age", 61);
	set("attitude", "peaceful");
	set("class", "taoist");
	set("shen_type", 1);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("jing",4000);
	set("max_jing",4000);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jiali",300);
	set("combat_exp", 6400000);
	set("score", 60000);

	set_skill("force", 400);
	set_skill("taiji-shengong", 400);
	set_skill("dodge", 400);
	set_skill("tiyunzong", 400);
	set_skill("unarmed", 400);
	set_skill("taiji-quan", 400);
	set_skill("parry", 400);
	set_skill("sword", 400);
	set_skill("taiji-jian", 400);
	set_skill("wudang-jian", 400);
	set_skill("taoism", 400);
	set_skill("literate", 400);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 2, "弟子");

	set("inquiry", ([
		"秘籍" : (: ask_me :),
		"俞岱岩": (: ask_yu() :),
	]));

	set("book_count", 1);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query("guarded") < 3) {
		command("say " + RANK_D->query_respect(ob) +"你对我武当派尽了多少心力，有几分忠心呢？");
		return;
	}
	if ((int)ob->query_skill("taiji-shengong",1)< 100) {
		command("say 我武当派乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) +
			"是否还应该在太极神功上多下点功夫？");
		return;
	}
	if ((int)ob->query("shen") < 1000){
		command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
		return;
	}
	command("say 好吧，贫道就收下你了。");
	command("recruit " + ob->query("id"));
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "武当派")
		return RANK_D->query_respect(this_player()) + "与本派素无来往，不知此话从何谈起？";
	if (query("book_count") < 1)
		return "你来晚了，本派的内功心法不在此处。";
	add("book_count", -1);
	ob = new("/clone/book/force_book");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"拿到太极十三式啦。\n");
	return "好吧，这本「太极十三式」你拿回去好好钻研。";
}
string ask_yu()
{
	object me;
	me = this_player();
	
	if(me->query("marks/都大锦"))
		return "多谢这位"+ RANK_D->query_respect(me)+"仗义相助，三师弟他现在已经在养伤了。";
	
	if(!me->query_temp("ask_dudajin"))
		return "三师弟自从上次前往赛刀大会，至今仍旧下落不明，我们四处打探，仍旧没有他的消息。";

	me->set_temp("ask_songyuanqiao",1);	
	return "莫非这位"+ RANK_D->query_respect(me)+"有我三师弟的消息？";
}
int accept_object(object who, object ob)
{
	
	if((string)ob->query("name") == "俞岱岩"
	&& who->query_temp("ask_dudajin")
	&& who->query_temp("ask_songyuanqiao")
	&& (int)who->query_temp("pk_qiangdao") > 1) {
		say(name()+"脸色一惊，叫道：三师弟，三师弟，是谁害得你这样子的？\n");
		say("你从容的说道：在下路经武当，在武当山下发现了俞大侠，在下看到他时，他已经奄奄一息，残喘气息了。\n");
		say(name()+"连忙谢道：真是有劳这位"+ RANK_D->query_respect(who)+"，来人啊，把三师弟扶进去休息。\n");
		say("几个武当弟子一拥而上，赶紧把俞岱岩扶进了休息室。\n");
		if(!who->query("marks/都大锦")){
			tell_object(who,"由于成功的将俞岱岩送到了武当派，替都大锦解决了心头之患。\n");
			tell_object(who,"你的潜能增加了 2000 点，江湖威望也有所提高了。\n");
			who->add("learned_points",-2000);
			who->add("weiwang",100);
			who->set("marks/都大锦",1);
			who->delete_temp("ask_songyuanqiao");
			who->delete_temp("ask_dudajin");
			who->delete_temp("pk_qiangdao");
			CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s(%s)成功的将俞岱岩送到了武当派，得到了一些奖励。",who->name(),who->query("id")));
		}
		return 1;
	}
	return 0;
}
