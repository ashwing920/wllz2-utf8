// kaochang.c - 考  场
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "考场");
        set("long", @LONG
这是桃源城的一所考场。并不是所有的人都醉心于行侠仗义，桃源城
中有意向仕途发展的年轻人在寒窗苦读之后，集中到这里参加考试。一名
考官背着手踱来踱去，监视着考生的一举一动。旁边挂著一块牌子(sign)。
LONG
);
        set("exits", ([
                "south" : __DIR__"roadw4",
        ]));
        set("item_desc", ([
                "sign": @TEXT
$CYN$

这里可以使用的命令有：
                
quest       询问试题
huida   　　回答问题
=       　　回答问题

$NOR$
TEXT
        ]));
        set("objects", ([
                __DIR__"npc/kaoguan": 1,
                __DIR__"npc/kaosheng": 2,
        ]));
        setup();
        replace_program(ROOM);
}
