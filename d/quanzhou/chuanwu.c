// chuanwu.c 船坞
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "船坞");
	set("long", @LONG
这里是云集了全国最好的造船技师和工匠。一眼望去，满是已完工和
即将完工的各种用途，各种大小的木船。坞内人们忙忙碌碌，一片繁忙景
象。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"gangkou2",
	]));
	set("objects", ([
		__DIR__"npc/kuli" : 2,
	]));
	setup();
	replace_program(ROOM);
}
