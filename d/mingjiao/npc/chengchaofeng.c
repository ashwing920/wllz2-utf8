// ChengChaoFeng.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("程嘲风", ({ "cheng chaofeng", "cheng", "chaofeng", }));
	set("long",@LONG
他是一位身宽体胖的老者，身穿一件白布长袍。他正笑嘻嘻地看着你，好
象对你颇有好感。
LONG
);

	set("title",HIG"明教"HIC"青龙坛"NOR"坛主");
	set("level",5);

	set("gender", "男性");
	set("attitude", "friendly");
	set("age", 51);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_jing", 300);
	set("neili",1200);
	set("max_neili",1200);
	set("jiali",60);
	set("combat_exp",60000);
	set("score", 100);

	set_skill("force", 80);
	set_skill("hunyuan-yiqi", 80);
	set_skill("dodge", 80);
	set_skill("shaolin-shenfa", 80);
	set_skill("finger",80);
	set_skill("nianhua-zhi",80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("damo-jian", 80);
	set_skill("buddhism", 80);
	set_skill("literate", 80);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("finger", "nianhua-zhi");

	set("inquiry", ([
		"明教" :	(: ask_me :),
	]));
	create_family("明教", 4, "青龙坛坛主");
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object();
	ob = this_player();

	add_action("do_join","join");
	
	if( interactive(ob) && !is_fighting() ){
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

string ask_me()
{
	return "你想加入我明教(join mingjiao)吗？";
}

#include "tanzhu.h"
