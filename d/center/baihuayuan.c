// baihuayuan.c - 百花园
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com           1997.7

#include <room.h>

inherit ROOM;

void create()
{
        set("short", "百花园");
        set("long", @LONG

    这里是侠客城百花园。一走进来，沁人心脾的阵阵花香象风儿一般迎
面扑进你的鼻中。园中景色优美，林木葱绿，碧水环绕，各种各样的花儿
争奇斗艳，古色古香的亭台楼阁掩映其间。还有叫不出名字的小鸟跳跃其
中，啾啾有声。向南是侠客城的小武场。
LONG
        );

        set("outdoors", "center");

        set("exits", ([
                "east"  : __DIR__"bathhouse",
                "west"  : __DIR__"kaochang",
                "north" : __DIR__"dahuaishu",
                "enter" : __DIR__"xiaowuchang_watch_room",
        ]) );                   
        set("objects", ([
                __DIR__"npc/girl": 2,
                __DIR__"npc/butterfly": 1,
              __DIR__"npc/bee": 1,
        ]) );

        setup();
        create_door("enter", "小木门", "out", DOOR_CLOSED);
        replace_program(ROOM);
}
