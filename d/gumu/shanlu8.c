// shanlu8.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
此段山路是沿着峭壁而开凿出来的，特别崎岖难行。有时峭壁边必须
面贴山璧，侧身而过。尤其当山凤吹来时，更需特别小心，不然一失足，
就要掉进万丈深渊了。往北是一块广大的空地。往南下是一块巨岩。
LONG
);
	set("outdoors", "gumu");
	set("exits", ([
		"northup": __DIR__"daxiaochang",
		"southdown"  : __DIR__"juyan",
	]));

	setup();
	replace_program(ROOM);
}
