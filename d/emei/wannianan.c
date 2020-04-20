//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: wannianan.c 万年庵

inherit ROOM;

void create()
{
	set("short","万年庵");
	set("long",@LONG
万年庵建在一座突起的山峰上，周围古木森森，清泉淙淙，闲步无坎
，吟游无坷，景色非常迷人。由此西上过十二盘可达华严顶，南下至白龙
洞。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"southdown" : __DIR__"bailongdong",
		"westup"	: __DIR__"shierpan1",
		"enter"	 : __DIR__"wnadian",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if(dir == "westup"){
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		me->add("qi",-10);
	if(((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	tell_object(me,"你爬上了十二盘，觉得上山的路又陡又弯，好累人。\n");
	}
	return 1;
}

