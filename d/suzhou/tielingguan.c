// Room: /d/suzhou/tielingguan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "铁岭关");
	set("long", @LONG
关呈长方形，砖石结构，正中的三层敌楼为新建。铁岭关地处水陆要
冲登敌楼，既可了望，又能放炮射箭。这关垣、运河、石桥所组成的联合
工事，当时是为了防御合抵抗侵扰的倭寇。
LONG
);
	set("outdoors", "suzhou");
	set("exits", ([
		"south" : __DIR__"fengqiao",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 3,
	]));
	setup();
	replace_program(ROOM);
}

