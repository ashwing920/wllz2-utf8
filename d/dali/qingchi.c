//Room: /d/dali/qingchi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","清池");
	set("long",@LONG
在这里你能享受到城内少有的清净。清池建于南诏年间，后有修复，
在大宋园林工匠的帮助下，更添姿彩。池内鱼虾龟虫倒也养了不少，在这
四季如春的气候下，荷花睡莲无比妖娆。
LONG
);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"sheguta",
	]));
	setup();
	replace_program(ROOM);
}

