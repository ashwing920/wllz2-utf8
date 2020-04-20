//TOHSQ6.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
一挂巨大的瀑布白龙出霄般横越山间，水气已浓得仿佛可以滴下水珠
儿来。山峦间升起薄薄的青雾，凝聚不散。哗哗的水声震耳欲聋。
LONG );
	set("exits", ([
		"north" : __DIR__"tohsq7",
		"south" : __DIR__"tohsq5",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
