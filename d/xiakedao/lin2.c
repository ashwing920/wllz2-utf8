// Room: /xiakedao/lin2.c

inherit ROOM;

void create()
{
        set("short", "树林");
        set("long", @LONG
这是一片茂密的树林，好象被人设计了一种阵，一走进来，你仿佛迷
失了方向。
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
                "east" : __DIR__"lin3",
                "west" : __DIR__"lin1",
                "south" : __DIR__"lin1",
                "north" : __DIR__"lin1",
                "southeast" : __DIR__"lin1",
                "northeast" : __DIR__"lin2",
        ]));
        setup();
        replace_program(ROOM);
}
