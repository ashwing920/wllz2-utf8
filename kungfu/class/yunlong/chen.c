// chen.c 陈近南

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
int ask_weiwang();

void create()
{
	set_name("陈近南", ({ "chen jinnan", "chen","jinnan" }));
	set("title", HIR "天地会"HIM"总舵主"NOR );
	set("nickname", HIC "英雄无敌" NOR);
	set("long", @LONG
这是一个文士打扮的中年书生，神色和蔼。他就是天下闻名的天地会总舵
主陈近南，据说十八般武艺，样样精通。偶尔向这边看过来，顿觉他目光
如电，英气逼人。
LONG
);
	set("gender", "男性");
	set("class", "scholar");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",10000);
	set("max_jing",10000);
	set("neili",12000);
	set("max_neili",12000);
	set("jiali",600);
	set("combat_exp",51200000);

	set_skill("literate", 800);
	set_skill("force", 800);
	set_skill("dodge", 800);
	set_skill("unarmed", 800);
	set_skill("parry", 800);
	set_skill("whip", 800);
	set_skill("blade", 800);
	set_skill("sword", 800);
	set_skill("hand", 800);
	set_skill("claw", 800);
	set_skill("houquan", 800);
	set_skill("yunlong-xinfa", 800);
	set_skill("yunlong-shengong", 800);
	set_skill("wuhu-duanmendao", 800);
	set_skill("yunlong-jian", 800);
	set_skill("yunlong-shenfa", 800);
	set_skill("yunlong-bian", 800);
	set_skill("yunlong-shou", 800);
	set_skill("yunlong-zhua", 800);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");
	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");

	create_family("云龙门",1, "开山祖师");
	set("book_count", 1);
	set("inquiry", ([
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"入会" :  "\n只要入我天地会，可以向各位好手学武艺。\n",
		"反清复明" : "去棺材店和回春堂仔细瞧瞧吧！\n",
		"暗号" : "敲三下！\n",
		"切口" : "敲三下！\n",
		"威望" :  (: ask_weiwang :),
		"江湖威望" : (: ask_weiwang :),
		"云龙剑谱" : (: ask_me :),
	]) );

	set("env/wimpy", 60);
	set("chat_chance_combat", 70);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
		(: command("unwield changjian") :),
		(: command("wield changjian") :),
		(: command("wield bian") :),
		(: perform_action, "sword.xian" :),
		(: perform_action, "whip.chan" :),
		(: perform_action, "blade.duan" :),
		(: command("unwield bian") :),
		(: command("wield blade") :),
		(: command("unwield blade") :),
	}) );
	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city2/obj/hlbian");
	carry_object("/clone/weapon/gangdao");
}

string ask_me()
{
	mapping fam;
	object ob,me;
	me = this_player();
	

	if(!mapp(fam = me->query("family"))
		|| fam["family_name"] != "云龙门")
		return RANK_D->query_respect(me) + "与本派素无来往，不知此话从何谈起？";

	if (query("book_count") < 1)
		return "你来晚了，本派的云龙真经不在此处。";

	add("book_count", -1);
	ob = new("/clone/book/yljianpu");
	ob->move(me,1);

	CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",sprintf("听说%s得到了%s！",
		me->name(),ob->name()));

	return "好吧，这本「云龙剑谱」你拿回去好好钻研。";
}
void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("yunlong-shengong", 1) < 300){
		command("say 我云龙神功乃内家武功，最重视内功心法。");
		command("say " + RANK_D->query_respect(ob) + "是否还应该在云龙神功上多下点功夫？");
		return;
	}

	if ((int)ob->query("shen") > 10000 && (int)ob->query("shen") < 200000) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +"是否还做得不够？");
		return ;
	}
	if(ob->query("weiwang")<80){
		if((int)ob->query("shen")<0)
		command("say "+ RANK_D->query_respect(ob) +"虽然是邪派中人，但也还做了些好事。\n");
		command("say 我天地会所作所为，无一不是前人所未行之事。\n");
		command("say 万事开创在我，骇人听闻，物议沸然，又何足论？\n");
		command("say 今天就收了你吧！！\n");
		command("chat 想不到我一身惊人艺业，今日终于有了传人，哈哈哈哈！！！！\n");
		message_vision(HIC "$N的江湖威望提高了！\n" NOR,this_player());
		ob->set("weiwang",80);
	}
	command("recruit " + ob->query("id"));
	if((!(string)ob->query("class")) || ((string)ob->query("class") != "fighter"))
		ob->set("class","fighter");
}
int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say("\n陈近南说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
	+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
	say("陈近南又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
	return 1;
}
