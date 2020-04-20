// cuiweiting.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "翠微亭");
	set("long", @LONG
翠微亭建在飞来峰的半山间，是名将韩世忠为纪念岳飞而建的。岳飞
有“经年尘土满征衣，特特寻芳上翠微”的诗句，故亭名“翠微”。西边
是下山的路。
LONG
);
	set("exits", ([
		"westdown"  : __DIR__"qinglindong",
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
