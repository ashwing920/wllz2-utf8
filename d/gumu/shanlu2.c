// shanlu2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这条山路盘终南山主峰而上，山路贴着石璧凿出，只容一人可过，形
势极为险峻。往远处望去。群山环绕，列於脚下，百里美景尽收眼底，顿
时令人豪气陡声，想要长啸一声。往北下是一条山路。往东上就是终南山
主峰。
LONG
);
	set("outdoors", "gumu");
	set("exits", ([
		"northdown" : __DIR__"shanlu3",
		"eastup": __DIR__"zhufeng",
	]));

	setup();
	replace_program(ROOM);
}
