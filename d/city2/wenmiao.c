//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "文庙");
	set("long", @LONG
这里是文庙正殿，内有孔夫子像。历代皇帝都懂得利用儒教思想来巩
固自己的江山社稷，当朝皇帝自然也不例外。不论何人到此，都毕恭毕敬
地上香礼拜。
LONG
);
	set("no_sleep_room",1);
	set("objects", ([
		"/clone/misc/box" : 1,
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"xisi",
	]));

	setup();
	replace_program(ROOM);
}

