//TOHSQ5.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
水声越来越大，山间充满了浓浓的水气。山路上，断裂的山隙中，都
流出一道道细细的泉水，汇成一股澄碧的小溪，向山下蜿蜒流去。周围绿
意荡漾，鸟语鹦声，如置身仙境。
LONG
);
	set("exits", ([
		"north" : __DIR__"tohsq6",
		"south" : __DIR__"tohsq4",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
