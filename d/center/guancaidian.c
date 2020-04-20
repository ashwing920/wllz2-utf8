// guancaipu.c - 棺材店
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
	set("short", "棺材店");
	set("long", @LONG
这里是桃源城的一间棺材店。墙上零散地挂着几串纸钱和元宝，棺材
店老板面无表情地站在柜台里面，对你的到来似乎漠不关心。听说最近城
里出现了杀手帮，店老板的生意显然好了许多。
LONG
);
	set("exits", ([
		"east" : __DIR__"roads6",
	]));
	set("objects", ([
		__DIR__"npc/seller-gcp" : 1,
	]));
	setup();
	replace_program(ROOM);
}
