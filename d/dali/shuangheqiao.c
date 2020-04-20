//Room: /d/dali/shuangheqiao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","双鹤桥");
	set("long",@LONG
这是一个岔路口，北边是座青石拱桥名叫双鹤桥，此桥跨在绿玉溪上
，桥北即是大理城，由此南去是通往南方的喜州、龙口等城镇的官道，东
去的岔路通往广西，沿绿玉溪南岸西行可达五华楼。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	 : __DIR__"southgate",
		"west"	  : __DIR__"luyuxi",
		"south"	 : __DIR__"road4",
		"southeast" : __DIR__"road5",
	]));
	setup();
	replace_program(ROOM);
}

