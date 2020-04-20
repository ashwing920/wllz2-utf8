// crazy_dog.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("疯狗", ({ "crazy dog", "dog" }));
	set("long", @LONG
一只浑身脏兮兮的野狗，一双眼睛正恶狠狠地瞪著你。
LONG
);
	set("attitude", "aggressive");
	set("race", "野兽");
	set("age", 4);
	set("str", 20);		// 膂力
	set("cor", 30);		// 胆识
	set("combat_exp", 100);
	set("chat_chance", 6);
	set("chat_msg", ({
		(: random_move :),
	}) );
	set("chat_msg_combat", ({
		"疯狗大声吠叫：汪！汪！汪！汪！汪！汪！\n",
		"疯狗突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
	}) );
	set_temp("apply/attack", 15);
	set_temp("apply/armor", 2);
	set_temp("apply/damage", 6);
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
