// Room: xiuxishi.c 休息室
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这是血刀门的休息处，光线很昏暗。房里别无他物，只有中间放着一
张收拾得舒舒服服的大床，看着就让人想睡觉。
LONG
);
	set("exits", ([
		"southeast" : __DIR__"lwchang",
	]));
	set("sleep_room", 1);
	setup();
}


