inherit ROOM;

void create()
{
        set("short","碧水亭");
        set("long",@LONG
这是湖中的一个小亭子，从这望去，可以看到整个湖面的景色，令人
心旷神怡。亭子壁上刻画着江南水乡的宜人风景，令人产生无限遐想。亭
上有一根梁（liang)。
LONG);
        set("exits",([
                "east" : __DIR__"muqiao",
        ]));
        set("item_desc", ([
                "liang" : "房梁是上好的楠木做的,上面还有十分古怪的字画。\n",
        ]));
        setup();

}

void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
        object me;
        me = this_player();

        if (arg !="liang")
                 return notify_fail("你要到那去？\n");
        if (me->query_dex()<20)
                write("你试图跳上房梁，无奈身法不够敏捷，只好做罢。\n");
        else {
                write("你纵身跃上了房梁。\n");
                message("vision",me->name() + "一纵身跃上了房梁。\n",environment(me), ({me}) );
                me->move(__DIR__"liang");
                message("vision",me->name() + "从下面跃了上来。\n",environment(me), ({me}) );
                return 1;
        }
}
