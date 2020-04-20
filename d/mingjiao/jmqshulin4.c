//JMQSHULIN4.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "巨木旗树林");
	set("long", @LONG
你眼前骤然一暗，朦胧中，只见左右前后，到处都是铺天盖地的不知
名的巨树，好象松柏，又似冷杉，簇在一起，密实的枝叶象一蓬蓬巨伞般
伸向天空，遮天蔽日。你似乎迷失了方向，象没头苍蝇般到处乱闯。
LONG
);
	set("exits", ([
		"east" : __DIR__"jmqshulin4",
		"west" :__DIR__"jmqshulin4",
		"north" : __DIR__"jmqshulin5",
		"south" : __DIR__"jmqshulin4",
	]));
	set("outdoors", "mingjiao");

	setup();
	replace_program(ROOM);
}
