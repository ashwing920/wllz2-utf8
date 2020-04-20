// Design By Robert 蝴蝶君 Email:robert_st@sina.com
//road1.c 黄土路

inherit ROOM;

void create()
{
        set("short", "乱石坡");
        set("long", @LONG
这是一处乱石怪异的小山岗，向西便是通向云南的大路了。据说前方
经常有野兽出没，不可久留。
LONG
);
        set("outdoors", "wudang");
        set("exits", ([
                "southwest" : "/d/village/wexit",
                "southeast" : __DIR__"shidao3",
        ]));
        setup();
        replace_program(ROOM);
}
