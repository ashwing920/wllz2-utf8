// suti7.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "苏堤");
	set("long", @LONG
苏堤是诗人苏东坡在主持浚深西湖时用湖泥和草筑成的。苏东坡曾有
诗记述此事；“我在钱塘拓湖渌，大堤士女争昌丰。六桥横绝天汉上，北
山始与南屏通。忽惊二十五万丈，老葑席卷苍烟空。”往南便是大道，北
边是映波桥。映波桥乃苏堤六桥由至北南的第一座。
LONG
);
	set("exits", ([
		"north"	 : __DIR__"suti6",
		"south"	 : __DIR__"road20",
	]));
	set("objects", ([
		__DIR__"npc/shu-sheng" : 1,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
