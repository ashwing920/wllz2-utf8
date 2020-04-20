// wuchang2.c 武场
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "武场");
        set("long", @LONG
这里是全真教的演武场，地下的青砖本来铺的整整齐齐，却不知道被
谁踩出了几十个大大小小的凹坑。看的出来，这里成年累月的有弟子修炼
掌法步法，天长日久，地下就踩出了凹坑。武场中央立着几个练功用的木
人。
LONG
);
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"wuchang1",
                "east" : __DIR__"xiuxishi",
                "southeast" : __DIR__"shantang",
        ]));

        set("objects", ([
                "/d/shaolin/npc/mu-ren": 5,
        ]));

        setup();
        replace_program(ROOM);
}
