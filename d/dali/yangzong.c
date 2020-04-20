//Room: /d/dali/yangzong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","阳宗镇");
	set("long",@LONG
这里是强宗部的村镇，是么些蛮族的聚居区域，么些蛮族是摆夷的一
支。此处也是山间的小型平原，北面临着一片绿水，叫做明湖，这地方略
微偏远些，但有相当不少的摆夷人生活在附近。西南方有道路通向其它村
镇。
LONG
);
	set("objects", ([
		__DIR__"npc/bshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"westup"	 : __DIR__"shanlu8",
		"northeast"  : __DIR__"nongtian4",
		"southup"	: __DIR__"sanglin",
		"southwest"  : __DIR__"milin",
	]));
	setup();
	replace_program(ROOM);
}

