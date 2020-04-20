// piandian.c 偏殿
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "偏殿");
        set("long", @LONG
这里是大堂旁边的一个侧厅，也是接待重要客人的地方。厅不大，只
摆放着一张桌子和几把椅子。桌上摆放着一盆青山隐隐的盆景，墙壁上挂
着一些字画。
LONG
);
        set("exits", ([
                "east" : __DIR__"nairongdian",
                "west" : __DIR__"xianzhentang",
                "north" : __DIR__"datang2",
                "south" : __DIR__"guangning",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/shen" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
