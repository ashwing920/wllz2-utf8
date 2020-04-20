// citong_e2.c 刺桐东路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "刺桐东路");
        set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。恩怨巷坐落
在北边，可通至擂台。擂台比武可是城里的一大盛事。
LONG
);
        set("exits", ([ /* sizeof() == 4 */
                "west" : __DIR__"citong_e1",
                "north" : __DIR__"enyuan",
        ]));
        set("objects", ([
                "/d/center/npc/boy": 2,
                "/d/center/npc/girl": 1,
                "/d/mingjiao/npc/changjinpeng": 1,
        ]));

        set("outdoors", "quanzhou");
        setup();
        replace_program(ROOM);
}
