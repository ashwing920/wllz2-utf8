// dixiaoshi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;
void create()
{
        set("short", "林间小屋");
        set("long", @LONG
你走进了一间小屋。四周墙壁都由青竹篾编成，窗外是一望无际的竹
林。屋里的桌椅、床铺均为竹制。但一阵扑鼻而来的狗肉香味，却显得与
这清雅的气纷格格不入。
LONG
);
        set("exits", ([ 
                "west" : __DIR__"gbandao"
        ]));
        set("objects", ([
                CLASS_D("gaibang") + "/hong" : 1,
                CLASS_D("gaibang") + "/master_gaibang" : 1,
                "/clone/weapon/zhubang": 1,
                "/clone/food/gourou": 1,
                "/clone/food/jiudai": 1,
                "/clone/food/jitui": 1
        ]));

        set("valid_startroom", 1);
        set("sleep_room", 1);

        setup();

        replace_program(ROOM);
        "/clone/board/gaibang_r"->foo();
}
