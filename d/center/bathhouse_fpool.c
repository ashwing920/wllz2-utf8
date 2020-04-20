
inherit ROOM;
#include <ansi.h>
#include <room.h>
#include "wash.h"

void create()
{
	set("short", "枫叶泉");
	set("long", @LONG
枫叶泉是方圆五百里最著名的一口温泉。水温适中，泉水呈淡红，故
而得名枫叶。它不但有去腐生肌的奇效，据说还有延年益寿的妙用。武林
第一美人每天都以此泉水浣面（ｗａｓｈ），来保持她如花似玉的容貌。
LONG
);
	set("exits", ([
		"east" : __DIR__"bathhouse_f3",
	]));
	set("objects", ([
		__DIR__"npc/nude_lady": 2,
	]));
	set("women",1);
	setup();
	create_door("east", "檀木门", "west", DOOR_CLOSED);

}

void init()
{
	add_action("do_wash","wash");
}
int valid_leave(object me, string dir)
{
	if(dir == "east" && me->query_temp("wash"))
		return notify_fail("你还没泡完呢就想走？\n");
	return 1;
}
