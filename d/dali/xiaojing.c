//Room: /d/dali/xiaojing.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","山区小径");
	set("long",@LONG
这是清源山区的碎石小径，曲折蜿蜒，两旁林木茂盛，遮天蔽日。满
径落叶，柔软稀松。虫鸟啾啾。凉风习习。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"east"	: __DIR__"jinzhihe",
		"westup"  : __DIR__"dadieshui",
	]));

	setup();
	replace_program(ROOM);
}

