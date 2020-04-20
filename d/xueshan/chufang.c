// chufang.c 厨房
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","厨房");
	set("long",@LONG
这里是雪山寺的厨房，新来的僧人可以在此打杂。房中醒目的位置有
一块牌子（paizi）。
LONG
);
	set("exits",([
		"south" : __DIR__"xiaoyuan",
	]));
	setup();
}
