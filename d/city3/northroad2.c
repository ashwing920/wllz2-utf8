// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: northroad2.c

inherit ROOM;

void create()
{
        set("short", "北大街");
        set("long", @LONG
这里一条北大街横贯东西。望向北边，是出城的北门。号称 "天下幽
" 的青城山，就是从这里出去。这里地当当道，行人却都过往匆匆，小心
翼翼，恨不得销声匿迹。
LONG
);
        set("outdoors", "chengdu");
        set("exits", ([
                "east"   : __DIR__"northroad3",
                "west"   : __DIR__"northroad1",
                "north"  : __DIR__"northgate",
        ]));
        
        setup();
}
