//wuchangdan.c
#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
}
void create()
{
	set_name(HIR"无常丹"NOR, ({"wuchang dan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗晶莹火红的无常丹，经桃花岛主精心练制，有起死回生之功。\n");
		set("value", 20000);
	}
	setup();
}

int do_eat(string arg)
{
	int force_limit, neili_limit, force_skill;
	int nowcondition;

	object me = this_player();

	force_limit = me->query_skill("force", 1)*10;
	neili_limit = me->query("max_neili");
	force_skill = me->query_skill("force", 1);

	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	if(arg=="dan" || arg == "wuchang dan") 
	{
		nowcondition = me->query_condition("bonze_drug");
		if ( nowcondition > 0 ){
		message_vision(HIG"$N吃下一只无常丹，只觉全身冰凉，看来你补药吃太多了，闹起肚子来了！\n" NOR, me);
			me->receive_damage("jing",(int)me->query("max_jing")/ 2);
			me->receive_damage("qi",(int)me->query("max_qi") / 2);
		}
		else
		{
			me->set("eff_jing",me->query("max_jing"));
			me->set("jing",me->query("max_jing"));
			me->set("eff_qi",me->query("max_qi"));
			me->set("qi",me->query("max_qi"));
			message_vision(HIR"$N吃下一颗无常丹，一股热流从丹田升起，顿时全身充满力量！\n"NOR,me);
			me->apply_condition("bonze_drug", 60);
		}
		destruct(this_object());
	}
	me->start_busy(2);
	return 1;
}