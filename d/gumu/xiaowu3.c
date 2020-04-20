// xiaowu3.c 孙婆婆小屋
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
这里是远离正厅的一间小屋，收拾得整整洁洁一尘不染。摆设就如普
通人家一般，红木的桌椅，细磁的杯壶，沉香的大床。你简直想象不到这
幽深的古墓之中还有这等摆设。
LONG
);

	set("exits", ([
		"west" : __DIR__"xiaowu2",
	]));

	set("objects", ([
		CLASS_D("gumu") +"/sun" : 1,
		__DIR__"obj/ping" : 1,
	]));

	setup();
	replace_program(ROOM);
}
