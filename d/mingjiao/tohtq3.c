//TOHTQ3.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山路掩在土层下，前面似乎没有路了。满山树林密集，鸦鸟群集，林
中烟雾飘荡，不知所之。
LONG
);
	set("exits", ([
		"southup" :__DIR__"tohtq2",
		"enter"   :__DIR__"tohtq4",
	]));
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}
