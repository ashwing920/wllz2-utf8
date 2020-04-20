// Room: /d/henshan/shuiliandong.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "水帘洞");
	set("long", @LONG
水帘洞在紫盖峰下，在吐雾和香炉两峰之间。紫盖峰之水经山涧汇入
紫盖仙洞中，深不可测，水满则溢，飞瀑高二十余丈，数叠垂帘，飘泄而
下，蔚为壮观。明张居正诗曰：$WHT$误疑瀛海翻琼波，莫拟银河倒碧流，自是
湘妃深隐处，水晶帘挂五云头$NOR$。以赞叹这衡山大四绝之一的水帘洞之奇。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"westdown"	: __DIR__"shanlu12",
	]));
	set("outdoors", "henshan");
	setup();
	replace_program(ROOM);
}

