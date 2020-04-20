// qingcaop.c
//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "青草坪");
        set("long", @LONG
这里是树林中的一片比较大的空地，名曰：青草坪。因为处于密林之
中所以这里平时很少有人来，但是不知道为什么，这里却经常有人迹出现
。你看，又一个来了。
LONG
);
        set("exits", ([
                "north" : __DIR__"xiaodao3",
                "south" : __DIR__"xiaodao5",
                "east" : __DIR__"xiaodao4",
                "west" : __DIR__"xiaodao1",
        ]));
        set("outdoors", "xiaoyao");
        set("objects", ([
                CLASS_D("xiaoyao")+"/suxingh": 1,
                CLASS_D("xiaoyao")+"/master_xiaoyao": 1,
        ]));
        set("valid_startroom", 1);
        
        setup();
        replace_program(ROOM);
        
        "/clone/board/xiaoyao_b"->foo();
}
