//qingshe.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("竹叶青蛇", ({ "qing she", "she" }) );
	set("race", "蛇类");
	set("age", 2);
	set("long", "一只让人看了起鸡皮疙瘩的竹叶青蛇。\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 20);
	set("eatable",1);
	set("afterdie","/d/baituo/obj/qingdan");
	set("combat_exp", 30000+random(30000));

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
		if (!(ob = present("xionghuang", this_player())) &&
		(string)this_player()->query("family/family_name")!="白驼山派")
		{
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, this_player());
		}
	}
}
int hit_ob(object me, object ob, int damage)
{
	if ((int)ob->query("combat_exp") > 10000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
		&& (int)ob->query_condition("snake_poison") < 10 )
	{
		ob->apply_condition("snake_poison", 20);
		tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}
