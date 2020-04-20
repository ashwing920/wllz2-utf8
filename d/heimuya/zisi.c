// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short", "紫石崖");
	set("long", @LONG
片片粉石中忽起出一处冲天石崖，通体却是紫色，阳光映照下，石体
闪闪欲动，非常陡峭。
LONG
);
	set("exits", ([
		"eastdown" : __DIR__"taohua",
	]));
	set("objects", ([
		"/d/center/npc/bee": 4,
	]));

	set("outdoors", "xx" );

	setup();
	replace_program(ROOM);
}
