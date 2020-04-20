// anhai.c 安海港
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "安海港");
        set("long", @LONG
安海港是泉州三大港口之一。这里港阔水深，风平浪静。极目远眺，
海天一色，蔚蓝无暇。岸边停靠着密密麻麻的各种船只。东边有座姑嫂塔
。
LONG
);

        set("exits", ([ /* sizeof() == 4 */
                "east" : __DIR__"gushao",
                "north" : __DIR__"gangkou2",
        ]));

        set("objects", ([
                __DIR__"npc/kuli" : 1,
                __DIR__"npc/tiao-fu" : 1,
                __DIR__"npc/langren" : 2,
                __DIR__"npc/wokou" : 4,
        ]));
        set("outdoors", "quanzhou");
        setup();
}
