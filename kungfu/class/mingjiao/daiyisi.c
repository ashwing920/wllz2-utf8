// daiyisi.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黛绮丝", ({ "dai yisi", "dai", "master" }) );
	set("long", @LONG
她是紫衫龙王黛绮丝。
LONG
);

	set("title",HIR"明教护法"NOR);
	set("nickname",HIM"紫衫龙王"NOR);
	set("level",9);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("class","fighter");

	set("age", 36);
	set("per", 25);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",4000);
	set("max_jing",4000);
	set("neili", 6000);
	set("max_neili",6000);
	set("jiali",300);

	set("combat_exp",6400000);
	set("shen_type",1);
	set("score", 80000);

	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("parry", 400);
	set_skill("unarmed", 400);
	set_skill("staff",400);
	set_skill("jinhua-staff",400);
	set_skill("shenghuo-shengong",400);
	set_skill("lingxu-bu",400);
	set_skill("bosi-guaizhao",400);
	set_skill("literate",400);
	set_skill("throwing",400);
	set_skill("duoming-jinhua",400);
	set_skill("jinwu-daofa",400);
	set_skill("blade",400);

	map_skill("blade","jinwu-daofa");
	map_skill("force", "shenghuo-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("unarmed","bosi-guaizhao");
	map_skill("parry", "bosi-guaizhao");
	map_skill("staff", "jinhua-staff");
	map_skill("throwing","duoming-jinhua");

	create_family("明教",34,"法王");

	setup();

	carry_object("/clone/weapon/xlongquan")->wield();
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
