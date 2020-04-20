//Room: /d/dali/sikong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","司空堂");
	set("long",@LONG
这里是大理国司空堂。堂内无余物，四壁却堆满了书籍。想来主人爱
书如命，即便工余亦手不释卷。
LONG
);
	set("objects", ([
		CLASS_D("dali")+"/batianshi" : 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zonglichu",
	]));
	setup();
	replace_program(ROOM);
}

