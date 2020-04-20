// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
山路突然陡峭，两旁山峰笔立，中间留出一条窄窄的石阶，仅能两人
并肩而行。
LONG
);
	set("exits",([
		"westup" : __DIR__"shijie2",
		"eastdown" : __DIR__"baichi",
	]));
	setup();
	replace_program(ROOM);
}
