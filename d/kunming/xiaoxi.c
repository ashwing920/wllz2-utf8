// /d/kunming/qingshilu

inherit ROOM;

void create()
{
        set("short",  "路旁小溪");
        set("long", @LONG
这里是昆明郊外的一条小溪，白花花的溪水奔流，十分清澈。几个妇
人正在溪边洗衣服呢。
LONG
);
        set("outdoors", "kunming");
        set("kunming_job",1);
        set("exits", ([
                "north": __DIR__"qingshilu",
        ]));
        setup();
        replace_program(ROOM);
}
