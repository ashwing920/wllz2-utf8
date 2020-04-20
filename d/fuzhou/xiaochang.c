// Room: /d/fuzhou/xiaochang.c

inherit ROOM;

void create()
{
	set("short", "校场");
	set("long", @LONG
福州校场为福建水师校场。场中点将楼上高挂“施”字黑锈金边帅旗
，刀枪耀日生辉。水师提督施琅施大人亲率十万雄兵，隔海相望，壮心不
已。
LONG
);
	set("exits",([
		"west"   : __DIR__"nanmendou",
	]));
	set("outdoors", "fuzhou");
	setup();
	replace_program(ROOM);
}
