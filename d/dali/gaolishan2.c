//Room: /d/dali/gaolishan2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","高黎山密林");
	set("long",@LONG
高黎山上地势险恶、树大林深，附近几乎毫无人烟。地处高山四季皆
寒，熊虎等猛兽时常出没，只有勇敢的猎人才敢上这里来。东面下山即是
泸水谷地。
LONG
);
	set("objects", ([
		"/d/hangzhou/npc/laohu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([
		"east"  : __DIR__"gaolishan1",
	]));
	setup();
	replace_program(ROOM);
}

