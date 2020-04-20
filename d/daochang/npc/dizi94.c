// daochang-dizi.c - 道场弟子

#include <ansi.h>
#include "daochang_dizi.h";

inherit NPC;

void create()
{
	set("title","百人道场第九十四层弟子");
	set_name(npc_name("男性"), ({"daochang dizi", "dizi" }));
	set("long","这位是"+ query("title")+"。\n");
	set("nickname",WHT"冥"NOR);
	set("gender","男性");
	set("age",20);
	set("attitude", "heroism");
	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jianqi":),
		(: perform_action, "sword.feiwu":),
		(: exert_function, "regenerate":),
		(: exert_function, "recover" :),
	}));
	set_temp("apply/astral_vision",1);
	add_temp("apply/damage",600);
	add_temp("apply/armor",600);
	add_temp("apply/dodge",600);
	add_temp("apply/attack",600);
	add_temp("apply/unarmed_damage",600);

	set("combat_exp",14000000);
	create_family("日月神教",21,"弟子");
	setup();
	NPC_D->full_init(this_object());
	carry_object(__DIR__"obj/cloth")->wear();
}
