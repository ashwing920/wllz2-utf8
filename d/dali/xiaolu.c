// /d/dali/xiaolu

inherit ROOM;

void create()
{
        set("short","青石路");
        set("long", @LONG
一条青石大道，青石铺成，平坦宽阔，抬头向东一看，前面的城门清
晰可见。
LONG
);
        set("outdoors", "dali");
        set("exits", ([
                "west" : __DIR__"dahejieeast", 
                "east"  :"/d/kunming/xiaoximen",
        ]));
        setup();
        replace_program(ROOM);
}
