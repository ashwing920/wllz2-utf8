// Room: /d/xiangyang/walls1.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这是登向城头的石阶，因为城墙很高，所以很陡。石阶两侧有可供拉
车上下的斜坡道。
LONG
);
	set("outdoors", "xiangyang");
	set("exits", ([
		"westup"   : __DIR__"walls3",
		"eastdown" : __DIR__"southgate1",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if (dir == "westup" )
	{
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		me->receive_damage("qi",10);
		if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	}
	return 1;
}


