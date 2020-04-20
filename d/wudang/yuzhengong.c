//Room: yuzhengong.c 遇真宫
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","遇真宫");
	set("long",@LONG
这里是进入武当山的第一道宫宇遇真宫，宽敞无比，可容千人食宿，
是进香客的一大歇脚处。三丰真人曾在此结庵修炼，因此宫中供着张三丰
真人像。由于张真人闭关已久，外人不知其是否仍在人间，民间传说他已
得道仙逝，立像膜拜。
LONG
);
	set("objects", ([
		CLASS_D("wudang") +"/zhixiang": 1,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"shijie1",
		"southup"  : __DIR__"wdbl",
	]));
	setup();
	replace_program(ROOM);
}
