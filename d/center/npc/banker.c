// banker.c - 钱庄老板
// Design By Robert 蝴蝶君 emial:robert_st@263.net

#include <ansi.h>

inherit NPC;
inherit F_BANKER;

string ask_me(object who);

void create()
{
	set_name("陈鸿腾", ({ "chen hongteng","chen","hongteng" }));
	set("title","钱庄老板");
	set("long", @LONG
他是钱庄老板，一双贼兮兮的眼睛正笑眯眯的看着你。
一看就知道是个十分精明的老家伙。
LONG
	);

	set("rank_info/respect", "老板");
	set("attitude", "friendly");
	set("gender", "男性" );
	set("age", 36);
	set("str", 30);                         // 膂力         
	set("cps", 30);                         // 定力
	set("cor", 30);                         // 胆识         
	set("per", 30);                         // 容貌
	set("con", 30);                         // 根骨

	set("combat_exp",random(30000)+10000);
	set("shen_type",1);
	set("env/wimpy", 30);        

	setup();
	
	carry_object("/clone/cloth/cloth")->wear();       // 装备

	add_money("gold",1);                           // 金钱
}

void init()
{
	add_action("do_check", "check");
	add_action("do_check", "chazhang");
	add_action("do_convert", "convert");
	add_action("do_convert", "duihuan");
	add_action("do_deposit", "deposit");
	add_action("do_deposit", "cun");
	add_action("do_withdraw", "withdraw");
	add_action("do_withdraw", "qu");
}
