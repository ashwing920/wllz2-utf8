// Room: /d/dali/feilihu.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","妃丽湖畔");
	set("long",@LONG
你站在妃丽湖的北岸，北边不远就是喜州城。此湖不大，但湖水清澈
，鱼鳖皆有，不少台夷村民划着竹筏在湖上捕鱼。湖之南和东边半山上都
有台夷村镇，有道路绕湖东而过通向南边。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"north"	  : __DIR__"xizhou",
		"east"	   : __DIR__"luwang",
		"southeast"  : __DIR__"feilihueast",
	]));
	setup();
	replace_program(ROOM);
}
