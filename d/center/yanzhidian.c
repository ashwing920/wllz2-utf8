// yanzhidian.c - 胭脂店
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
	set("short", "胭脂店");
	set("long", @LONG
这里陈列着各式各样的胭脂，有从京都运来的，也有本地产的。胭脂
鲜红似血，香气扑鼻。每当朝阳初升，阳光照入店内，映在胭脂上，给人
一种耀眼的亮红。除了胭脂这里来卖刨花油，花粉袋。店老板听说就是当
年江湖中有名的易容高手。
LONG
);
	set("exits", ([
                "north": __DIR__"roadw2",
        ]) );
        set("objects", ([
                __DIR__"npc/seller-yzd": 1,
                __DIR__"npc/yitaitai": 1,
	]));
	setup();
	replace_program(ROOM);
}
