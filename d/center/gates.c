// gates.c - 南城门
// Design By Robert 蝴蝶君 Email:robert_st@263.net

inherit ROOM;
#include <ansi.h>
string look_gaoshi();

void create()
{
        set("short", "南城门");
        set("long", @LONG
这里是桃源城南城门，城门正上方刻着“南门”两个楷书大字，城墙
上贴着几张官府告示(gaoshi)。官兵们警惕地注视着过往行人，你最好小
心为妙。一条笔直的青石板大道向南北两边延伸。南边是郊外，隐约可见
一片一望无际的树林。北边是城里。
LONG
);
        set("exits", ([ 
                "south" : "/d/road/xia-s1",
                "west":"/d/earth/wall",
                "north" : __DIR__"roads4",
        ]));
        set("item_desc",([
        	"gaoshi": (: look_gaoshi :),
        ]));
        set("objects", ([
              	"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing": 2,
        ]) );
        set("outdoors", "center");

        setup();
}

string look_gaoshi()
{
	return  FINGER_D->get_killer()+"\n桃源城知府。\n\n";
}
