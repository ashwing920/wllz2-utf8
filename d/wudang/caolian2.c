// Room: caolian2 北间操练房
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	  set("short", "北间操练房");
	  set("long", @LONG
这里摆满了大刀长剑、沙袋绑腿等，是武当弟子日常练功的地方。
LONG
);

	  set("exits", ([ /* sizeof() == 1 */
		"south"   : __DIR__"caolianfang",
	  ]));

	  set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	  ]));

	  setup();

}

