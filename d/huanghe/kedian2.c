// Room: /city/kedian2.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "客店二楼");
	set("long", @LONG
你正走在客店二楼的走廊上，可以听到从客房里不时地呼呼的打酣声
，一阵高过一阵。不时有睡意朦胧的旅客进进出出，到楼下的掌柜处付了
钱再上来睡觉。
LONG
);
	set("exits", ([
		"down"  : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));

	setup();
	replace_program(ROOM);
}

