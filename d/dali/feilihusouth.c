//Room: /d/dali/feilihusouth.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","妃丽湖南岸");
	set("long",@LONG
这里是休猎部的渔船码头。岸边有台夷村民正在扎制竹筏，一些渔民
划着竹筏下湖捕鱼，新鲜的鱼鳖可以在附近的喜州、龙口等城镇卖出好价
钱。
LONG
);
	set("objects", ([
		__DIR__"npc/yufu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"south"	  : __DIR__"hexi",
	]));
	setup();
	replace_program(ROOM);
}

