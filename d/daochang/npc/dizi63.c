// daochang-dizi.c - 道场弟子

#include <ansi.h>
#include "daochang_dizi.h";

inherit NPC;

void create()
{
	set("title","百人道场第六十三层弟子");
	set_name(npc_name("男性"), ({"daochang dizi", "dizi" }));
	set("nickname",HIM"刚"NOR);
	set("long","这位是"+ query("title")+"。\n");
	set("gender","男性");
	set("age",20);
	set("attitude", "heroism");
	set("chat_chance_combat",20);
	set("chat_msg_combat", ({
		(: perform_action, "staff.chan":),
		(: perform_action, "staff.tianxia":),
		(: exert_function, "regenerate":),
		(: exert_function, "recover" :),
	}));
	add_temp("apply/damage",300);
	add_temp("apply/armor",300);
	add_temp("apply/dodge",300);
	add_temp("apply/attack",300);
	set("combat_exp",7300000);
	create_family("丐帮",21,"弟子");
	setup();
	NPC_D->full_init(this_object());
	carry_object(__DIR__"obj/cloth")->wear();
}
