// huantongdan.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW"还童丹"NOR, ({ "huantong dan","dan"}) );
	set("no_give", 1);
	set("no_drop",1);
	set("no_put",1);
	set("no_get",1);
	set("no_get_from",1);
	set("no_pawn",1);
	set("no_sell",1);
	set("no_beg",1);
	if( clonep())
		set_default_object(__FILE__);
	else {
		set("long", @TEXT
一颗小小的还童丹，据说吃了可以变得更年轻。
TEXT
);
	set("unit", "个");
	set("base_weight",500);
	set("value",0);

}
	setup();
}
void init()
{
	if(environment() == this_player())
	add_action("do_eat","eat");
}

int do_eat(string arg)
{
	object me,ob;
	me = this_player();
	ob = this_object();

	if(!arg || !id(arg)) return 0;

	if( me->is_busy()){
		write("你正忙着呢！\n");
		return 1;
	}

	message_vision("$N拿起一颗$n，一仰脖，立刻吞了下去。\n",me,ob);

	if( me->query("age") < 20 || (int)me->query("zhounian_liwu/huantongdan")){
		tell_object(me,"你吃下还童丹，却发现好象没什么用。\n");
		destruct(ob);
		return 1;
	}

	switch(random(3)){
		case 1:
			tell_object(me,"你吃下一颗还童丹，立刻精神抖擞，容光焕发，仿佛年轻了一些。\n");
			me->add("mud_age",-172800);
			me->add("age",-2);
			break;
		case 2:
			tell_object(me,"你吃下一颗还童丹，立刻精神抖擞，容光焕发，仿佛年轻了许多。\n");
			me->add("mud_age",-259200);
			me->add("age",-3);
			break;
		default:
			tell_object(me,"你吃下一颗还童丹，立刻容光焕发，好象已经年轻了一岁，精神看起来好多了。\n");
			me->add("mud_age",-86400);
			me->add("age",-1);
			break;

	}
	me->add("zhounian_liwu/huantongdan",1);
	me->start_busy(1);
	me->save();
	destruct(ob);
	return 1;
}
void owner_is_killed() { destruct(this_object());}