// roads5.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
        set("short","桃源南街");
        set("long", @LONG
你走在桃源南大街上，踩着坚实的青石板地面。这里的游人络绎不绝
。你仔细一看，大街的东面有一家棋社，一块写着：桃源棋社的金字大匾
高高的挂在棋社的大门上方。西面是一家戏楼，不时传来阵阵喝彩声和欢
呼声，显得格外热闹。
LONG
);
        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"qishe",
                "south" : __DIR__"roads6",
                "west"  : __DIR__"xilou",
                "north" : __DIR__"roads4",
        ]));
        setup();
	replace_program(ROOM);
}
