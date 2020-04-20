// YinTianZheng.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("殷天正", ({"yin tianzheng", "yin", "tianzheng", }));
	set("long",@LONG
他是一位身材魁梧的秃老者，身穿一件白色长袍。他长眉胜雪，垂下眼角
，鼻子钩曲，犹如鹰嘴。
LONG
);

	set("title",HIR"明教护法"NOR);
	set("nickname",HIW"白眉鹰王"NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class","fighter");

	set("age", 72);
	set("shen_type", 1);
	set("per", 22);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",4000);
	set("max_jing",4000);
	set("neili",6000);
	set("max_neili",6000);
	set("jiali",300);
	set("combat_exp",6400000);
	set("score", 100000);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("unarmed", 400);
	set_skill("parry", 400);
	set_skill("claw", 400);
	set_skill("literate", 400);
	set_skill("shenghuo-shengong", 400);
	set_skill("xiaoyaoyou", 400);
	set_skill("sougu", 400);
	set_skill("longzhua-gong", 400);

	map_skill("force","shenghuo-shengong");
	map_skill("dodge","xiaoyaoyou");
	map_skill("claw","sougu");
	map_skill("parry","longzhua-gong");
	map_skill("unarmed","sougu");
	prepare_skill("claw", "sougu");

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: command("perform muyeyingyang") :),
	}) );
	create_family("明教",34, "法王");
	setup();
	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object();
	ob = this_player();

	if (interactive(this_player()) && this_player()->query_temp("fighting")){
		COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon") );
		this_player()->add_temp("beat_count", 1);
	}
	if( interactive(ob) && !is_fighting() ){
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

#include "fawang.h"
