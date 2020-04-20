//qingshe.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("竹叶青蛇", ({ "qing she", "she" }) );
	set("race","蛇类");
	set("age", 2);
	set("long", "一只让人看了起鸡皮疙瘩的竹叶青蛇。\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 20);
	set("combat_exp", 3000+random(300));
	set("eatable",1);
	set("afterdie","/d/baituo/obj/qingdan");
	set_temp("apply/attack", 18);
	set_temp("apply/damage", 15);
	set_temp("apply/armor", 12);
	set_temp("apply/defence",16);
	setup();
}

void init()
{
	object ob;

	if (interactive(this_player())){
		if (!(ob = present("xionghuang", this_player()))
		&& this_player()->query("combat_exp") > 10000){
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, this_player());
		}
	}
}
