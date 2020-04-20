// huantongdan.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC"洗髓丹"NOR, ({ "xisui dan","dan"}) );
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
一颗小小的洗髓丹，据说吃了可以增长属性。
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

	if( me->query("age") < 20 || (int)me->query("zhounian_liwu/xisuidan")){
		tell_object(me,"你吃下洗髓丹，却发现好象没什么用。\n");
		destruct(ob);
		return 1;
	}

	switch(random(15)){
		case 1:
			tell_object(me,HIY"你的先天魅力增加了一点。\n"NOR);
			me->add("per",1);
			break;
		case 2:
			tell_object(me,HIY"你的先天悟性增加了一点。\n"NOR);
			me->add("int",1);
			break;
		case 3:
			tell_object(me,HIY"你的先天身法增加了一点。\n"NOR);
			me->add("dex",1);
			break;
		case 4:
			tell_object(me,HIY"你的先天根骨增加了一点。\n"NOR);
			me->add("con",1);
			break;
		case 5:
			tell_object(me,HIY"你的先天灵性增加了一点。\n"NOR);
			me->add("spi",1);
			break;
		case 6:
			tell_object(me,HIY"你的运气增加了一点。\n"NOR);
			me->add("kar",1);
			break;
		case 7:
			tell_object(me,HIY"你的先天定力增加了一点。\n"NOR);
			me->add("cor",1);
			break;
		default:
			tell_object(me,HIY"你的先天臂力增加了一点。\n"NOR);
			me->add("str",1);
			break;

	}
	me->add("zhounian_liwu/xisuidan",1);
	me->start_busy(1);
	me->save();
	destruct(ob);
	return 1;
}
void owner_is_killed() { destruct(this_object());}