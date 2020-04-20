//Room: /d/dali/hualang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","花廊");
	set("long",@LONG
这里是大理国皇宫的花廊，走廊下到处是奇花异草，往北是正殿，往
南是御花园，往西是御膳房，往东是偏殿。
LONG
);
	set("objects", ([
		__DIR__"npc/gongnu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"yuhuayuan",
		"north"  : __DIR__"zhengdian",
		"east"   : __DIR__"piandian",
		"west"   : __DIR__"yushanfang",
	]));
	setup();
	replace_program(ROOM);
}


