// daochang-dizi.c - 道场弟子

#include <ansi.h>
#include "daochang_dizi.h";

inherit NPC;

void create()
{
	set("title","百人道场第八十二层弟子");
	set_name(npc_name("男性"), ({"daochang dizi", "dizi" }));
	set("long","这位是"+ query("title")+"。\n");
	set("gender","男性");
	set("age",20);
	set("attitude", "heroism");
	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
		(: perform_action, "blade.wenrou":),
		(: perform_action, "blade.riyue":),
		(: perform_action, "blade.suifeng":),
		(: exert_function, "regenerate":),
		(: exert_function, "recover" :),
	}));
	add_temp("apply/damage",500);
	add_temp("apply/armor",500);
	add_temp("apply/dodge",500);
	add_temp("apply/attack",500);
	add_temp("apply/unarmed_damage",500);

	set("combat_exp",9200000);
	create_family("逍遥派",21,"弟子");
	setup();
	NPC_D->full_init(this_object());
	carry_object(__DIR__"obj/cloth")->wear();
}
