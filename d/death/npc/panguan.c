// TIE@FY3

#include <ansi.h>
#include <command.h>

inherit NPC;

string *death_msg = ({
	HIW"朱笔判官那锐利的目光象利刃一般在你身上扫来扫去。\n\n"NOR,
	HIW"朱笔判官翻了翻勾魂簿，叹道：又一个夭折的短命鬼。\n\n"NOR,
	HIW"朱笔判官合上簿子说道：阳寿未尽？罢了罢了，你走吧。\n\n"NOR,
	HIW"一股阴冷的浓雾突然出现，很快地包围了你。\n\n"NOR,
});

string *revive_loc= ({
	"/d/center/guandimiao",
	"/d/city/wumiao",
});

void create()
{
	set_name("朱笔判官", ({ "panguan", "ghost judge" }) );
	set("long",
		"阎王身边的朱笔判官，专勾画天下人的生死。\n");
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
		"朱笔判官喝道：牛头，马面何在？\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("max_gin", 900);
	set("max_kee", 900);
	set("max_sen", 200);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	setup();
}

void init()
{

	if( !previous_object()
	||  !userp(previous_object())) return;
	call_out( "death_stage", 5, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	int i;
	object *inv;

	if( !ob || environment(ob) != environment()) return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 5, ob, stage );
		return;
	} else
		ob->reincarnate();

	inv =  all_inventory(ob);
	for (i = 0; i < sizeof(inv); i++)
		DROP_CMD->do_drop(ob, inv[i]);
	ob->move(revive_loc[random(sizeof(revive_loc))]);
	ob->set("startroom", base_name(environment(ob)));
	message("vision",
		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
		"很久了，只是你一直没发觉。\n", environment(ob), ob);
}
