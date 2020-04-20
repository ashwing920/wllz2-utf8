// ymdongting.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "衙门正厅");
        set("long", @LONG
堂上东西有两根楹住，挂着一幅对联，但是你无心细看。正墙上悬挂
一个横匾，上书“正大光明”四个金光闪闪的大字。知府正坐在文案后批
阅文书，师爷随侍在后。
LONG
);
        set("exits", ([
                "east"  : __DIR__"dongting",
                "west"  : __DIR__"xiting",
                "north" : __DIR__"neizhai",
                "south" : __DIR__"yamen",
        ]));
        set("no_fight",1);
        set("objects", ([
                __DIR__"npc/cheng" : 1,
                __DIR__"npc/shiye" : 1,
                "/clone/npc/xunbu": 4,
        ]));
        setup();
        replace_program(ROOM);
}
