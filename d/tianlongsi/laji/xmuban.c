// xmuban.c 小木板
// xueer

inherit ITEM;

void init();
void create()
{
	object me;
	string name,new_name;
	me=this_player();
	name = me->query("id")+"_muban";
	new_name = me->query("name")+"要清扫的东西";
	set_name("小木板", ({"xiao muban","muban",name}) );
	set_weight(20);
	set("unit", "块");
	set("long", "这是一块废弃的小木板, 它是"+new_name+"。\n");
	set("no_get",1);
//	  set("value", 10);
	setup();
}