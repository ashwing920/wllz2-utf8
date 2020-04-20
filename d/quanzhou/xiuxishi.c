// Room: xiuxishi.c 武馆休息室

inherit ROOM;

void create()
{
	set("short", "武馆休息室");
	set("long", @LONG
这是扬威武馆的休息室。收拾得非常干净，摆设简单。靠墙设有几张
木床，近门处放着一张桌子。
LONG
);
	set("sleep_room", 1);
	set("exits", ([
		"east" : __DIR__"zoulang2",
	]));
	setup();
	replace_program(ROOM);
}
