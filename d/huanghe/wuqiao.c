// Room: /huanghe/wuqiao.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "乌鞘岭");
	set("long", @LONG
乌鞘岭是武威东南的一个险要地段，黑石山上密林重重，时常有野兽
出没。一条官道从山下蜿蜒而过。
LONG
);
	set("exits", ([
		"south"	 : __DIR__"dacaigou",
		"northwest" : __DIR__"wuwei",
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

