//Cracked by Kafei

#include <ansi.h>

inherit ITEM;

int cure_ob(string);

void create()
{
	set_name("定神丸", ({"dingshen wan","wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("value", 2000);
		set("long", "这是一颗可以让人头脑清醒，恢复精神的定神丸。\n");
		set("medicine", 1);
	}
	setup();
}

int cure_ob(object me)
{
	message_vision("$N吃下一颗" + name() + "。\n", me);
	if((int)me->query("eff_jing") < (int)me->query("max_jing") / 6){
		write("你伤势过重，服食丹药仅能略尽人事！\n");
	}
	else if ((int)me->query("eff_jing")==(int)me->query("max_jing")){
		me->receive_wound("jing", 50);
		write( HIR "你没伤胡乱服食丹药，反有大害！\n\n" NOR );
	}
	else {
		if((int)me->query("eff_jing") < (int)me->query("max_jing")) {
			me->receive_curing("jing",200);
		}
		message_vision(YEL"$N只觉精神大为好转，可见此丹灵效。\n\n"NOR,me);
	}
	destruct(this_object());
	return 1;
}