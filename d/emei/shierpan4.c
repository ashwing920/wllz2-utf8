//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: shierpan4.c 十二盘

inherit ROOM;

void create()
{
	set("short","十二盘");
	set("long",@LONG
这里石阶陡折多弯，号称「十二盘」。由此西上可达华严顶，东下则
到万年庵。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"northeast" : __DIR__"shierpan3",
		"up"	: __DIR__"huayanding",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if(dir == "up"){
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		me->add("qi",-1);
	if(((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
		tell_object(me,"你沿十二盘又往上爬了一阵，终于到了华严顶，好累人。\n");
	}
	return 1;
}
