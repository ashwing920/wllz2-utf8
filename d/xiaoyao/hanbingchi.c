// hanbingchi.c 寒冰池
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "寒冰池");
	set("long", @LONG
这里是逍遥派重地寒冰池。由于这里的湖面终年结冰因而得名，湖水
很深也很冷，一般不会武功的人是不敢下去的。近年来这里胜产一种娃娃
鱼，时常有人潜(out)下池去搜寻它，总也不知道结果如何。
LONG
);
	set("exits", ([
		"east"	 : __DIR__"xiaodao22",
	]));
	set("outdoors", "xiaoyao");
	setup();
}
void init()
{
	int i;
	object obj,me;
	me = this_player(); 

	if(me->query("id")=="wawa yu"){
	destruct(me);
	i = random(10);
	obj = new("/d/xiaoyao/npc/obj/wawayu");

	if ( i > 0) 
	if ( i > 1) 
	if ( i > 2) 
	if ( i > 3) 
	if ( i > 4) 
	if ( i > 5) 
	if ( i > 6)
	if ( i > 7)
	if ( i > 8)
	if ( i > 9)
	if ( i > 10) 
	obj->move("/d/xiaoyao/chi1");
	else obj->move("/d/xiaoyao/chi2");
	else obj->move("/d/xiaoyao/chi3");
	else obj->move("/d/xiaoyao/chi21");
	else obj->move("/d/xiaoyao/chi22");
	else obj->move("/d/xiaoyao/chi23");
	else obj->move("/d/xiaoyao/chi24");
	else obj->move("/d/xiaoyao/chi31");
	else obj->move("/d/xiaoyao/chi32");
	else obj->move("/d/xiaoyao/chi33");
	else obj->move("/d/xiaoyao/chi34");

}
	add_action("do_out","out");

}

int do_out()
{
	object me;
	me = this_player();
	
	message_vision("$N纵身跃起，空中一个浪里翻花，头下脚上，咚的一声潜入池中不见了。\n", me);
	me->move(__DIR__"chi1");
	return 1;
}

