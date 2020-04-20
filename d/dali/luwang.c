//Room: /d/dali/luwang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","鲁望镇");
	set("long",@LONG
这里是普麽部的鲁望镇，普麽部属台夷，领属还有附近的越州。这是
一座建在山坡上的小镇，东面和北面是高耸的群山，向西和南眺望均可见
村庄和城镇。
LONG
);
	set("objects", ([
		__DIR__"npc/tshangfan": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"west"	: __DIR__"feilihu",
		"east"	: __DIR__"yulin",
		"south"   : __DIR__"shuitian",
		"north"   : __DIR__"zhulou3",
	]));
	setup();
	replace_program(ROOM);
}

