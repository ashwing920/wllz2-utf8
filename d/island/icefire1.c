                                     inherit ROOM;

void create()
{
        set("short", "冰火岛");
        set("long", @LONG
这是北极附近的一个大岛屿，周围一片青绿草地，岛屿西部都是尖石
嶙峋的山峰，奇形怪样，莫可名状。岛东却是一片望不到尽头的平野，岛
上气候便和长白山、黑龙江一带相似。
LONG
);
        set("exits", ([
                "east" : __DIR__"icefire_land",
                "west" : __DIR__"icefire_hill",
                "north" : __DIR__"icefire2",
                "south" : __DIR__"diaoyu1",
        ]));
        set("outdoors", "island");
        setup();
}
