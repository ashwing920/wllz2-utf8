// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这一路上山，地势极险，脚下是万丈深谷，而山道极之陡峭窄小，倘
若一不留神，必将命丧于此。
LONG
);
	set("exits",([
		"westup" : __DIR__"baichi",
		"eastdown" : __DIR__"shandao",
	]));
	setup();
	replace_program(ROOM);

}
