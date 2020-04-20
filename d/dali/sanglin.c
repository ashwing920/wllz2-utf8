//Room: /d/dali/sanglin.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","桑林");
	set("long",@LONG
一大片桑树林生长在低山的缓坡山腰上。养蚕、纺丝是摆夷族的重要
副业，摆夷妇女大都擅织丝，编织自己穿着的短裙，也用来和临近部落交
换些其它物品。一群摆夷姑娘正在林间忙着采摘桑叶。
LONG
);
	set("objects", ([
		__DIR__"npc/caisangnu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"northdown"  : __DIR__"yangzong",
	]));
	setup();
	replace_program(ROOM);
}

