// zhanqiao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "悬空栈桥");
	set("long", @LONG
栈道悬于南北危楼之间，由无数的掾铺成，每节掾宽尺许，九节并排
在一起，每根掾绑在铁索上，上铺木板，长数十丈，下临深渊。山风呼啸
，惊心动魄。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"south"   : __DIR__"xuankong2",
		"north"   : __DIR__"xuankong1",
	]));
	set("outdoors", "hengshan");

	setup();
	replace_program(ROOM);
}
