// ZhouDian.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("周颠", ({ "zhou dian", "zhou", "dian", }));
	set("long",@LONG
他是一位疯疯颠颠的老者，身穿一件白布长袍。他总是慌慌张张的，先天
下之急而急。
LONG
);
	set("title", HIG "明教" NOR "五散人");
	set("nickname", "没事不颠有事颠");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "scholar");

	set("age", 46);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_jing", 1000);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali",75);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 100);
	set_skill("hunyuan-yiqi", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("cuff", 100);
	set_skill("jingang-quan", 100);
	set_skill("parry", 100);
	set_skill("buddhism", 100);
	set_skill("literate", 100);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("parry", "jingang-quan");

	prepare_skill("cuff", "jingang-quan");
	create_family("明教", 3, "五散人");

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	if (interactive(this_player()) && this_player()->query_temp("fighting")){
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}	   
}
