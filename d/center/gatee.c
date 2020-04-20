// gatee.c - 东城门

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "桃源城城门");
	set("long", @LONG
这里是桃源城的城门了。进出于桃源城的商人，游客络绎不绝，由于
桃源城只有一个城门，桃源城知府便委派了几个官兵，严厉的把守着。只
见几个官兵和武将们正站在城门的两边，眼睛不停的注视着来来往往的人。
LONG
	);

	set("exits", ([
  		"east" : "/d/shaolin/road",
		"west" : __DIR__"roade4",
	]));
	set("city_gate",1);
        set("objects", ([
              	"/d/city/npc/wujiang" : 2,
		"/d/city/npc/bing": 4,
        ]) );
	setup();
}
