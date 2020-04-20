// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: guangchang.c

inherit ROOM;
void create()
{
        set("short", "蜀都广场");
        set("long", @LONG
这里是成都提督府前广场。好空旷的地方，只有稀稀落落几个没精打
采的行人。北面就是提督府了，南边是提督街。广场周围种了一圈遮阳树
，但骄阳仍把青石广场地面晒得滚烫冒烟。
LONG
);
        set("outdoors", "chengdu");
        set("exits", ([
                "east"  : __DIR__"shuduroad1",
                "west"  : __DIR__"shuduroad2",
                "south" : __DIR__"tiduroad",
                "north" : __DIR__"tidugate",
        ]));
        
        set("objects", ([
                "/d/city/npc/wujiang" : 2,
                "/clone/npc/xunbu": 4,
        ]));
        setup();
        replace_program(ROOM);
}
