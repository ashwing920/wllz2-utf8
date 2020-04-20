
inherit ROOM;

void create()
{
        set("short","长廊");
        set("long", @LONG
一人多高，只容两人并行的檀香木走廊，廊中的两侧陈列着一些奇花
异草。滚滚热气从走廊的一头冒出，将檀木地板打得又湿又滑，你几乎要
扶着栏杆才不会滑倒。
LONG
);
        set("exits", ([
                "south" : __DIR__"bathhouse_f1",
                "west"  : __DIR__"bathhouse_f3",
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
           if( random(100) < 3 )
              {
               message_vision("$N脚下一个不稳，四脚朝天地摔在地上。\n\n",me);
               this_player()->unconcious();
               return 0;
              }
        if(  dir == "north" && me->query("gender") != "女性")
        return notify_fail("这是女人浴室，你冲进去作什么？\n");
        return 1;
}
