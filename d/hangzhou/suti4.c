// suti4.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "苏堤");
	set("long", @LONG
春晓，漫步林荫道上，烟柳笼纱，雀鸟欢鸣，一片生机。苏堤春晓被
列为西湖十景之首，果然名不虚传。北边是压堤桥，南面是望山桥。东面
一片梅林，林后似乎有座院落，但看不真切。
LONG
);
	set("exits", ([
		"north"	 : __DIR__"suti3",
		"south"	 : __DIR__"suti5",
	]));
	set("objects", ([
		__DIR__"npc/liyuanzhi" : 1,
		__DIR__"npc/wuya" : 1,
		__DIR__"npc/maque" : 2,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
