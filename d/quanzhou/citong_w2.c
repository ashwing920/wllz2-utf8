// citong_x1.c 刺桐西路

inherit ROOM;

void create()
{
        set("short", "刺桐西路");
        set("long", @LONG
这是泉州的主要干道，笔直宽广，车水马龙，热闹非凡。北边是开元
寺，南边是济世堂老店，西边则是西门吊桥。
LONG
);
        set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"kaiyuan",
                "west" : __DIR__"xiqiao",
                "east" : __DIR__"citong_w1",
                "south": __DIR__"yaopu",
        ]));
        set("outdoors", "quanzhou");
        setup();
        replace_program(ROOM);
}
