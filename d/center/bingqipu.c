// bingqipu.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "兵器铺");
	set("long", @LONG
这里是桃源城的兵器铺，兵器铺两边的墙壁上挂满了各类兵器。到处
银光闪闪，让人眼花缭乱。各色各样的兵器应有尽有，你一时不知道挑什
么好。
LONG
);
        set("exits", ([
                "north" : __DIR__"roadw4",
        ]) );
        set("objects", ([
                __DIR__"npc/seller-bqp" : 1,
         ]) );

        setup();

        replace_program(ROOM);
}

