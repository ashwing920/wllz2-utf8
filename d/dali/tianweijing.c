//Room: /d/dali/tianweijing.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","天威径");
	set("long",@LONG
此处据说是三国时蜀汉诸葛孔明第七次擒孟获之处，孟获曰：“公，
天威也，吾既降，南人不复反也。”，故此得名。这是一条贯通南北的大
路，南去十里是喜州城，北上约三十里可达大理城。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"road4",
		"south"	  : __DIR__"xizhou",
	]));
	setup();
	replace_program(ROOM);
}

