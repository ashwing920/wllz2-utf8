//Room: /d/dali/gudao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","古道");
	set("long",@LONG
一条石板古道，两边树木苍翠，山势平缓，南面是一望无际的西双版
纳大森林。大道北面有一片宏伟建筑，一堵里许长的红墙隔开，越过墙头
可见一座高楼耸立，正是大理名胜五华楼。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"enter"   : __DIR__"dating",
		"west"	: __DIR__"shanlu6",
		"east"	: __DIR__"luyuxi",
	]));
	setup();
	replace_program(ROOM);
}

