// kedian.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "客店");
        set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落脚
，你可以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接
待着南腔北调的客人。客店的主人从不露面，他究竟是谁，有各种各样的
猜测。墙上挂着一个牌子(paizi)。
LONG );
        set("item_desc", ([
                "paizi" : "楼上雅房，每夜五两白银。\n",
        ]));
        set("objects", ([
                "/d/center/npc/xiaotou":1,
                __DIR__"npc/xiaoer" : 1,
        ]));
        set("exits", ([
                "east" : __DIR__"majiu",
                "west" : __DIR__"beidajie1",
                "up"   : __DIR__"kedian2",
        ]));

        setup();
        "/clone/board/kedian_b"->foo();
}


int valid_leave(object me,string dir)
{
        if (!me->query_temp("rent_paid") && present("xiao er",environment(me))
        &&      dir == "up")
                return notify_fail("店小二拦在楼梯口，白眼一翻，说道：怎么着？想白住？\n");
                
        if ( me->query_temp("rent_paid") && present("xiao er",environment(me)) && dir != "up" )
        me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);

}
