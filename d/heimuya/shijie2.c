// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
越往上，山势越陡峭，中间的石阶越窄，仅能一人行走，从这里往上
望，隐约望见一座石门。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
		"westup" : __DIR__"shimen",
		"eastdown" : __DIR__"shijie",
	]));
	setup();
	replace_program(ROOM);
}
