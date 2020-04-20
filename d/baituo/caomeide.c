// caomeide.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","草莓地");
	set("long",@LONG
这里是一块草莓地，鲜红的草莓散落在绿草中，让人感到美妙惬意。
LONG
);
	set("exits", ([
		"northeast" : __DIR__"shulin1",
	]));
	set("objects" , ([
		 __DIR__"obj/caomei" : random(7),
	]));
	set("outdoors","baituo");
	setup();
	replace_program(ROOM);
}
