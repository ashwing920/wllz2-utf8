// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "二天门");
	set("long", @LONG
这里又叫「中天门」。一般的登山者来到这里都已累极，但是这里才
是泰山的一半啊！面对前面险峻的十八盘，很多人都不禁犹豫起来。
LONG
);
	set("exits", ([
		"northup" : __DIR__"wudafu",
		"southdown" : __DIR__"huima",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/tiansong" : 1,
		__DIR__"npc/tianbai" : 1,
	]));
	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

