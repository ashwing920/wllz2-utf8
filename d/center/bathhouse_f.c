
inherit ROOM;

void create()
{
        set("short", "浣凰堂");
        set("long", @LONG
四面的墙壁挂满了风干的花环，散发出醉人的香气。大堂的中央是一
个古色古香的青铜仙鹤，鹤嘴里面飘出袅袅青烟，沁人心脾。大堂的右边
是一个小小的柜台，台子的后面有一个木架，架子上挂满了白毛巾。
LONG
);
        set("exits", ([
                "down" : __DIR__"bathhouse_m",
                "west" : __DIR__"bathhouse_f1",
        ]));
        set("objects", ([
                __DIR__"npc/little_waiter": 2,
        ]) );
        setup();
        replace_program(ROOM);

}
