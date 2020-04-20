// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "试心石");
	set("long", @LONG
这里便是莲花峰的峰顶，由两块巨石勾连在一起，据说若果你心存诚
意，登上试心石时石快便不会动摇，反之则摇动不止。
LONG
);
	set("exits", ([
		"southdown" : __DIR__"lianhua",
	]));
	set("objects", ([
		__DIR__"npc/yujizi" : 1,
		__DIR__"npc/yuyinzi" : 1,
		__DIR__"npc/yuqingzi" : 1,
	]));

	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}

