//guanwai/tuyaoguan.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "土窑馆");
	set("long", @LONG
一迈进这间小房，一股脂粉混合着大蒜的味道扑鼻而来，差点把你呛
了一个跟头。屋内点着很多蜡烛和灯笼，把四壁照得通红。很多穿着破烂
的汉子，一手搂着姑娘，一个握着酒壶，正在高谈阔论。一个肥胖的老鸦
一遍招待着客人，一遍大声催促的这里的伴当和姑娘们。
LONG
);
	set("exits", ([
		"north" : __DIR__"dongcheng",
	]));
	set("objects", ([
		__DIR__"npc/jiaowenqi" : 1,
	]));
	setup();
	replace_program(ROOM);
}

