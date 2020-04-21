//Room: /d/dali/nianhuasi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","拈花寺");
	set("long",@LONG
山路越走越荒僻，转过四个山坳，来到一座小小的古庙前，庙门上写
着‘拈花寺’三字。佛教是大理国教。大理京城内外，大寺数十，小庙以
百计，这座‘拈花寺’地处偏僻，无甚香火，即是世居大理之人，多半也
不知晓。
LONG
);
	set("objects", ([
		__DIR__"npc/pochen": 1,
		__DIR__"npc/poyi": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"enter"	  : __DIR__"nianhua1",
		"southdown"  : __DIR__"shanlu2",
	]));
	setup();
	replace_program(ROOM);
}
