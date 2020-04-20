// chat_room_5.c - 侠客城聊天室

inherit CHAT_ROOM;

void create()
{
        set("short", "云中阁");
        set("long", @LONG
这里是英雄楼的云中阁，这里宽阔非常，足可容纳数十个人。云中阁
里装饰排场而又十分讲究，四壁辉煌。两边各有一排椅子，提供给来英雄
楼的侠客们休息的。不知不觉中，在这里呆上一年，江湖中也只是一天。
LONG
);
        set("exits", ([
                "out" : __DIR__"chat_room",
        ]) );                   
        set("objects",([
                 "/clone/misc/qipan": 1,
        ]));

        ::create();

        replace_program(ROOM);
}
