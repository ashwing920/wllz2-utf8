// mao18.c 茅十八

#include <ansi.h>
inherit NPC;
int ask_weiwang();

void create()
{
	set_name("茅十八", ({ "mao shiba", "mao", "shiba" }));
	set("gender", "男性");
	set("age", 30);
	set("str", 25);
	set("dex", 16);
	set("long",@LONG
他虬髯如乱草，满脸血污，好象曾受过很重的伤，可以看得见
他左腿上血迹未干。但他双目炯炯，却又有着说不出的威风。
LONG
);
	set("combat_exp", 35000);
	set("shen_type", 1);
	set("score", 4000);
	set("attitude", "peaceful");
	set("startroom","/d/city/lichunyuan");

	set_skill("unarmed", 50);
	set_skill("force", 60);
	set_skill("blade", 80);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set_skill("wuhu-duanmendao", 70);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 10);

	map_skill("blade", "wuhu-duanmendao");

	set("neili", 200);
	set("max_neili", 200);
	set("jiali", 20);
	set("inquiry", ([
		"史松" : "杀了史松可以提高江湖威望。\n",
		"鳌拜" : "杀鳌拜救人可以提高江湖威望。\n",
		"威望" : (: ask_weiwang :),
		"江湖威望" : (: ask_weiwang :),
	]));
	set("chat_chance", 20);
	set("chat_msg", ({
		(: command("say 他奶奶的，我就不信鳌拜有这等厉害，我正要上北京去斗他一斗。"):),
		(: command("say 用我这五虎断门刀法对付盐枭可是绰绰有余，只不知对付鳌拜行不行。"):),
		(: command("say 江湖威望很重要！威望高大有好处啊..."):),
		(: command("say 他奶奶的，谁帮我杀了史松，兄弟我谢谢你了！"):),
		(: command("say 老听说那鳌拜是满洲第一武士，他妈的，还有人说他是天下第一勇士，我可不服气。"):),
		(: command("say 江湖有言：“为人不识陈近南，就称英雄也枉然。”"):),
		(: random_move :)
	}) );
	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say("\n茅十八说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
	+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息......\n");
	say("\n茅十八又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
	return 1;
}

void init()
{
	object ob;
	if(interactive(ob = this_player()) && !is_fighting()){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	message_vision("\n$N拱手道：兄弟腿上不方便，不能起立行礼了。\n",this_object());
}

void die()
{
	say("\n茅十八哈哈大笑道：托韦兄弟的福，我见过了陈近南总舵主，虽死无憾啊！\n");
	message_vision("$N大笑两声，死了！\n", this_object());
	::die();
}

int accept_object(object me, object ob)
{
	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if ( (string)ob->query("id") == "heilong bian")
	{
	i=(int)me->query("weiwang");
	if(i<20)
	{
	i=i+10;
	me->set("weiwang",i);
	message_vision(HIC "\n$N的江湖威望提高了！\n" NOR,this_player());
	}
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(i));
	}
	else
	{
		 command("shake ");
		 command("say 这种东西鬼才要 ! 老子宰了你 !");
		 remove_call_out("kill_ob");
		 call_out("kill_ob", 1, this_player());
	}
	 return 1;
}
