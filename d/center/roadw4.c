// roadw4.c - 西大街
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short","桃源西街");
        set("long", @LONG
这里是桃源城的西大街，你走在大街之上，脚踩着坚实的青石板地面
。大街北面有一所考场，每年科举，许多参加科举考试的考生们都会来到
这里参考应试。大街南面则是一家兵器铺，出售一些名贵的兵器。在往西
走就是桃源城的不夜舫了。
LONG
);
        set("outdoors", "center");
        set("exits", ([
                "east"  : __DIR__"roadw3",
                "south" : __DIR__"bingqipu",
                "west"  : __DIR__"roadw5",
                "north" : __DIR__"kaochang",
        ]));
        setup();

	replace_program(ROOM);
}
