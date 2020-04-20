//guanwai/tiyun.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "梯云峰");
	set("long", @LONG
玉柱峰北，有一山峰，峰脊出梯河瀑布，远望如腾白如云，纵列如梯
，故名梯云峰。
LONG
);
	set("exits", ([
		"south"	  : __DIR__"yuzhu",
	]));
	set("outdoors", "guanwai");
	setup();
	replace_program(ROOM);
}
