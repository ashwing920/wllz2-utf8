// /d/kunming/road7

inherit ROOM;

void create()
{
	set("short","山路");
	set("long", @LONG
你走在一条崎岖的山路上，再往南，就进入了云贵高原了。北面是一
条大河拦住去路。
LONG
);
	set("outdoors", "kunming");
	set("exits", ([
		"south": __DIR__"yunnan",
		"north"  :__DIR__"road6",
	]));
	setup();
	replace_program(ROOM);
}
