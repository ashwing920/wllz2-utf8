// Room: /d/shaolin/bydian.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "白衣殿");
	set("long", @LONG
这是白衣殿，供奉白衣观音大士。大士高居须弥座上，手托净瓶，眉
含微愁，唇绽浅笑，仿佛对人间疾苦既存忧心，又觉释怀。殿中放了红木
大香案，香案上供品齐备，香火十分旺盛。
LONG
);
	set("exits", ([
		"west" : __DIR__"guangchang5",
	]));
	setup();
	replace_program(ROOM);
}

