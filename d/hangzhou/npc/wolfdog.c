// wolfdog.c

inherit NPC;

void create()
{
	set_name("大狼狗", ({ "wolf dog", "dog" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "凤老爷府上的一只昂首挺胸，吐着长舌头的大狼狗。\n");
	set("attitude", "peaceful");
	set("str", 26);
	set("cor", 30);
	set("combat_exp", 1000);
	set("eatable",1);
	set("afterdie",__DIR__"obj/goupi");
	set("chat_msg_combat", ({
		(: random_move :),
		"大狼狗大声吠叫：汪！汪！汪！汪！汪！汪！\n",
		"大狼狗突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
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
