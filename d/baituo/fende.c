//fende.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","坟地");
	set("long",@LONG
这里是荒凉阴森的荒坟地。四周一片漆黑，不时传来阵阵乌鸦的啼叫
声，让人胆颤心惊。
LONG
);
	set("outdoors", "baituo");
	set("exits", ([
		"southwest" : __DIR__"xiaolu1",
	]));
	set("objects" , ([
		 __DIR__"npc/guafu": 1,
	]));
	setup();
	replace_program(ROOM);
}
