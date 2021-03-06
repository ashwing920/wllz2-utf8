// daochang-dizi.c - 道场弟子

#include <ansi.h>
#include "daochang_dizi.h";

inherit NPC;

void create()
{
	set("title","百人道场第七十七层弟子");
	set_name(npc_name("男性"), ({"daochang dizi", "dizi" }));
	set("nickname",RED"阴"NOR);
	set("long","这位是"+ query("title")+"。\n");
	set("gender","男性");
	set("age",20);
	set("attitude", "heroism");
	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
		(: perform_action, "staff.feng":),
		(: perform_action, "staff.xue":),
		(: exert_function, "regenerate":),
		(: exert_function, "recover" :),
	}));
	add_temp("apply/damage",350);
	add_temp("apply/armor",350);
	add_temp("apply/dodge",350);
	add_temp("apply/attack",350);
	add_temp("apply/unarmed_damage",350);

	set("combat_exp",8700000);
	create_family("星宿派",21,"弟子");
	setup();
	NPC_D->full_init(this_object());
	carry_object(__DIR__"obj/cloth")->wear();
}
