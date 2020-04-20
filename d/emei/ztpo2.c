//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: ztpo2.c 钻天坡

inherit ROOM;

void create()
{
	set("short","钻天坡");
	set("long",@LONG
莲花石与洗象池之间，道路陡绝，石栈若齿，直上蓝天，石蹬达一千
三百多级，是在陡峭山壁上开凿出来的坡道。人行其上，前后顶踵相接，
一如登天。这段路叫「鹁鸽钻天」，这段陡坡也因此而叫「钻天坡」。这
里西上坡顶便到洗象池，东下可达莲花石。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"eastdown"  : __DIR__"ztpo1",
		"westup"	: __DIR__"xixiangchi",  
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
		tell_object(me,"你在钻天坡又往上爬了一阵，终于到了洗象池，好累人。\n");
	}
	return 1;
}

