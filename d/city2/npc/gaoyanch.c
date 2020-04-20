// gaoyanchao.c 高彦超

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

int ask_weiwang();

void create()
{
	set_name("高彦超", ({ "gao yanchao", "gao", "yanchao" }));
	set("title",HIR"天地会"HIG"青木堂"NOR"会众");
	set("gender","男性");
	set("age", 32);
	set("str", 25);
	set("dex", 20);
	set("long",@LONG
他不过三十出头，却显得异常老练。一言不发地往那儿一站，真是威风凛
凛。
LONG
);
	set("combat_exp", 40000);
	set("score", 5000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("club", 80);
	set_skill("parry", 70);
	set_skill("literate", 50);
	set_skill("hunyuan-yiqi", 60);
	set_skill("shaolin-shenfa", 60);
	set_skill("zui-gun", 70);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("club", "zui-gun");
	map_skill("parry", "zui-gun");

	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/armor", 5);
	set_temp("apply/damage", 25);
	set("qi", 400);
	set("max_qi", 400);
	set("jing", 300);
	set("max_jing", 300);
	set("neili", 250); 
	set("max_neili", 250);
	set("jiali", 35);
	set("inquiry", ([
		"陈近南" :"想见总舵主可不容易啊。\n",
		"天地会" :"只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
		"入会" :  "只要入了我天地会，可以向会中各位好手学武艺。\n",
		"反清复明" :"去棺材店内室仔细瞧瞧吧！\n",
		"暗号" : "敲三下！\n",
		"切口" : "敲三下！\n",
		"威望" :  (: ask_weiwang :),
		"江湖威望": (: ask_weiwang :),
	]) );
	setup();
	carry_object("/d/shaolin/obj/qimeigun")->wield();
	carry_object("/clone/cloth/cloth")->wear();
	add_money("gold", 1);
}

int ask_weiwang()
{
	command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
	say("\n高彦超说道：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
	+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
	say("高彦超又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
	return 1;
}

