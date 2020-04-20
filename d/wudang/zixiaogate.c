//Room: zixiaogonggate.c 紫霄宫大门
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","紫霄宫大门");
	set("long",@LONG
你已走到了展旗峰下，前面就是武当山最为宏大的宫宇紫霄宫了。殿
宇依山而筑，高低错落有致。周围古木森森，翠竹成林，景色清幽。这里
是武当师徒的主要活动场所。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"northdown"  : __DIR__"shijie2",
		"southup"	: __DIR__"guangchang",
	]));
	set("outdoors", "wudang");
	setup();
	replace_program(ROOM);
}
