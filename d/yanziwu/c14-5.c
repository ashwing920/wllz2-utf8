                                      inherit ROOM;

void create()
{
        set("short","长廊");
        set("long", @LONG
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉
璃瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟
、家丁们走来走去，都忙着自己的事情，西面是杂货室，北面是长廊的延
伸。
LONG);
        set("exits", ([
                "west" : __DIR__"zahuoshi",
                "north" : __DIR__"c14-4",
        ]));
        set("objects",([
                "/d/center/npc/kid" : 1,
                CLASS_D("murong")+"/murongbo" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
