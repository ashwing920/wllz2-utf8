// TuoBa.c

#include <ansi.h>
inherit F_MASTER;
inherit NPC;

void create()
{
	set_name("拓跋", ({ "tuoba", }));
	set("long",@LONG
他是一位带发修行的头陀，身穿一件白布长袍。他个子不高，但很结实，
看上去颇为纯朴。可是脸上经常浮现出奇怪的笑容，让人有些摸不着头脑。
LONG
);
	set("title",HIG"明教"NOR"风字门门主");
	set("level",5);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 22);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_jing",300);
	set("neili",1200);
	set("max_neili",1200);
	set("jiali",60);
	set("combat_exp", 50000);
	set("score",100);

	set_skill("force", 80);
	set_skill("hunyuan-yiqi", 80);
	set_skill("dodge", 80);
	set_skill("shaolin-shenfa", 80);
	set_skill("finger",80);
	set_skill("nianhua-zhi", 80);
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
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object();
	ob = this_player();

	if( interactive(ob) && !is_fighting() ){
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

#include "menzhu.h"
