            // Room: /d/suzhou/gumujiaohe.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short", "古木交诃");
        set("long", @LONG
古木交诃在荷花厅的西面，一排不同图案的漏窗，使你透过漏窗隐隐
看到中部的水光山色和高低错落的楼阁，此处赏景，有“移步幻影”之妙
。向西窗孔可以遥望绿荫轩、明瑟楼，给人一种“庭院深深深几许”和空
间不尽之感。
LONG
);
        set("outdoors", "suzhou");
        set("exits", ([
                "east"    : __DIR__"hehuating",
                "southwest" : __DIR__"chitang",
        ]));
        set("objects",([
                "/d/center/npc/lvke": 3,
        ]));
        setup();
        replace_program(ROOM);
}
