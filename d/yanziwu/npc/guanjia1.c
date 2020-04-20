// /u/beyond/mr/npc/guanjia1.c 管家
// this is made by beyond
// update 1997.6.23
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("管家", ({ "guan jia", "liu" }));
	set("gender", "男性");
	set("age", 40);      
	set("str", 20);
	set("int", 26);
	set("con", 26);
	set("dex", 26);
	set("combat_exp", 50000);
	set("shen_type", 0);
	set("attitude", "peaceful");
	set("max_qi",800);
	set("max_jing",800);
	set("neili",800);
	set("max_neili",800);
	set("jiali",0);
	set("score", 7000);

	set_skill("cuff", 80);
	set_skill("parry",80);
	set_skill("dodge", 80);
	set_skill("force",80);

	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	setup();
	carry_object(__DIR__"obj/cloth2")->wear();
}
