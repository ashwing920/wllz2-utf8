// roadn5.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "桃源北街");
        set("long", @LONG
这里是桃源城的北大街上，踩着坚实的青石板地面。这里人群已比较
稀少，东面是一家桃源城里唯一的一家书斋，出售一些书籍等。西面是一
所超度法场，不时传出阵阵铃铛声。再往北边走是桃源城的关帝庙了。
LONG
);

        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"shuzhai",
                "south" : __DIR__"roadn4",
                "west"  : __DIR__"chaodufachang",
                "north" : __DIR__"guandimiao",
        ]));

        setup();

        replace_program(ROOM);
}
