// chat_room_1.c

inherit CHAT_ROOM;

void create()
{
        set("short","剑盟");
        set("long", @LONG
这里是英雄楼的剑盟一阁，是专门让各门派或江湖中各道的英雄侠客
讨论江湖中事的地方。这里收拾得十分干净，给人一种十分安宁详合的感
觉。不知不觉，在这里呆上一年，江湖中也只有一天。
LONG
);

        set("exits", ([
                "out" : __DIR__"chat_room",
        ]) );                   
        ::create();
        replace_program(ROOM);
}
