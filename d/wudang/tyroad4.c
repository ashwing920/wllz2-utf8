// tyroad4.c 崎岖山路
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

string* npcs = ({
        "guest",
        "tufei2",
        "guest",
        "xiao_tufei",
        "guest",
        "xiao_louluo",
});
void create()
{
        int i = random(sizeof(npcs));
        set("short", "崎岖山路");
        set("long", @LONG
你走在一条崎岖狭隘的山路上，一边是峭壁，一边是悬崖。高高的天
柱峰(feng)笼罩在云雾中，隐约可见。可是身旁的进香客和游人都仔细地
町着自己的脚下，不敢抬头望一眼，惟恐一不小心摔下去。更有强人趁机
打劫，行人无不噤声闭气，只求快点赶路。
LONG
);
        set("outdoors", "wudang");
        set("exits", ([
                "westup" : __DIR__"tyroad3",
                "southdown" : __DIR__"tyroad5",
        ]));
        set("objects", ([
                __DIR__"npc/"+npcs[i] : 1
        ]));
        setup();
}

