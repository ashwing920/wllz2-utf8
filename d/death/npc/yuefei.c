// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("常胜将军", ({ "master yue", "master" }) );
	set("nickname", HIY"金盔"HIW"银甲"NOR);
	set("gender", "男性" );
	set("age", 44);
	set("str", 50);
	set("cor", 30);
	set("cps", 30);
	set("int", 30);
	set("per", 30);
	set("attitude","friendly");
	set("max_neili", 15000);
	set("neili", 15000);
	set("jiali", 20);
	set("long",@LONG
你看着看着，觉得这位将军就象是当年统兵十万，直捣黄龙，壮志未酬的岳飞！
LONG);
	set("combat_exp", 1000000);
	set("agi",25);
	set("int",30);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("literate", 60);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	setup();
	carry_object(__DIR__"obj/goldarmor")->wear();
	carry_object(__DIR__"obj/silverarmor")->wear();
}


int is_ghost() { return 1; }

int recognize_apprentice(object ob)
{
	if( ob->query("betrayer"))
	{
		say("将军喝道：我最恨的就是你这种不忠之人！\n");
		kill_ob(ob);
		ob->kill_ob(this_object());
		return 0;
	}
	return 0;
}

