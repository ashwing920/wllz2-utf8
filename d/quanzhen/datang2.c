// datang2.c 大堂二进
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "大堂二进");
	set("long", @LONG
这里是大堂的第二重，是全真教弟子做功课的所在。现在还不到功课
时间，大堂里空荡荡的，只有全真教掌管上下杂事的掌理道长带领着几个
小道童在整理桌椅，预备餐饭。
LONG
);
	set("exits", ([
		"east" : __DIR__"datang3",
		"west" : __DIR__"datang1",
		"north" : __DIR__"cetang",
		"south" : __DIR__"piandian",
	]));
	set("objects",([
		__DIR__"npc/zhangli" : 1,
		__DIR__"npc/daotong1" : 1,
	]));
	setup();
	replace_program(ROOM);
}
