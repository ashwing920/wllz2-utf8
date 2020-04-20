// main-03.c
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;

void create()
{
        set("short", "大厅");
        set("long", @LONG
这里是主人家的大厅，只见大厅之上装饰华丽，宽阔非常。大厅的地
面铺设着来自于关外的大理石，地面擦拭的非常干净，隐约可以看见地面
上呈现着你的倒影。大厅中央有一张红木制成的八仙桌，一个身材略为肥
胖的中年妇女正坐在桌旁品茗。两个丫环模样的女子正站在她身后为她捶
背。大厅两旁挂着一些出自于名人手笔的字画。
LONG
);
        set("exits", ([
                "north": __DIR__"main-04",
                "west" : __DIR__"main-05",
                "east" : __DIR__"main-02",
        ]));
        set("objects", ([
                "/d/qianjinlou/npc/yahuan" : 2,
                __DIR__"npc/furen":1,
        ]));

        setup();
        replace_program(ROOM);
}

