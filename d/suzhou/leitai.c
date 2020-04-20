// Room: /d/suzhou/leitai.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "擂台前广场");
	set("long", @LONG
这里是苏州擂台前面的一个大型广场，有许多人正在擂台上比武，到
处是人山人海，如果你也想试试身手，那么就请跳上擂台比试比试吧。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"east"  : __DIR__"hutong1",
	]));
	setup();
	replace_program(ROOM);
}

