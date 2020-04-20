//Room: /d/dali/jisidawu1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","祭祀大屋");
	set("long",@LONG
这是乌撒部的祭祀大屋，颇为宽敞。屋子正中一张竹台，台上摆放着
一排竹制牌位，上书乌蛮族祖先之名。牌位后的墙上挂有大幅兽皮，上绘
龙形花纹，似是该族的图腾。一位老祭司常年守在祭台前，负责全族的祭
司活动。
LONG
);
	set("objects", ([
		__DIR__"npc/laojisi": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
		"out"	  : __DIR__"wuyiminju3",
	]));
	setup();
	replace_program(ROOM);
}

