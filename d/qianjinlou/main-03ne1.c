// main-03ne1.c - 千金楼（游廊）

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "游廊");
        set("long", @LONG
这是通往藕香榭的游廊，游廊采用大理石铺设，显得十分尊贵。一个
妓女和一个嫖客正坐在游廊边上相互嬉戏，不时发出阵阵淫笑声，真是好
煞风景。
LONG
);

        set("outdoors", "qianjinlou");
        set("exits", ([
                "west"   : __DIR__"main-03n1",
                "east"   : __DIR__"main-03ne2",
        ]));
        set("objects",([
        	__DIR__"npc/jinu": 2,
        	__DIR__"npc/piaoke":1,
	]));
        setup();

        replace_program(ROOM);
}