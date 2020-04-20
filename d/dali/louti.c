//Room: /d/dali/louti.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","楼梯");
	set("long",@LONG
这就是通往二楼“迎宾斋”的楼梯，楼梯高有五十余级，上面铺了鲜
红的毛毡，楼梯两侧站了一些素衣卫士，楼上则是贵宾休息的地方。
LONG
);
	set("objects", ([
		__DIR__"npc/weishi": 3,
		CLASS_D("dali")+"/gaoshengtai": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"up"	  : __DIR__"zoulang1",
		"south"   : __DIR__"dating",
	]));
	setup();
	replace_program(ROOM);
}

