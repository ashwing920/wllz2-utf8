//Room: /d/dali/piandian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","偏殿");
	set("long",@LONG
这里是大理国皇宫的偏殿，大理皇帝常在这里接见心腹大臣，但现在
显得空空荡荡的，往西是长廊。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"hualang",
	]));
	setup();
	replace_program(ROOM);
}

