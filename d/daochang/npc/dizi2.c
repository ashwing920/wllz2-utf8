// daochang-dizi.c - 道场弟子

#include <ansi.h>
#include "daochang_dizi.h";

inherit NPC;

void create()
{
	set("title","百人道场第二层弟子");
	set_name(npc_name("男性"), ({"daochang dizi", "dizi" }));
	set("nickname",HIY"气"NOR);
	set("long","这位是"+ query("title")+"。\n");
	set("gender","男性");
	set("age",20);
	set("attitude", "heroism");
	set("combat_exp",1200000);
	create_family("武当派",18,"弟子");
	setup();
	NPC_D->full_init(this_object());
	carry_object(__DIR__"obj/cloth")->wear();
}
