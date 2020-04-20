// tyroad5.c 崎岖山路
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "崎岖山路");
	set("long", @LONG
你走在一条崎岖狭窄的山路上，一边是峭壁，一边是悬崖，高高的天
柱峰(feng)在云雾中隐约可见。身旁的进香客和游人都仔细地盯着自己的
脚下，不敢抬头望一眼，惟恐一不小心摔下去。更有强人趁机打劫，行人
无不噤声闭气，只求快点赶路。
LONG
);
	set("outdoors", "wudang");
	set("exits", ([
		"northup" : __DIR__"tyroad4",
		"eastdown" : __DIR__"tyroad6",
	]));
	setup();
	replace_program(ROOM);
}
