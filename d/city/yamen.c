// yamen.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "衙门大门");
        set("long", @LONG
这里是衙门大门，两扇朱木大门紧紧关闭着。“肃静”“回避”的牌
子分放两头石狮子的旁边。前面有一个大鼓，显然是供小民鸣冤用的。几
名衙役在门前巡逻。
LONG );
        set("exits", ([
                "south" : __DIR__"xidajie1",
                "north" : __DIR__"ymzhengting",
        ]));
        set("objects", ([
                __DIR__"npc/yayi" : 4,
        ]));

        setup();
}

