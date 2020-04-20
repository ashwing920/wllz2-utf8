// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","洞中岔路");
	set("long", @LONG
你来到了洞中的岔路之中，路道已经逐渐变窄了。由于处于山洞的深
处，洞里一片漆黑，连一丝丝光线也没有。偶然一阵啪嗒啪嗒的声响从你
身边飞过，一切显得更加诡异。
LONG
);
	set("exits",([
		"north": __DIR__"hole_nw/entry",
		"southeast": __DIR__"hole05",
	]));
	setup();
	replace_program(ROOM);
}
