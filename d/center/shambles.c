// shambles.c - 肉  场
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "集市肉场");
        set("long", @LONG
这里是桃源城的肉场，肉架上挂满了血淋淋的生肉，一股腥气扑面而
来，不时有几只苍蝇在屋里飞来飞去。靠近门口的地方有一块牛骨雕成的
招牌(sign)，上面写着些什么。
LONG
);
        set("outdoors", "center");
        set("exits", ([
                "south" : __DIR__"jishi",
                "north" : __DIR__"caichang",
        ]));
        set("item_desc",([
                "sign": @TEXT

新鲜猪肉出售。

TEXT
        ]));
        set("objects", ([
                __DIR__"npc/butcher": 1,
                __DIR__"npc/fly": 2,
                __DIR__"npc/crazy_dog": 2,
        ]) );
        setup();
        replace_program(ROOM);
}
