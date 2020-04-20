// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "议事厅");
	set("long", @LONG
这里是日月神教的聚议厅，是教中议事的地方。时时可以见到教主同
教中各位堂主。长老在此共商大计，教中各堂下属都皆尽叹服。
LONG
);
	set("exits", ([
		"west" : __DIR__"changlang6",
	]));
	setup();
	replace_program(ROOM);
}
