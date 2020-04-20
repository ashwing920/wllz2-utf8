// zhuguo.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG"朱果"NOR, ({ "zhu guo","guo"}) );
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
一颗圆圆的朱果，据说吃了会有神奇的效果。
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

	message_vision("$N拿起一颗$n，三两口就吃了个精光。\n",me,ob);

	if((int)me->query("zhounian_liwu/zhuguo")){
		tell_object(me,"你吃下朱果，却发现好象没什么用。\n");
		destruct(ob);
		return 1;
	}

	if(me->query("weapon")){
		if(random(4) < 1){
			tell_object(me,"恭喜！你的兵器有效级别增加了一级。\n");
			me->add("weapon/lv",1);
		}
		else{
			tell_object(me,"恭喜！你的兵器有效级别增加了二级。\n");
			me->add("weapon/lv",2);
		}
	}
	else if(me->query("armor")){
		if(random(4) < 1){
			tell_object(me,"恭喜！你的防具有效级别增加了一级。\n");
			me->add("armor/lv",1);
		}
		else{
			tell_object(me,"恭喜！你的防具有效级别增加了二级。\n");
			me->add("armor/lv",2);
		}
	}
	else if(me->query("make_horse")){
			if(random(4) < 1){
			tell_object(me,"恭喜！你的马匹最大生命值增加了一点。\n");
			me->add("make_horse/max_life",1);
		}
		else{
			tell_object(me,"恭喜！你的马匹最大生命值增加了二点。\n");
			me->add("make_horse/max_life",2);
		}
	}
	else {
			tell_object(me,"你吃下朱果，却发现好象没什么用。\n");
	}
	me->add("zhounian_liwu/zhuguo",1);
	me->start_busy(1);
	me->save();
	destruct(ob);
	return 1;
}
void owner_is_killed() { destruct(this_object());}