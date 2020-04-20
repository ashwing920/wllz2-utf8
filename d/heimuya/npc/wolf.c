inherit NPC;

void create()
{
	set_name("野狼", ({ "wolf"}) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只昂首挺胸，吐着长舌头的野狼。\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("cor", 30);
	set("combat_exp", 10000);
	set("chat_chance", 6);
	set("chat_msg", ({
		(: random_move :),
	}) );
	set("chat_msg_combat", ({
		"野狼大声：喔！喔！喔！喔！喔！喔！\n",
		"野狼突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
	}) );
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);
	setup();
}
void init()
{
	object ob;

	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
	}
}
