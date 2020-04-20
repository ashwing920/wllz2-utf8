// Room: /d/fuzhou/rongcheng.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "榕城驿");
        set("long", @LONG
榕城驿是全省最大的客店，生意非常兴隆。外地游客多选择这里落脚
，你可以在这里打听到本省的风土人情。店小二里里外外忙得团团转，福
州的方言你是实在听不顺耳。还是上楼睡觉去。墙上挂着一个牌子(sign)。
LONG
);
        set("valid_startroom", 1);
        set("item_desc", ([
                "sign" : "楼上雅房，每夜五十两白银。\n",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
        ]));
        set("exits", ([
                "south" : __DIR__"dongdajie",
                "north" : __DIR__"majiu",
                "up"    : __DIR__"rongcheng2",
        ]));
        setup();
        "/clone/board/kedian5_b"->foo();
}

int valid_leave(object me, string dir)
{
        if ( !me->query_temp("rent_paid") && dir == "up" 
        && present("xiao er",environment(me)))
        return notify_fail("店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n");
        return ::valid_leave(me, dir);
}
