// Room: /d/suzhou/canlangting.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "沧浪亭");
        set("long", @LONG
沧浪亭在苏州的北大街南侧，因为环境相对幽雅，使得男女老少都喜
爱在这里闲庭散步。在亭中放眼望去，四周一片碧绿的草坪，亭子翼然于
耸翠之中，飞檐凌空琵琶形牌科，布满檐口四周，亭上的额匾和石柱上的
楹联(lian)使人更加喜爱这里。
LONG
);
        set("outdoors", "suzhou");
        set("item_desc", ([
                "lian" :"清风明月本无价 近水远山皆有情\n",
        ]));
        set("objects",([
                "/d/center/npc/lvke": 3,
        ]));
        set("exits", ([
                "southeast" : __DIR__"dongdajie1",
                "southwest" : __DIR__"xidajie1",
                "north"  : __DIR__"beidajie1",
                "south"  : __DIR__"baodaiqiao",
        ]));
        setup();
        replace_program(ROOM);
}
