
inherit ROOM;

void create()
{
	set("short","厢房");
	set ("long",@LONG
这是一间厢房, 里面摆设简单, 只有一张床, 一张书桌和一把椅子。
LONG);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("exits",([
		"west" : __DIR__"xiaoting",
	]));
	setup();
	replace_program(ROOM);
}
