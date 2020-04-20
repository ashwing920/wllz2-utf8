// houmen.c 后门
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","后门");
	set("long",@LONG
这是雪山寺的后门。一片破落而萧索模样。喇嘛们香火也足，花用也
大。这是后门，虽然未免寒酸，可也总可以掖着。
LONG
);
	set("exits",([
		"south" : __DIR__"houyuan",
	]));
	setup();
	replace_program(ROOM);
}

