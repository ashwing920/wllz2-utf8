// wawayu.c

#include <ansi.h>

inherit NPC;

void create()
{
	object me;
	string new_name;
	me=this_player();
	set_name("娃娃鱼", ({ "wawa yu","wawayu","yu"}));
	set("race","游鱼");
	set("age", 20);
	set("attitude", "peaceful");
	set("env/wimpy",20);
	set("chat_chance", 30);
	set("chat_msg", ({
		 "娃娃鱼从远处游了过来,盯着你看,不知道在打什么主意。\n",
		 "娃娃鱼在你面前游来游去, 对一旁的你看也看一眼, 看来它并不怕你。\n",
		 "娃娃鱼正盯着你看, 但看上去却十分的有善。\n",
		 (:random_move :),
	}));
	set("combat_exp", 10000+random(10000));
	set_temp("apply/attack", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);

	new_name = me->query("name")+"捕捉的对象";
	set("long","娃娃鱼是寒冰池里特有的动物,因为它们终年都在寒冰池里,所以有很高的药用价值。\n");
	setup();
}
void die()
{
	this_player()->set_temp("wang/鱼网",0);
	::die();

}
