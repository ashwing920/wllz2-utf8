// FanYao.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("范遥", ({"fan yao","fan","yao",}));
	set("long",@LONG
他是一位带发修行的头陀，身穿白布长袍。他的脸上七七八八的全是伤疤
，简直看不出本来面目了。
LONG
);

	set("title",HIG"明教"HIR"光明右使"NOR);
	set("level",11);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("class","fighter");

	set("age", 38);
	set("shen_type", -1);
	set("per", 12);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("jing",3000);
	set("max_jing",3000);
	set("neili", 4500);
	set("max_neili",4500);
	set("jiali",225);
	set("combat_exp", 2700000);
	set("score", 800000);

	set_skill("force", 300);
	set_skill("jiuyang-shengong", 300);
	set_skill("dodge", 300);
	set_skill("lingxu-bu", 300);
	set_skill("finger", 300);
	set_skill("strike", 300);
	set_skill("hand", 300);
	set_skill("claw", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
	set_skill("jinwu-daofa", 300);
	set_skill("nianhua-zhi", 300);
	set_skill("sanhua-zhang", 300);
	set_skill("fengyun-shou", 300);
	set_skill("longzhua-gong", 300);
	set_skill("buddhism", 300);
	set_skill("literate", 300);
	set_skill("hunyuan-yiqi",300);
	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("blade", "jinwu-daofa");
	map_skill("parry", "nianhua-zhi");

	set("inquiry", ([
		"光明圣火阵"  : (: ask_me :),
		"明教圣火阵"  : (: ask_me :),
		"圣火阵"          : (: ask_me :)
	]));

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: prepare_skill("finger", "nianhua-zhi") :),
		(: prepare_skill("strike", "sanhua-zhang") :),
	}) );
	create_family("明教",34, "光明右使");

	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

void init()
{
	object me,ob;
	me = this_object () ;
	ob = this_player () ;

	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me, ob);
	}
}

void attempt_apprentice(object ob)
{
	command("say 我不收徒的，你找各位法王去。");
	return 0;
}

#include "fanyao.h"
