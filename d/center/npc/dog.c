// dog.c

inherit NPC;

void create()
{
	set_name("野狗", ({ "dog" }));
	set("long", @LONG
一只浑身脏兮兮的野狗。
LONG
	);

	set("race", "野兽");
	set("age", 4);
	set("str", 24);		// 膂力
	set("cor", 26);		// 胆识
	set("combat_exp", 100);
	set("chat_chance", 6);
	set("chat_msg", ({
		"野狗用鼻子闻了闻你的脚。\n",
		"野狗在你的脚边挨挨擦擦的，想讨东西吃。\n",
		"野狗对著你摇了摇尾巴。\n",
		"野狗用後腿抓了抓自己的耳朵。\n",
		(: random_move :),
	}) );
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 3);
	set_temp("apply/damage", 0);
	set_temp("apply/dodge", 0);
	setup();
}

int accept_object(object who, object ob)
{
	if( ob->id("bone") ) {
		set_leader(who);
		message("vision", name() + "高兴地汪汪叫了起来。\n", environment());
		return 1;
	}
}

