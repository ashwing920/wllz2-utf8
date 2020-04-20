// Room: /d/taishan/.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "日观峰");
	set("long", @LONG
这里是位于南天门西面的山岭，怪石攒簇，最高的地方一石卓立，名
为君子峰。往北走便是泰山的西天门。
LONG
);
	set("exits", ([
		"westup" : __DIR__"yuhuang",
		"eastup" : __DIR__"tanhai",
	]));
	set("objects", ([
		__DIR__"npc/tianmen" : 1,
	]));
	setup();
	"/clone/board/taishan_b"->foo();
}

