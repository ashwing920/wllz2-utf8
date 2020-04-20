            // citong_s1.c 刺桐南路
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "刺桐南路");
        set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。由此东行便
到承天寺，西边是民宅，西南则是一处阿拉伯宅区。泉州出名的源和堂便
在西边。
LONG
);
        set("exits", ([ /* sizeof() == 4 */
                "east" : __DIR__"chengtian",
                "west" : __DIR__"minzai3",
                "north" : __DIR__"citong_s1",
                "southeast" : __DIR__"alabo",
        ]));
        set("objects",([
                "/d/songshan/npc/bo": 1,
        ]));
        set("outdoors", "quanzhou");
        setup();
        replace_program(ROOM);
}
