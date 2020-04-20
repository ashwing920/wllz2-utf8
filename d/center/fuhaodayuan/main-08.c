// main-06.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short","小屋");
        set("long", @LONG
这里是主人家提供给家丁们休息的小屋。小屋中虽然布置简单，但收
拾得十分干净。一张大床放置在小屋的靠边角落里，床上铺着一床厚厚的
床被，让人看了不禁想躺下休息一会儿。
LONG
);
        set("sleep_room",1);
        set("exits", ([
                "east":  __DIR__"main-06",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
