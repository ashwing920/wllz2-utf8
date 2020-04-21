// lilishi.c 李力世

#include <ansi.h>

inherit NPC;

inherit F_MASTER;
int ask_weiwang();
int ask_zhu();

void create()
{
	set_name("李力世", ({ "li lishi", "li" }));
	set("title", HIR "天地会"HIG"青木堂"NOR"会众");
	set("gender", "男性");
	set("age", 45);
	set("str", 25);
	set("dex", 20);
	set("long",@LONG
这是一个身材矮小，满连胡须的中年人，身上的衣服又脏又破，脸上满是
皱纹，看上去饱经风霜。
LONG
);
	set("combat_exp", 35000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set_skill("unarmed", 50);
	set_skill("force", 60);
	set_skill("blade", 90);
	set_skill("dodge", 70);
	set_skill("parry", 50);
	set_skill("wuhu-duanmendao", 90);
	set_skill("yunlong-shenfa", 60);
	map_skill("blade", "wuhu-duanmendao");
	map_skill("dodge", "yunlong-shenfa");

	set("neili", 150); 
	set("max_neili", 150);
	set("jiali", 10);
	set("chat_chance", 2);
	set("chat_msg", ({
		"李力世说：呆会儿我还得把猪送到宫里去。\n",
		"李力世突然吆喝道: 花雕芙苓猪啊，只卖黄金一两，谁买谁买啊？\n",
		"李力世突然吆喝道: 燕窝人参猪啊，只卖黄金一两，谁买谁买啊？\n",
		"李力世搔了搔头，说道：这么好的猪肉怎么没人要啊。\n",
		"李力世突然说：初进洪门结义兄，对天明誓表真心。\n",
	}));
	set("inquiry", ([
		"陈近南" :  "\n想见总舵主可不容易啊。\n",
		"天地会" :  "\n只要是英雄好汉，都可以入我天地会。\n",
		"入会" :  "\n只要入了我天地会，可以向会中各位好手学武艺。\n",
		"反清复明" : "去棺材店和回春堂仔细瞧瞧吧！\n",
		"暗号" : "敲三下！\n",
		"切口" : "敲三下！\n",
		"进宫" : (: ask_zhu :),
		"花雕芙苓猪" : (: ask_zhu :),
		"燕窝人参猪" : (: ask_zhu :),
		"威望" :  (: ask_weiwang :),
		"江湖威望" : (: ask_weiwang :),
	]) );
	setup();
	carry_object("/d/city2/obj/tudao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("silver", 20);
}

int accept_object(object who, object ob)
{
	if (ob->query("money_id") && ob->value() >= 10000) 
	{
		message_vision("\n李力世对$N一揖作礼，说道：这位客官，要什么尽管说。\n",this_player());
		who->set_temp("money_paid",1);
		return 1;
	}
	return 0;
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say("\n李力世说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
	+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
	say("李力世说：杀某些坏人或救某些好人可以提高江湖威望。\n");
	return 1;
}


int ask_zhu()
{
	if (this_player()->query_temp("money_paid")){
		this_player()->delete_temp("money_paid");
		this_player()->set("huanggong/canenter",1);
		say("李力世说：您老现在可以走啦！\n");
		return 1;
	}
	say("李力世说：干什么也得先交钱啊。\n");
	return 1;
} 