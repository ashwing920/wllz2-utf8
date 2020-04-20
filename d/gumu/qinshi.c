// mishi8.c 密室
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","寝室");
	set("long", @LONG
这里是古墓中的密室，四周密不透风，你只能借着墙上昏暗的灯光来
勉强分辨方向。墙是用整块的青石砌合起来的，接合的甚是完美，你难以
从中找出一丝缝隙。密室中摆放着一些简单的家居用具，原来这是古墓派
祖师林朝英的居室。
LONG
);

	set("exits", ([
		"west" : __DIR__"mishi/exit",
	]));
	set("objects", ([
		CLASS_D("gumu") +"/lin" : 1,
	]));
	setup();
	replace_program(ROOM);
}
