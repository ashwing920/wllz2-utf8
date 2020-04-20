// Design By Robert 蝴蝶君 email:robert_st@sina.com

inherit ROOM;

void create()
{
        set("short", "成德殿");
        set("long", @LONG
殿中摆放着一张大桌，桌上放满了文房四宝，墙上挂满了字画，布置
得十分清雅，旁边一道木梯通往上面。
LONG
);
        set("valid_startroom","1");
        set("exits", ([
                "east" : __DIR__"yaofang",
                "up" : __DIR__"changjingge",
                "south" : __DIR__"dadian",
                "north" : __DIR__"changlang2",
                "west" : __DIR__"zhuquetang",
        ]));
        set("objects", ([
                CLASS_D("riyue") +"/ji" : 1,
                CLASS_D("riyue") +"/master_riyue" : 1,
        ]));
        setup();
        "/clone/board/riyue_b"->foo();
}
