// yuquan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "玉泉");
	set("long", @LONG
玉泉寺建在玉泉山上，原名清涟寺。走进玉泉寺，只见这里有几个水
池(pond)。朝东就是出寺下山的路。
LONG
);
	set("exits", ([
		"eastdown"  : __DIR__"road5",
	]));
	set("item_desc", ([
		"pond":"池旁的石碑刻着“古珍珠泉”，池内偶有小水泡上涌，好象一串珍珠\n",
	]));
	set("objects" , ([
		__DIR__"npc/you-ke" :1,
	]));
	set("outdoors", "hangzhou");
	setup();
	replace_program(ROOM);
}
