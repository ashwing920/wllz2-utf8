//Cracked by Kafei

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("灵蛇", ({ "ling she", "she", "snake" }) );
	set("race","蛇类");
	set("age", 4);
	set("long", "一条银光闪闪的小蛇，产于西域，极为罕见。\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("cor", 30);
	set("dex", 35);
	set("combat_exp", 100000);
	set_temp("apply/attack", 55);
	set_temp("apply/damage", 56);
	set_temp("apply/armor", 52);

	setup();
}

void init()
{
	object ob;

	if (interactive(ob = this_player()) && ob->query("family/family_name") != "白驼山派" &&
		random(ob->query_kar() + ob->query_per()) < 30) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
	add_action("convert","bian");
}
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("bt_poison", 10 + me->query("snake_poison") +
		victim->query_condition("bt_poison"));
}
int convert(string arg)
{
	object me = this_player();
	object ob;

	if (!id(arg)) return 0;

	if (me->query("family/family_name") != "白驼山派")
		return notify_fail("你不能化蛇为杖。\n");
	if (me->query_skill("training",1) < 70 + random(70)) {
		kill_ob(me);
		return 1;
	}
	message_vision("$N左手按住灵蛇的头，右手轻抚其七寸，口中念念有词，片刻间将蛇化为一根蛇杖。\n",me,);
	ob = new("/d/xingxiu/obj/lingshezhang");
	ob->move(environment(this_object()));
	ob->set("poison_applied", me->query_skill("poison",1)/2);
	destruct(this_object());
	return 1;
}
