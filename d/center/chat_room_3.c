// chat_room_3.c 

inherit CHAT_ROOM;

void create()
{
        set("short", "棍师");
        set("long", @LONG
这里是英雄楼的棍师厅，棍师厅中铺设豪华，大厅中央铺设着一层红
色地毯。中央有一对茶几，两旁则各有一排椅子，是平时提供给侠客英雄
们商议江湖中事的地方。棍师厅正中挂着一副字画，上面龙飞凤舞的写着
一个“棍”字。正气凛凛，让人不得不肃然起敬。
LONG
        );

        // set("outdoors", "center");

        set("exits", ([
                "out" : __DIR__"chat_room",
        ]) );                   

        ::create();

        replace_program(ROOM);
}

