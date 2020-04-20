// Room: /d/dali/feilihueast.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","妃丽湖东");
	set("long",@LONG
你站在妃丽湖的东岸，脚下的土路绕湖东连接南北的村镇。眺望湖中
只见轻舟点点，正是捕鱼的台夷竹筏。路边尽是青青竹林，台夷的竹楼间
或出现。向西南去的岔路通往湖西的休猎部，正路向南直达龙口城。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"south"	  : __DIR__"longkou",
		"northwest"  : __DIR__"feilihu",
		"southwest"  : __DIR__"hexi",
	]));
	setup();
	replace_program(ROOM);
}

