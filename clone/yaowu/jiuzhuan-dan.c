//Cracked by Kafei

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void create()
{
	set_name(HIM"九转"HIC"回神丹"NOR, ({"jiuzhuan dan","dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("value", 1800);
		set("long", "这是一颗九转回神丹，拥有迅速恢复内力的功效。\n");
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	message_vision("$N吃下一颗" + name() + "。\n", me);

	if((int)me->query("neili") > (int)me->query("max_neili") * 2)
	{
		write(HIR"突然，你只觉得丹田之中一股真气逆转而行，忍不住“哇”的吐了一口鲜血。\n"NOR);
		me->revive_damage("qi",500);
		me->set("neili",0);
	}
	else {
		me->add("neili",1000);
		message_vision(HIW"$N只觉一股暖流由丹田徐徐升起，贯通了$N的四肢六脉。\n"NOR,me);
	}
	destruct(this_object());
	return 1;
}