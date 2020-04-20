//RJQLWCH.C
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
走进了锐金旗的练武场，发现这里有些奇怪。练武的教众们并不是在
相互切磋，而是穿戴着特制的护具，同一架奇怪的装置打斗。装置从不移
开原地，只是它似乎具备用不完的各种兵器，进攻起来丝毫不弱于江湖好
手。
LONG
);
	set("exits", ([
		"north" : __DIR__"rjqyuan",
	]));
	setup();
	replace_program(ROOM);
}
