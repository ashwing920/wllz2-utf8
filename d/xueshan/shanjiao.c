// shanjiao.c 山脚
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","山脚");
	set("long",@LONG
这里是山脚下的一片平地，山上不远处，皑皑白雪映照下的一大片红
墙金瓦处，就是远近闻名的雪山寺。
LONG
);
	set("outdoors","xueshan");
	set("exits",([
		"westup" : "/d/xuedao/nroad7",
		"south"  : __DIR__"hubian4",
	]));
	setup();
	replace_program(ROOM);
}

