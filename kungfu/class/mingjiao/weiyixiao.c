// WeiYiXiao.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("韦一笑", ({"wei yixiao", "wei", "yixiao",}));
	set("long",@LONG
他长得活象是一只青翼大蝙蝠。他的脸色灰扑扑的。
LONG
);

	set("title",HIR"明教护法"NOR);
	set("nickname",HIC"青翼蝠王"NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class","fighter");

	set("age", 48);
	set("shen_type", 1);
	set("per", 19);
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
	set("score", 10000);

	set_skill("unarmed",400);
	set_skill("force", 400);
	set_skill("dodge", 400);
	set_skill("strike", 400);
	set_skill("parry", 400);
	set_skill("shenghuo-shengong", 400);
	set_skill("qingfu-shenfa", 400);
	set_skill("hanbing-mianzhang",400);
	set_skill("literate", 400);

	map_skill("unarmed","hanbing-mianzhang");
	map_skill("force", "shenghuo-shengong");
	map_skill("dodge", "qingfu-shenfa");
	map_skill("strike","hanbing-mianzhang");
	map_skill("parry", "hanbing-mianzhang");
	prepare_skill("strike","hanbing-mianzhang");

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: command("perform xixueqingfu") :),
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
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

#include "fawang.h"