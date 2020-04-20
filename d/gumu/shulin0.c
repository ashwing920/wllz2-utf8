// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com
// shulin0.c 树林

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
走在林中，你只闻铮铮琴声，一股淡淡白烟，带着极甜的花香，自密
林深处传出。一群乳白色的蜜蜂在你身旁不停的飞来飞去。只见一块石碑
(shibei)立在当眼ㄦ处。往东是一块空地。其它方向尽是茂密的树林。
LONG
);
	set("outdoors", "gumu");
	set("item_desc", ([
		"shibei" : @TEXT

	终南古墓，
	外人止步。
TEXT
	]));
	set("exits", ([
		"southup" : __DIR__"shulin1",
		"north" : __DIR__"shulin4",
		"west"  : __DIR__"shulin5",
		"east"  : __DIR__"shulin6",
	]));

	setup();
	replace_program(ROOM);
}
