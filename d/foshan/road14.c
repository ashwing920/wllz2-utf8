//Design By Robert 蝴蝶君 email:stcoolman@21cn.com
//Room: /d/foshan/road14.c

inherit ROOM;

void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。东面就是泉州城的西门吊桥，
向西南可达岭南广东。
LONG
);
	set("objects", ([
		__DIR__"obj/hua3": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([
                "east"    : "/d/quanzhou/xiqiao",
		"southwest" : __DIR__"road13",
		"west":     __DIR__"shulin",
	]));
	setup();
}

