// bank.c
// Design By Robert 蝴蝶君 emial:robert_st@263.net

inherit ROOM;

void create()
{
	set("short","彩票购买处");
	set("long", @LONG
这里是聚宝钱庄二楼的出售彩票的地方，一个票童正站在柜台前出售
彩票。柜台后面贴着一张字画，上面写着「财源广进」四个大字。柜台前
聚集了不少前来购买彩票，兑奖的人，人头攒攒，络绎不绝。
LONG
);

	set("exits", ([ 
		"down": __DIR__"bank",
	]));
/*
	set("objects", ([
		"/clone/npc/lottery_boy":1,
	]) );
*/
	set("no_fight",1);
	set("no_beg",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
