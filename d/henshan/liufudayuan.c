// liufudayuan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "刘府大院");
	set("long", @LONG
刘府大院里现在挤着很多江湖豪客，原来今天是刘正风金盆洗手的好
日子。刘老爷子在衡阳人缘很好，来捧场的自然不少，大院里已摆了很多
张桌子，杯筷往来，很是热闹。
LONG
);
	set("exits", ([
		"north"  : __DIR__"liufudating",
		"out"	: __DIR__"liufugate",
	]));
	set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
		"/d/taishan/npc/jian-ke" : 1,
		"/d/huashan/npc/haoke" : 1,
	]));
	setup();
	replace_program(ROOM);
}
