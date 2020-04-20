// Room: /d/henshan/liuyunping.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "流云坪");
	set("long", @LONG
每逢雨霁，在后山深壑中升腾起来的云山雾海，涌过南天门山脊，向
前山倾泻，直如银河飞泻，蔚为壮观，这就是南天门的流云奇景。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"westdown"  : __DIR__"nantian",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

