//Room: /d/dali/wuyiminju4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","乌夷民居");
	set("long",@LONG
这是一座用木柴及兽皮搭成的乌夷民居。此地的村民主要从事耕作，
由于实行换季轮耕，不得不经常迁徙，因而房舍都颇简陋，说是房舍，倒
不如说更象帐篷，拆、建都甚方便。
LONG
);
	set("objects", ([
		__DIR__"npc/kid": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"yixibu",
	]));
	setup();
	replace_program(ROOM);
}

