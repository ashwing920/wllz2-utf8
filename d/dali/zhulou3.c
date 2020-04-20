//Room: /d/dali/zhulou3.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","大竹楼");
	set("long",@LONG
这是一座普通样式的台夷竹楼，建在鲁望镇中心，与四周其它竹楼比
占地广大得多，也特别高大，似有三层，正是普麽部的祭祀大屋。此处下
层也不养牲畜，打扫得干干净净。宽大的竹梯直通上层。
LONG
);
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"luwang",
		"up"	 : __DIR__"zhulou4",
	]));
	setup();
	replace_program(ROOM);
}

